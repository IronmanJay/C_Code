#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*交换数组中两个元素*/
void swap_o40_TheSmallestNumberOfK(int* arr, int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

/*快速排序*/
int partition_o40_TheSmallestNumberOfK(int* arr, int left, int right)
{
	/*选取最左边元素为中枢值，随机化最好*/
	int pivot = arr[left];
	/*大于等于中枢值值的索引*/
	int leftEnd = left;
	/*将比中枢值小的元素都放到中枢值的左边*/
	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] < pivot)
		{
			leftEnd++;
			swap_o40_TheSmallestNumberOfK(arr, i, leftEnd);
		}
	}
	/*将中枢值交换到中间位置*/
	swap_o40_TheSmallestNumberOfK(arr, left, leftEnd);
	/*返回中枢值索引*/
	return leftEnd;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	/*获取数组长度*/
	int len = arrSize;
	/*结果数组*/
	int* res = (int*)malloc(sizeof(int)*arrSize);
	/*判断边界值返回*/
	if (k == 0 || k > len)
	{
		*returnSize = 0;
		return res;
	}
	/*在数组中k就是索引，所以-1*/
	int target = k - 1;
	int left = 0;
	int right = len - 1;
	while (true)
	{
		/*返回中枢值索引*/
		int pIndex = partition_o40_TheSmallestNumberOfK(arr, left, right);
		/*恰好中枢值索引等于目标索引，说明前k个数已经按从小到大排序，直接返回即可*/
		if (pIndex == target)
		{
			for (int i = 0; i < k; i++)
			{
				res[i] = arr[i];
			}
			*returnSize = k;
			return res;
		}
		/*如果中枢值索引小于目标索引，需要向右继续排序*/
		else if (pIndex < target)
		{
			left = pIndex + 1;
		}
		/*如果中枢值索引大于目标索引，需要向左继续排序*/
		else
		{
			right = pIndex - 1;
		}
	}
}

/*主函数省略*/
