#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))

int massage(int* nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}
	if (numsSize == 1)
	{
		return nums[0];
	}
	int* dp = (int*)malloc(sizeof(int) * numsSize);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < numsSize; i++)
	{
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[numsSize - 1];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/