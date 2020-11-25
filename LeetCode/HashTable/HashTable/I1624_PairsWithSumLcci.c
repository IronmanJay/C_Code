#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*自定义排序，从小到大排序*/
int compare_I1624_PairsWithSumLcci(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
	/*新建结果数组并开辟空间*/
	int** res = (int**)malloc(sizeof(int*)*(numsSize / 2));
	*returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize / 2));
	for (int i = 0; i < numsSize / 2; i++)
	{
		res[i] = (int*)malloc(sizeof(int) * 2);
		(*returnColumnSizes)[i] = 2;
	}
	/*从小到大排序*/
	qsort(nums, numsSize, sizeof(int), compare_I1624_PairsWithSumLcci);
	/*结果数组索引*/
	int index = 0;
	/*待查数组左指针*/
	int left = 0;
	/*待查数组右指针*/
	int right = numsSize - 1;
	/*开始遍历*/
	while (left < right)
	{
		/*如果找到一对加入到结果数组，*/
		if (nums[left] + nums[right] == target)
		{
			res[index][0] = nums[left];
			res[index++][1] = nums[right];
			left++;
			right--;
		}
		/*如果当前这一对和大于目标值，右指针左移*/
		else if (nums[left] + nums[right] > target)
		{
			right--;
		}
		/*如果当前这一对和小于目标值，左指针右移*/
		else
		{
			left++;
		}
	}
	/*返回数组长度*/
	*returnSize = index;
	/*结果数组*/
	return res;
}

/*主函数省略*/
