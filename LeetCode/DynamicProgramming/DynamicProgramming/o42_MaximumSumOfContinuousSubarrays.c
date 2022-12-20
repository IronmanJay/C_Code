#include<stdio.h>
#include<stdlib.h>

int maxSubArray(int* nums, int numsSize)
{
	int* dp = (int*)malloc(sizeof(int) * numsSize);
	dp[0] = nums[0];
	int max = dp[0];
	for (int i = 1; i < numsSize; i++)
	{
		dp[i] = fmax(dp[i - 1] + nums[i], nums[i]);
		max = fmax(dp[i], max);
	}
	return max;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/