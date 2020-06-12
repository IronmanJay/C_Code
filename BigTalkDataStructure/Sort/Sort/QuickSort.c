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
#define MAX_LENGTH_INSERT_SORT 7 /*���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ*/

typedef int Status;

typedef struct
{
	int r[MAXSIZE + 1]; /*���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ����*/
	int length; /*���ڼ�¼˳���ĳ���*/
}SqList;

/*����L������r���±�Ϊi��j��ֵ*/
void Quicktswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*��ӡ*/
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

/*����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ��*/
/*��ʱ����֮ǰ(��)�ļ�¼������(С)����*/
int Partition1(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low]; /*���ӱ�ĵ�һ����¼��Ϊ�����¼*/
	while (low < high) /*�ӱ�����˽�������м�ɨ��*/
	{
		while (low < high && L->r[high] >= pivotkey)
		{
			high--;
		}
		Quicktswap(L, low, high); /*���������¼С�ļ�¼�������Ͷ�*/
		while (low < high && L->r[low] <= pivotkey)
		{
			low++;
		}
		Quicktswap(L, low, high); /*���������¼��ļ�¼�������߶�*/
	}
	return low; /*������������λ��*/
}

/*��˳���L�е�������L->r[low..high]����������*/
void QSort1(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition1(L, low, high); /*��L->r[low..high]һ��Ϊ�����������ֵpivot*/
		QSort1(L, low, pivot - 1); /*�Ե��ӱ�ݹ�����*/
		QSort1(L, pivot + 1, high); /*�Ը��ӱ�ݹ�����*/
	}
}

/*��˳���L����������*/
void QuickSort1(SqList *L)
{
	QSort1(L, 1, L->length);
}

/*���������Ż��㷨*/
int Partition2(SqList *L, int low, int high)
{
	int pivotkey;
	int m = low + (high + low) / 2; /*���������м��Ԫ�ص��±�*/
	if (L->r[low] > L->r[high])
	{
		Quicktswap(L, low, high); /*����������Ҷ����ݣ���֤��˽�С*/
	}
	if (L->r[m] > L->r[high])
	{
		Quicktswap(L, high, m); /*�����м����Ҷ����ݣ���֤�м��С*/
	}
	if (L->r[m] > L->r[low])
	{
		Quicktswap(L, m, low); /*�����м���������ݣ���֤��˽�С*/
	}
	pivotkey = L->r[low]; /*���ӱ�ĵ�һ����¼��Ϊ�����¼*/
	L->r[0] = pivotkey; /*������ؼ��ֱ��ݵ�L->r[0]*/
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
	return low; /*������������λ��*/
}

/*��˳���L��ֱ�Ӳ�������*/
void QuickInsertSort(SqList *L)
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

/*������ֵ�ж��Ż�*/
void QSort2(SqList *L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		while (low < high)
		{
			pivot = Partition2(L, low, high); /*��L->r[low..high]һ��Ϊ�����������ֵpivot*/
			QSort2(L, low, pivot - 1); /*�Ե��ӱ�ݹ�����*/
			low = pivot + 1; /*β�ݹ�*/
		}
	}
	else
	{
		QuickInsertSort(L);
	}
}

/*��˳���K�����������Ż���*/
void QuickSort2(SqList *L)
{
	QSort2(L, 1, L->length);
}

/*��������*/
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
	Quickprint(l0);

	printf("��������:\n");
	QuickSort1(&l1);
	Quickprint(l1);

	printf("�Ľ���������:\n");
	QuickSort2(&l2);
	Quickprint(l2);

	printf("========================================================================================================================");

	/*����������*/
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