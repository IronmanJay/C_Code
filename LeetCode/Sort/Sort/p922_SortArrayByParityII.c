#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
	/*定义结果数组*/
	int *res = (int*)malloc(ASize * sizeof(int));
	/*定义偶数下标和奇数下标*/
	int oddIndex = 0;
	int evenIndex = 1;
	/*遍历A数组每一个元素，如果是偶数，那么就放到res数组的偶数位置，oddIndex相应+2，如果是奇数，就放到res数组奇数位置，eventIndex相应+2*/
	for (int i = 0; i < ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			res[oddIndex] = A[i];
			oddIndex += 2;
		}
		else
		{
			res[evenIndex] = A[i];
			evenIndex += 2;
		}
	}
	/*返回结果*/
	*returnSize = ASize;
	return res;
}

/*主函数省略*/
int main(void)
{

}