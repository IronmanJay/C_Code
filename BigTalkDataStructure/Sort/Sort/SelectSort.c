#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000 /*用于要排序数组个数最大值，可根据需要修改*/
typedef struct
{
	int r[MAXSIZE + 1]; /*用于存储要排序数组，r[0]用作哨兵或临时变量*/
	int length; /*用于记录顺序表的长度*/
}SqList;

/*交换L中数组r的下标为i和j的值*/
void SelectSortswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*打印*/
void SelectSortprint(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		printf("%d,", L.r[i]);
	}
	printf("%d", L.r[i]);
	printf("\n");
}

/*对顺序表L作简单选择排序*/
void SelectSort(SqList *L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i; /*将当前下标定义为最小值下标*/
		for (j = i + 1; j <= L->length; j++) /*循环之后的数据*/
		{
			if (L->r[min] > L->r[j]) /*如果有小于当前最小值的关键字*/
			{
				min = j; /*将此关键字的下标赋值给min*/
			}
		}
		if (i != min) /*若min不等于i，说明找到最小值，交换*/
		{
			SelectSortswap(L, i, min); /*交换L->r[i]与L->r[min]的值*/
		}
	}
}

/*简单选择排序*/
#define N 9
int mainSelectSort(void)
{

	int i;
	int d[N] = { 50,10,90,30,70,40,80,60,20 };
	SqList l0,l1;
	for (i = 0; i < N; i++)
	{
		l0.r[i + 1] = d[i];
	}
	l0.length = N;
	l1 = l0;

	printf("排序前:\n");
	SelectSortprint(l0);

	printf("选择排序:\n");
	SelectSort(&l1);
	SelectSortprint(l1);

	printf("========================================================================================================================");

	/*大数据排序*/
	srand(time(0));
	int Max = 10000;
	int num[10000];
	int p;
	SqList l;
	for (p = 0; p < Max; p++)
	{
		num[p] = rand() % Max + 1;
	}
	for (p = 0; p < Max; p++)
	{
		l.r[p + 1] = num[p];
	}
	l.length = Max;
	SelectSort(&l);
	SelectSortprint(l);

	getchar();

}
