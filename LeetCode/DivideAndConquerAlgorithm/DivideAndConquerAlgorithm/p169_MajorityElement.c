#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * 返回当前部分数组某个元素出现的次数
 *
 * @param nums   部分数组
 * @param target 目标值
 * @param left   左指针
 * @param right  右指针
 * @return 当前部分数组target出现的次数
 */
int p169countInRange(int* nums, int target, int left, int right)
{
	int count = 0;
	for (int i = left; i <= right; i++)
	{
		if (nums[i] == target)
		{
			count++;
		}
	}
	return count;
}

/**
 * 使用分治算法查找每部分的众数
 *
 * @param nums  待查数组
 * @param left  左指针
 * @param right 右指针
 * @return 当前部分的众数
 */
int p169majorityElementReturn(int* nums, int left, int right)
{
	/*如果分成了单个元素，直接返回，开始“治”*/
	if (left == right)
	{
		return nums[left];
	}
	/*这里使用二分法，开始“分”*/
	int mid = (right - left) / 2 + left;
	/*分别向左右递归，开始“分”，最终将数组分成单个元素*/
	int leftNum = p169majorityElementReturn(nums, left, mid);
	int rightNum = p169majorityElementReturn(nums, mid + 1, right);
	/*如果分成当前部分单个元素，左边元素值和右边元素值相等，说明当前阶段的众数就是这个元素，返回即可，这也是“治”*/
	if (leftNum == rightNum)
	{
		return leftNum;
	}
	/*如果分成当前部分单个元素左边和右边不相等，那么就需要在当前数组中找到谁出现的次数更多就返回谁*/
	int leftNumCount = p169countInRange(nums, leftNum, left, mid);
	int rightNumCount = p169countInRange(nums, rightNum, mid + 1, right);
	/*得到的结果谁出现的次数多就返回谁*/
	return leftNumCount > rightNumCount ? leftNum : rightNum;
}

int p169majorityElement(int* nums, int numsSize)
{
	return p169majorityElementReturn(nums, 0, numsSize - 1);
}

int main(void)
{
	/*主函数省略*/
}