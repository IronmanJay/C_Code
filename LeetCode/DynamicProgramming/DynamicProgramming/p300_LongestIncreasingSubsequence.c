#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*返回两者之间较大值*/
int p300_LongestIncreasingSubsequence_max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int lengthOfLIS(int* nums, int numsSize)
{
	/*动态数组：存放到每个位置的最大递增子序列的长度*/
	int* dp = (int*)malloc(sizeof(int)*numsSize);
	/*每个位置初始化的最长递增的子序列的长度就是自身，所以长度为1*/
	for (int i = 0; i < numsSize; i++)
	{
		dp[i] = 1;
	}
	/*存放结果，默认长度为1*/
	int res = 1;
	/*从数组的第一个位置开始遍历，相当于找这个位置的前面元素看是否有递增的序列*/
	for (int i = 1; i < numsSize; i++)
	{
		/*找i之前递增的子序列*/
		for (int j = 0; j < i; j++)
		{
			/*如果[0,i]有递增的元素，更新动态数组的值*/
			if (nums[j] < nums[i])
			{
				/*动态转移方程：遇到一个比位置i小的元素那么肯定就是有递增的子序列，更新位置i的最长递增子序列的长度*/
				dp[i] = p300_LongestIncreasingSubsequence_max(dp[j] + 1, dp[i]);
			}
		}
		/*同时更新结果*/
		res = p300_LongestIncreasingSubsequence_max(res, dp[i]);
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
