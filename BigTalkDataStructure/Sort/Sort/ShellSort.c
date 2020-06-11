#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
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
void Shellswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Shellprint(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		printf("%d,", L.r[i]);
	}
	printf("%d", L.r[i]);
	printf("\n");
}

void ShellSort(SqList *L)
{
	int i, j, k = 0;
	int increment = L->length;
	do 
	{
		increment = increment / 3 + 1; /*��������*/
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment]) /*�轫L->r[i]�������������ӱ�*/
			{
				L->r[0] = L->r[i]; /*�ݴ���L->[0]*/
				for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
				{
					L->r[j + increment] = L->r[j]; /*��¼���ƣ����Ҳ���λ��*/
				}
				L->r[j + increment] = L->r[0]; /*����*/
			}
		}
		printf("	��%d��������: ", ++k);
		Shellprint(*L);
	} while (increment > 1);
}

/*ϣ������*/
#define N 9
int mainShellSort(void)
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
	Shellprint(l0);

	printf("ϣ������:\n");
	ShellSort(&l0);
	Shellprint(l0);

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
	ShellSort(&l);
	Shellprint(l);

	getchar();

}
