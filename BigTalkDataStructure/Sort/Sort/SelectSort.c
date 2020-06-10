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
#define MAXSIZE 10000 /*����Ҫ��������������ֵ���ɸ�����Ҫ�޸�*/
typedef struct
{
	int r[MAXSIZE + 1]; /*���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ����*/
	int length; /*���ڼ�¼˳���ĳ���*/
}SqList;

/*����L������r���±�Ϊi��j��ֵ*/
void SelectSortswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*��ӡ*/
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

/*��˳���L����ѡ������*/
void SelectSort(SqList *L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i; /*����ǰ�±궨��Ϊ��Сֵ�±�*/
		for (j = i + 1; j <= L->length; j++) /*ѭ��֮�������*/
		{
			if (L->r[min] > L->r[j]) /*�����С�ڵ�ǰ��Сֵ�Ĺؼ���*/
			{
				min = j; /*���˹ؼ��ֵ��±긳ֵ��min*/
			}
		}
		if (i != min) /*��min������i��˵���ҵ���Сֵ������*/
		{
			SelectSortswap(L, i, min); /*����L->r[i]��L->r[min]��ֵ*/
		}
	}
}

/*��ѡ������*/
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

	printf("����ǰ:\n");
	SelectSortprint(l0);

	printf("ѡ������:\n");
	SelectSort(&l1);
	SelectSortprint(l1);

	printf("========================================================================================================================");

	/*����������*/
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
