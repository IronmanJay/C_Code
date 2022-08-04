#include<stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	if (numsSize == 0)
	{
		res[0] = -1;
		res[1] = -1;
		return res;
	}
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] >= target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (left >= numsSize || nums[left] != target)
	{
		res[0] = -1;
		res[1] = -1;
		return res;
	}
	res[0] = left;
	left = 0;
	right = numsSize - 1;
	while (left <= right)
	{
		int mid = (left + right + 1) / 2;
		if (nums[mid] <= target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	res[1] = right;
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/