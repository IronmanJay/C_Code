#include<stdio.h>
#include<stdlib.h>

int jump(int* nums, int numsSize)
{
	int* dp = (int*)calloc(numsSize, sizeof(int));
	int bestIndex = 0;
	for (int i = 1; i < numsSize; i++)
	{
		while (i > bestIndex + nums[bestIndex])
		{
			bestIndex++;
		}
		dp[i] = dp[bestIndex] + 1;
	}
	return dp[numsSize - 1];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/