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
#define MAXSIZE 10000 /*����Ҫ��������������ֵ���ɸ�����Ҫ�޸�*/

typedef int Status;

typedef struct
{
	int r[MAXSIZE + 1]; /*���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ����*/
	int length; /*���ڼ�¼˳���ĳ���*/
}SqList;

/*����L������r���±�Ϊi��j��ֵ*/
void Insertswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*��ӡ*/
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

/*��˳���L��ֱ�Ӳ�������*/
void InsertSort(SqList *L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i] < L->r[i - 1]) /*�轫L->r[i]���������ӱ�*/
		{
			L->r[0] = L->r[i]; /*�����ڱ�*/
			for (j = i - 1; L->r[j] > L->r[0]; j--)
			{
				L->r[j + 1] = L->r[j]; /*��¼����*/
			}
			L->r[j + 1] = L->r[0]; /*���뵽��ȷλ��*/
		}
	}
}


/*ֱ�Ӳ�������*/
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

	printf("����ǰ:\n");
	Insertprint(l0);

	printf("ֱ�Ӳ�������:\n");
	InsertSort(&l1);
	Insertprint(l1);

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
	InsertSort(&l);
	Insertprint(l);

	getchar();

}
