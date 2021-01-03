#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*返回两者中较大值*/
int I1617_ContiguousSequenceLcci_Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int I1617_ContiguousSequenceLcci_Max_maxSubArray(int* nums, int numsSize)
{
	/*判空返回0*/
	if (numsSize == 0)
	{
		return 0;
	}
	/*如果只有一个元素，直接返回*/
	if (numsSize == 1)
	{
		return nums[0];
	}
	/*动态数组，存储累加数值*/
	int* dp = (int*)malloc(sizeof(int) * numsSize);
	/*第一次累加就是数组的第一个值*/
	dp[0] = nums[0];
	/*最大值，初始值为数组第一个元素，不断更新，最后返回总和最大的连续数列和*/
	int max = nums[0];
	/*从第二个元素开始遍历整个数组*/
	for (int i = 1; i < numsSize; i++)
	{
		/*动态数组对应位置存储当前位置元素和之前的和元素中较大的值*/
		dp[i] = I1617_ContiguousSequenceLcci_Max((dp[i - 1] + nums[i]), nums[i]);
		/*更新最大值*/
		max = I1617_ContiguousSequenceLcci_Max(max, dp[i]);
	}
	/*返回结果*/
	return max;
}

/*主函数省略*/
