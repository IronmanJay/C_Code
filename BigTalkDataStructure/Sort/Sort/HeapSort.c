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
#define MAXSIZE 10000  /*����Ҫ��������������ֵ���ɸ�����Ҫ�޸�*/

typedef int Status;

typedef struct
{
	int r[MAXSIZE + 1];	/*���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ����*/
	int length;			/*���ڼ�¼˳���ĳ���*/
}SqList;

/*����L������r���±�Ϊi��j��ֵ*/
void HeapSortswap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*��ӡ*/
void HeapSprtprint(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
		printf("%d,", L.r[i]);
	printf("%d", L.r[i]);
	printf("\n");
}

/*��֪L->r[s..m]�м�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ���*/
/*����������L->r[s]�Ĺؼ���,ʹL->r[s..m]��Ϊһ���󶥶�*/
void HeapAdjust(SqList *L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2) /*�عؼ��ֽϴ�ĺ��ӽ������ɸѡ*/
	{
		if (j < m && L->r[j] < L->r[j + 1])
		{
			++j; /*jΪ�ؼ����нϴ�ļ�¼�±�*/
		}
		if (temp >= L->r[j])
		{
			break; /*rcӦ������λ��s��*/
		}
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp; /*����*/
}

/*��˳���L���ж�����*/
void HeapSort(SqList *L)
{
	int i;
	for (i = L->length / 2; i > 0; i--) /*��L�е�r������һ���󶥶�*/
	{
		HeapAdjust(L, i, L->length);
	}
	for (i = L->length; i > 1; i--)
	{
		HeapSortswap(L, 1, i); /*���Ѷ���¼�͵�ǰδ�����������е����һ����¼����*/
		HeapAdjust(L, 1, i - 1); /*��L->r[1..i-1]���µ���Ϊ�����*/
	}
}

/*������*/
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

	printf("����ǰ:\n");
	HeapSprtprint(l0);

	printf("������:\n");
	HeapSort(&l1);
	HeapSprtprint(l1);

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
	HeapSort(&l);
	HeapSprtprint(l);

	getchar();

}
