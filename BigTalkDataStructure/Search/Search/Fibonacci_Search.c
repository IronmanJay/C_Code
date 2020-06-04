#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*存储空间初始分配量*/

typedef int Status; /*Status是函数的类型,其值是函数结果状态代码，如OK等*/

int F[100]; /*斐波那契数列*/

int Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k = 0;
	low = 1; /*定义最低下标为记录首位*/
	high = 1; /*定义最高下标为记录末位*/
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
				return mid; /*若相等则说明mid即为查找到的位置*/
			}
			else
			{
				return n;
			}
		}
	}
	return 0;
}

/*斐波那契查找*/
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
