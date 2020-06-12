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
void Mergeswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*��ӡ*/
void Mergeprint(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		printf("%d,", L.r[i]);
	}
	printf("%d", L.r[i]);
	printf("\n");
}

/*�������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n]*/
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++) /*��SR�м�¼��С����ز���TR*/
	{
		if (SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++) /*��ʣ���SR[i..m]���Ƶ�TR*/
		{
			TR[k +l] = SR[i + l];
		}
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
		{
			TR[k + l] = SR[j + l]; /*��ʣ���SR[j..n]���Ƶ�TR*/
		}
	}
}

/*��SR[s..t]�鲢����ΪTR1[s..t]*/
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		m = (s + t) / 2; /*��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]*/
		MSort(SR, TR2, s, m); /*�ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m]*/
		MSort(SR, TR2, m + 1, t); /*�ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t]*/
		Merge(TR2, TR1, s, m, t); /*��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t]*/
	}
}

/*��˳���L���鲢���򣨵ݹ鷨��*/
void MergeSort1(SqList *L)
{
	MSort(L->r, L->r, 1, L->length);
}

/*��SR[]�����ڳ���Ϊs�������������鲢��TR[]*/
void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1;
	int j;
	while (i <= n - 2 * s + 1)
	{
		/*�����ϲ�*/
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	if (i < n - s + 1) /*�鲢�����������*/
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else /*�����ֻʣ�µ���������*/
	{
		for (j = i; j <= n; j++)
		{
			TR[j] = SR[j];
		}
	}
}

/*��˳���L���鲢���򣨷ǵݹ鷨��*/
void MergeSort2(SqList *L)
{
	int* TR = (int *)malloc(L->length * sizeof(int)); /*�������ռ�*/
	int k = 1;
	while (k < L->length)
	{
		MergePass(L->r, TR, k, L->length);
		k = 2 * k; /*�����г��ȼӱ�*/
		MergePass(TR, L->r, k, L->length);
		k = 2 * k; /*�����г��ȼӱ�*/
	}
}

/*�鲢����*/
#define N 9
int mainMergeSort(void)
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
	Mergeprint(l0);

	printf("�鲢���򣨵ݹ鷨��:\n");
	MergeSort1(&l1);
	Mergeprint(l1);

	printf("�鲢���򣨷ǵݹ鷨��:\n");
	MergeSort2(&l2);
	Mergeprint(l2);

	printf("========================================================================================================================");

	/*����������*/
	srand(time(0));
	int Max = 10000;
	int num[10000];
	int p;
	SqList l3,l4;
	for (p = 0; p < Max; p++)
	{
		num[p] = rand() % Max + 1;
	}
	for (p = 0; p < Max; p++)
	{
		l3.r[p + 1] = num[p];
	}
	l3.length = Max;
	l4 = l3;

	MergeSort1(&l3);
	Mergeprint(l3);

	printf("========================================================================================================================");

	MergeSort2(&l4);
	Mergeprint(l4);

	getchar();

}
