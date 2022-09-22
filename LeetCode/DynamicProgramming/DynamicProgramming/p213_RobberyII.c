#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int getRes(int* nums, int numsSize, int begin, int end)
{
	int* dp = (int*)malloc(sizeof(int) * numsSize);
	dp[begin] = nums[begin];
	dp[begin + 1] = max(nums[begin], nums[begin + 1]);
	for (int i = begin + 2; i <= end; i++)
	{
		dp[i] = max((dp[i - 2] + nums[i]), dp[i - 1]);
	}
	return dp[end];
}

int rob_p213_RobberyII(int* nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}
	if (numsSize == 1)
	{
		return nums[0];
	}
	if (numsSize == 2)
	{
		return max(nums[0], nums[1]);
	}
	return max(getRes(nums, numsSize, 0, numsSize - 2), getRes(nums, numsSize, 1, numsSize - 1));
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/