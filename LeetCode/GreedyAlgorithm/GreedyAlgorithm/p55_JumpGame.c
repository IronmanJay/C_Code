#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*返回两个数中大值*/
int Max_p55_JumpGame(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

bool canJump(int* nums, int numsSize)
{
	/*表示每个位置可以跳的最远距离*/
	int maxLen = nums[0];
	/*开始遍历*/
	for (int i = 1; i < numsSize; i++)
	{
		/*如果当前位置在前一个位置所能跳的最远距离范围内，看当前位置能跳的最远距离是否大于前一个位置所能跳的最远距离*/
		if (i <= maxLen)
		{
			/*如果能跳的更远，更新可以跳的最远距离*/
			maxLen = Max_p55_JumpGame(maxLen, nums[i] + i);
		}
	}
	/*如果最终的距离超过最后一个位置，即可以到达最后一个位置*/
	return maxLen >= numsSize - 1;
}

/*主函数省略*/
