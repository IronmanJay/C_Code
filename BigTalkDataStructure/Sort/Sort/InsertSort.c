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

typedef int Status;

typedef struct
{
	int r[MAXSIZE + 1]; /*用于存储要排序数组，r[0]用作哨兵或临时变量*/
	int length; /*用于记录顺序表的长度*/
}SqList;

/*交换L中数组r的下标为i和j的值*/
void Insertswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*打印*/
void Insertprint(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		printf("%d,", L.r[i]);
	}
	printf("%d", L.r[i]);
	printf("\n");
}

/*对顺序表L作直接插入排序*/
void InsertSort(SqList *L)
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


/*直接插入排序*/
#define N 9
int main(void)
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
	Insertprint(l0);

	printf("直接插入排序:\n");
	InsertSort(&l1);
	Insertprint(l1);

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
	InsertSort(&l);
	Insertprint(l);

	getchar();

}
