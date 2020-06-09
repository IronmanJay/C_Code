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
void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*��ӡ*/
void print(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		printf("%d,", L.r[i]);
	}
	printf("%d", L.r[i]);
	printf("\n");
}

/*��˳���L����������ð����������棩*/
void BubbleSort0(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[i] > L->r[j])
			{
				swap(L, i, j); /*����L->r[i]��L->r[j]��ֵ*/
			}
		}
	}
}

/*��˳���L��ð������*/
void BubbleSort1(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--) /*ע��j�ǴӺ���ǰѭ��*/
		{
			if (L->r[j] > L->r[j + 1]) /*��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				swap(L, j, j + 1); /*����L->r[j]��L->r[j+1]��ֵ*/
			}
		}
	}
}

/*��˳���L���Ľ�ð���㷨*/
void BubbleSort2(SqList *L)
{
	int i, j;
	Status flag = TRUE; /*flag������Ϊ���*/
	for (i = 1; i < L->length - 1 && flag; i++) /*��flagΪtrue˵���й����ݽ���������ֹͣѭ��*/
	{
		flag = FALSE;
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1); /*����L->r[j]��L->r[j+1]��ֵ*/
				flag = TRUE; /*��������ݽ�������flagΪtrue*/
			}
		}
	}
}

/*ð������*/
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

	printf("����ǰ:\n");
	print(l0);

	printf("����ð������:\n");
	BubbleSort0(&l0);
	print(l0);

	printf("ð������:\n");
	BubbleSort1(&l1);
	print(l1);

	printf("�Ľ�ð������:\n");
	BubbleSort2(&l2);
	print(l2);

	printf("========================================================================================================================");

	/*�������������*/
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
	BubbleSort2(&l);
	print(l);

	getchar();

}
