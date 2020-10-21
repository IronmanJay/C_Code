#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*返回两个数中较小的值*/
int p209_MinimumSizeSubarraySum_MIN(int x, int y)
{
	return x > y ? y : x;
}

int minSubArrayLen(int s, int* nums, int numsSize)
{
	/*判空返回*/
	if (numsSize == 0)
	{
		return 0;
	}
	/*头指针*/
	int start = 0;
	/*尾指针*/
	int end = 0;
	/*存储当前窗口（区间）的数字和*/
	int sum = 0;
	/*最小连续子数组的长度*/
	int len = numsSize + 1;
	/*遍历数组*/
	while (end < numsSize)
	{
		/*累加求值，找到大于目标值的区间（窗口）*/
		sum += nums[end];
		/*找到一个窗口（区间）大于目标值*/
		while (sum >= s)
		{
			/*更新最小连续子数组的长度*/
			len = p209_MinimumSizeSubarraySum_MIN(len, (end - start + 1));
			/*继续在这个窗口（区间）缩小当前窗口（区间）继续寻找大于等于目标值的小窗口（区间），如果有的话，更新头指针和最小连续子数组的长度*/
			sum -= nums[start];
			start++;
		}
		/*当前窗口（区间）的数字和不大于等于目标值，向右滑动继续查找*/
		end++;
	}
	/*返回结果*/
	return len == (numsSize + 1) ? 0 : len;
}

/*主函数省略*/
