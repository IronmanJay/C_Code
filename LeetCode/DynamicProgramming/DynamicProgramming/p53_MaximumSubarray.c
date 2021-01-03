#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*返回两者之间较大值*/
int p53_MaximumSubarray_max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int p53_MaximumSubarray_maxSubArray(int* nums, int numsSize)
{
	/*动态方程数组，存放到达每一个位置的最大值*/
	int* dp = (int*)calloc(numsSize, sizeof(int));
	/*到达第一个位置的最大值肯定就是nums中第一个元素*/
	dp[0] = nums[0];
	/*遍历整个数组*/
	for (int i = 1; i < numsSize; i++)
	{
		/*动态转移方程：注意这只是把到当前位置的最大值找出来，并不是真的找出了一个连续子数组*/
		dp[i] = p53_MaximumSubarray_max(nums[i], nums[i] + dp[i - 1]);
	}
	/*最后找出整个数组最大值就是结果*/
	int max = -2147483648;
	for (int i = 0; i < numsSize; i++)
	{
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	/*返回结果*/
	return max;
}

/*主函数省略*/
