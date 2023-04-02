#include<stdio.h>

int compare(int* a, int *b)
{
	return *(int *)a - *(int *)b;
}

int minimumDifference(int* nums, int numsSize, int k)
{
	qsort(nums, numsSize, sizeof(int), compare);
	int res = nums[k - 1] - nums[0];
	for (int i = k; i < numsSize; i++)
	{
		res = fmin(res, nums[i] - nums[i - k + 1]);
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/