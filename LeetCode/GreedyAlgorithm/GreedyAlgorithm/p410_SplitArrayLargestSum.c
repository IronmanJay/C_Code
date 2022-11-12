#include<stdio.h>

int getSplits(int* nums, int numsSize, int max)
{
	int splits = 1;
	int curSum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (curSum + nums[i] > max)
		{
			splits++;
			curSum = 0;
		}
		curSum += nums[i];
	}
	return splits;
}

int splitArray(int* nums, int numsSize, int k)
{
	int left = 0;
	int right = 0;
	for (int i = 0; i < numsSize; i++)
	{
		right += nums[i];
		if (left < nums[i])
		{
			left = nums[i];
		}
	}
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		int splits = getSplits(nums, numsSize, mid);
		if (splits > k)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/