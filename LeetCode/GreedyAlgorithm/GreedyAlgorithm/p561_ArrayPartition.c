#include<stdio.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int arrayPairSum(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), compare);
	int res = 0;
	for (int i = 0; i < numsSize; i += 2)
	{
		res += nums[i];
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/