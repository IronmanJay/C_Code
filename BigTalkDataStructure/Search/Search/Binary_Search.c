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

int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1; /*定义最低下标为记录首位*/
	high = n; /*定义最高下标为记录末尾*/
	while (low <= high)
	{
		mid = (low + high) / 2; /*折半*/
		if (key < a[mid]) /*若查找值比中值小*/
		{
			high = mid - 1; /*最高下标调整到中位下标小一位*/
		}
		else if (key > a[mid]) /*若查找值比中值大*/
		{
			low = mid + 1; /*最低下标调整到中位下标大一位*/
		}
		else
		{
			return mid; /*若相等则说明mid即为要查找到的位置*/
		}
	}
	return 0;
}

/*折半查找*/
int mainBinary_Search(void)
{
	int i, result;
	int arr[MAXSIZE] = { 0,1,16,24,35,47,59,62,73,88,99 };

	result = Binary_Search(arr, 10, 62);
	printf("Binary_Search:%d \n",result);

	getchar();

}