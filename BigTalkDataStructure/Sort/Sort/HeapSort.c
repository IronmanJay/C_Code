#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <io.h>  
#include <math.h>  
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000  /*用于要排序数组个数最大值，可根据需要修改*/

typedef int Status;

typedef struct
{
	int r[MAXSIZE + 1];	/*用于存储要排序数组，r[0]用作哨兵或临时变量*/
	int length;			/*用于记录顺序表的长度*/
}SqList;

/*交换L中数组r的下标为i和j的值*/
void HeapSortswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*打印*/
void HeapSprtprint(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
		printf("%d,", L.r[i]);
	printf("%d", L.r[i]);
	printf("\n");
}

/*已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义*/
/*本函数调整L->r[s]的关键字,使L->r[s..m]成为一个大顶堆*/
void HeapAdjust(SqList *L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2) /*沿关键字较大的孩子结点向下筛选*/
	{
		if (j < m && L->r[j] < L->r[j + 1])
		{
			++j; /*j为关键字中较大的记录下标*/
		}
		if (temp >= L->r[j])
		{
			break; /*rc应插入在位置s上*/
		}
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp; /*插入*/
}

/*对顺序表L进行堆排序*/
void HeapSort(SqList *L)
{
	int i;
	for (i = L->length / 2; i > 0; i--) /*把L中的r构建成一个大顶堆*/
	{
		HeapAdjust(L, i, L->length);
	}
	for (i = L->length; i > 1; i--)
	{
		HeapSortswap(L, 1, i); /*将堆顶记录和当前未经排序子序列的最后一个记录交换*/
		HeapAdjust(L, 1, i - 1); /*将L->r[1..i-1]重新调整为大根堆*/
	}
}

/*堆排序*/
#define N 9
int mainHeapSort(void)
{

	int i;
	int d[N] = { 50,10,90,30,70,40,80,60,20 };
	SqList l0, l1;
	for (i = 0; i < N; i++)
	{
		l0.r[i + 1] = d[i];
	}
	l0.length = N;
	l1 = l0;

	printf("排序前:\n");
	HeapSprtprint(l0);

	printf("堆排序:\n");
	HeapSort(&l1);
	HeapSprtprint(l1);

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
	HeapSort(&l);
	HeapSprtprint(l);

	getchar();

}
