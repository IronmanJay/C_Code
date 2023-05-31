#include<stdio.h>

int longestSubarray(int* nums, int numsSize)
{
	int len = numsSize;
	int left = 0;
	int right = 0;
	int zero_count = 0;
	int res = 0;
	while (right < len)
	{
		if (nums[right] == 0)
		{
			zero_count++;
		}
		while (zero_count > 1)
		{
			if (nums[left] == 0)
			{
				zero_count--;
			}
			left++;
		}
		res = fmax(res, right - left + 1);
		right++;
	}
	return res - 1;
}