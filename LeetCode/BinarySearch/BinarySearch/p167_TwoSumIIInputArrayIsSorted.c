#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	/*新建结果数组*/
	int* res = (int *)malloc(sizeof(int) * 2);
	/*遍历每一个值，但是如果遇到符合要求的就退出for循环，所以说不一定遍历到底*/
	for (int i = 0; i < numbersSize; i++)
	{
		/*
			这里low = i + 1是因为我们要从数组第一个元素开始固定，
			从后面的数组查找target和固定值的差值，就变成了二分查找数组的问题了
		*/
		int low = i + 1;
		/*二分查找尾部固定是整个数组长度*/
		int high = numbersSize - 1;
		/*定义中间值索引*/
		while (low <= high)
		{
			/*定义中间值索引*/
			int mid = (high - low) / 2 + low;
			/*
				如果在除去固定值的数组中，查找到了target和固定值的差值，说明固定值+当前这个值就是目标值，
				因为数组有序，说明index1<index2，符合要求，返回下标即可，按照要求，分别+1
			*/
			if (numbers[mid] == target - numbers[i])
			{
				res[0] = i + 1;
				res[1] = mid + 1;
				*returnSize = 2;
				return res;
			}
			/*如果在除去固定值的数组中，发现中间值大于target和固定值的差值，说明我们要找的在中间值左边，向左查找*/
			else if (numbers[mid] > target - numbers[i])
			{
				high = mid - 1;
			}
			/*如果在除去固定值的数组中，发现中间值小于target和固定值的差值，说明我们要找的在中间值右边，向右查找*/
			else
			{
				low = mid + 1;
			}
		}
	}
	/*如果没找到，返回-1数组*/
	*returnSize = 2;
	return res;
}

/*主函数省略*/
