#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* sortedSquares(int* A, int ASize, int* returnSize)
{
	/*结果数组*/
	int* res = (int *)malloc(sizeof(int)*ASize);
	/*头指针*/
	int start = 0;
	/*尾指针*/
	int end = ASize - 1;
	/*结果数组指针*/
	int index = ASize - 1;
	/*开始遍历*/
	while (start <= end)
	{
		/*谁大把谁放到结果数组的后面，指针相应变化，注意这里不能把小的放到结果数组的前面，因为有负数的可能，平方之后反而变大了，利用数组已经排序的特点，挑出大的保证可以从后向前添加*/
		if (A[start] * A[start] > A[end] * A[end])
		{
			res[index] = A[start] * A[start];
			index--;
			start++;
		}
		else
		{
			res[index] = A[end] * A[end];
			index--;
			end--;
		}
	}
	/*返回大小*/
	*returnSize = ASize;
	/*返回结果*/
	return res;
}

/*主函数省略*/
