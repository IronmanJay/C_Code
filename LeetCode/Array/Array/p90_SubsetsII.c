#include<stdio.h>
#include<stdlib.h>

int compare_p90_SubsetsII(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void dfs_back_p90_SubsetsII(int* nums, int numsSize, int** res, int* returnSize, int** returnColumnSizes, int* path, int pathSize, int start)
{
	res[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
	memcpy(res[*returnSize], path, sizeof(int) * pathSize);
	(*returnColumnSizes)[*returnSize] = pathSize;
	(*returnSize)++;
	for (int i = start; i < numsSize; i++)
	{
		if (i > start && nums[i] == nums[i - 1])
		{
			continue;
		}
		path[pathSize++] = nums[i];
		dfs_back_p90_SubsetsII(nums, numsSize, res, returnSize, returnColumnSizes, path, pathSize, i + 1);
		pathSize--;
	}
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	qsort(nums, numsSize, sizeof(int), compare_p90_SubsetsII);
	*returnSize = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * 10001);
	int** res = (int**)malloc(sizeof(int*) * 10001);
	int* path = (int*)malloc(sizeof(int) * numsSize);
	dfs_back_p90_SubsetsII(nums, numsSize, res, returnSize, returnColumnSizes, path, 0, 0);
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/