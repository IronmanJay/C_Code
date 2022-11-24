#include<stdio.h>
#include<stdlib.h>

void dfs_back(int* nums, int numsSize, int** res, int* returnSize, int** returnColumnSizes, int start, int* path, int pathSize)
{
	res[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
	memcpy(res[*returnSize], path, sizeof(int) * pathSize);
	(*returnColumnSizes)[*returnSize] = pathSize;
	(*returnSize)++;
	for (int i = start; i < numsSize; i++)
	{
		path[pathSize++] = nums[i];
		dfs_back(nums, numsSize, res, returnSize, returnColumnSizes, i + 1, path, pathSize);
		pathSize--;
	}
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	*returnSize = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * 10001);
	int** res = (int**)malloc(sizeof(int*) * 10001);
	int* path = (int*)malloc(sizeof(int) * numsSize);
	dfs_back(nums, numsSize, res, returnSize, returnColumnSizes, 0, path, 0);
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/