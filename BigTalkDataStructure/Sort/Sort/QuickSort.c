#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000 /*用于要排序数组个数最大值，可根据需要修改*/
#define MAX_LENGTH_INSERT_SORT 7 /*用于快速排序时判断是否选用插入排序阙值*/

typedef int Status;

typedef struct
{
	int r[MAXSIZE + 1]; /*用于存储要排序数组，r[0]用作哨兵或临时变量*/
	int length; /*用于记录顺序表的长度*/
}SqList;

/*交换L中数组r的下标为i和j的值*/
void Quicktswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*打印*/
void Quickprint(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		printf("%d,", L.r[i]);
	}
	printf("%d", L.r[i]);
	printf("\n");
}

/*交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置*/
/*此时在它之前(后)的记录均不大(小)于它*/
int Partition1(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low]; /*用子表的第一个记录作为枢轴记录*/
	while (low < high) /*从表的两端交替地向中间扫描*/
	{
		while (low < high && L->r[high] >= pivotkey)
		{
			high--;
		}
		Quicktswap(L, low, high); /*将比枢轴记录小的记录交换到低端*/
		while (low < high && L->r[low] <= pivotkey)
		{
			low++;
		}
		Quicktswap(L, low, high); /*将比枢轴记录大的记录交换到高端*/
	}
	return low; /*返回枢轴所在位置*/
}

/*对顺序表L中的子序列L->r[low..high]作快速排序*/
void QSort1(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition1(L, low, high); /*将L->r[low..high]一分为二，算出枢轴值pivot*/
		QSort1(L, low, pivot - 1); /*对低子表递归排序*/
		QSort1(L, pivot + 1, high); /*对高子表递归排序*/
	}
}

/*对顺序表L作快速排序*/
void QuickSort1(SqList *L)
{
	QSort1(L, 1, L->length);
}

/*快速排序优化算法*/
int Partition2(SqList *L, int low, int high)
{
	int pivotkey;
	int m = low + (high + low) / 2; /*计算数组中间的元素的下标*/
	if (L->r[low] > L->r[high])
	{
		Quicktswap(L, low, high); /*交换左端与右端数据，保证左端较小*/
	}
	if (L->r[m] > L->r[high])
	{
		Quicktswap(L, high, m); /*交换中间与右端数据，保证中间较小*/
	}
	if (L->r[m] > L->r[low])
	{
		Quicktswap(L, m, low); /*交换中间与左端数据，保证左端较小*/
	}
	pivotkey = L->r[low]; /*用子表的第一个记录作为枢轴记录*/
	L->r[0] = pivotkey; /*将枢轴关键字备份到L->r[0]*/
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
		{
			high--;
		}
		L->r[low] = L->r[high];
		while (low < high && L->r[low] <= pivotkey)
		{
			low++;
		}
		L->r[high] = L->r[low];
	}
	L->r[low] = L->r[0];
	return low; /*返回枢轴所在位置*/
}

/*对顺序表L作直接插入排序*/
void QuickInsertSort(SqList *L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i] < L->r[i - 1]) /*需将L->r[i]插入有序子表*/
		{
			L->r[0] = L->r[i]; /*设置哨兵*/
			for (j = i - 1; L->r[j] > L->r[0]; j--)
			{
				L->r[j + 1] = L->r[j]; /*记录后移*/
			}
			L->r[j + 1] = L->r[0]; /*插入到正确位置*/
		}
	}
}

/*进行阙值判断优化*/
void QSort2(SqList *L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		while (low < high)
		{
			pivot = Partition2(L, low, high); /*将L->r[low..high]一分为二，算出枢轴值pivot*/
			QSort2(L, low, pivot - 1); /*对低子表递归排序*/
			low = pivot + 1; /*尾递归*/
		}
	}
	else
	{
		QuickInsertSort(L);
	}
}

/*对顺序表K作快速排序（优化后）*/
void QuickSort2(SqList *L)
{
	QSort2(L, 1, L->length);
}

/*快速排序*/
#define N 9
int main(void)
{

	int i;
	int d[N] = { 50,10,90,30,70,40,80,60,20 };
	SqList l0, l1, l2;
	for (i = 0; i < N; i++)
	{
		l0.r[i + 1] = d[i];
	}
	l0.length = N;
	l1 = l2 = l0;

	printf("排序前:\n");
	Quickprint(l0);

	printf("快速排序:\n");
	QuickSort1(&l1);
	Quickprint(l1);

	printf("改进快速排序:\n");
	QuickSort2(&l2);
	Quickprint(l2);

	printf("========================================================================================================================");

	/*大数据排序*/
	srand(time(0));
	int Max = 10000;
	int num[10000];
	int pos;
	SqList l3, l4;
	for (pos = 0; pos < Max; pos++)
	{
		num[pos] = rand() % Max + 1;
	}
	for (pos = 0; pos < Max; pos++)
	{
		l3.r[pos + 1] = num[pos];
	}
	l3.length = Max;
	l4 = l3;

	QuickSort1(&l3);
	Quickprint(l3);

	printf("========================================================================================================================");

	QuickSort2(&l4);
	Quickprint(l4);

	getchar();

}