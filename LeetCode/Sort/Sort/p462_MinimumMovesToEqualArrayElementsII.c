#include<stdio.h>

int compare_p462_MinimumMovesToEqualArrayElementsII(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int minMoves2(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), compare_p462_MinimumMovesToEqualArrayElementsII);
	int mid = nums[numsSize / 2];
	int res = 0;
	for (int i = 0; i < numsSize; i++)
	{
		res += fabs(nums[i] - mid);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/