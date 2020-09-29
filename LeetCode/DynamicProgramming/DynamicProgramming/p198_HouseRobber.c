#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*返回两者中较大值*/
int p198_HouseRobber_Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int rob(int* nums, int numsSize)
{
	/*数组长度为0返回0，数组长度为1返回第一个数*/
	if (numsSize <= 1)
	{
		return numsSize == 0 ? 0 : nums[0];
	}
	/*动态数组，对应位置存放到这个地方能获取的最大值*/
	int* dp = (int*)malloc(sizeof(int)*numsSize);
	/*第一个房屋能获取的最大值就是当前值*/
	dp[0] = nums[0];
	/*第二个房屋能获取的最大值是第一个位置和第二个位置中的较大值，就是选择钱多的房屋偷钱*/
	dp[1] = p198_HouseRobber_Max(nums[0], nums[1]);
	/*从第三个房屋开始遍历*/
	for (int i = 2; i < numsSize; i++)
	{
		/*这里对应的房屋更新可以偷的钱为当前的房屋加之前的房屋（i-2）和之前的房屋（i-1）中的较大值，因为有报警装置，所以隔着房屋偷钱*/
		dp[i] = p198_HouseRobber_Max(dp[i - 1], nums[i] + dp[i - 2]);
	}
	/*不断更新动态数组，最后一个元素就是能偷的最多钱*/
	return dp[numsSize - 1];
}

/*主函数省略*/
