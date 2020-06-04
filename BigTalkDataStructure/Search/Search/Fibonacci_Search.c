#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

int F[100]; /*쳲���������*/

int Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k = 0;
	low = 1; /*��������±�Ϊ��¼��λ*/
	high = 1; /*��������±�Ϊ��¼ĩλ*/
	while(n > F[k] - 1)
	{
		k++;
	}
	for (i = n; i < F[k] - 1; i++)
	{
		a[i] = a[n];
	}
	while (low <= high)
	{
		mid = low + F[k - 1] - 1;
		if (key < a[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
			{
				return mid; /*�������˵��mid��Ϊ���ҵ���λ��*/
			}
			else
			{
				return n;
			}
		}
	}
	return 0;
}

/*쳲���������*/
int mainFibonacci_Search(void)
{

	int i, result;
	int arr[MAXSIZE] = { 0,1,16,24,35,47,59,62,73,88,99 };

	F[0] = 0;
	F[1] = 1;
	for (i = 2; i < 100; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	result = Fibonacci_Search(arr, 10, 62);
	printf("Fibonacci_Search:%d \n", result);
 
	getchar();

}
