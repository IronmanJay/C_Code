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
int I1710countInRange(int* nums, int target, int left, int right)
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
 * 使用分治算法查找每部分的主要元素
 *
 * @param nums  待查数组
 * @param left  左指针
 * @param right 右指针
 * @return 当前部分的主要元素
 */
int I1710majorityElementReturn(int* nums, int left, int right)
{
	/*如果分成了单个元素，直接返回，开始“治”*/
	if (left == right)
	{
		return nums[left];
	}
	/*这里使用二分法，开始“分”*/
	int mid = (right - left) / 2 + left;
	/*分别向左右递归，开始“分”，最终将数组分成单个元素*/
	int leftNum = I1710majorityElementReturn(nums, left, mid);
	int rightNum = I1710majorityElementReturn(nums, mid + 1, right);
	/*如果分成当前部分单个元素，左边元素值和右边元素值相等，说明当前阶段的众数就是这个元素，返回即可，这也是“治”*/
	if (leftNum == rightNum)
	{
		return leftNum;
	}
	/*如果分成当前部分单个元素左边和右边不相等，那么就需要在当前数组中分别找到各自出现的次数*/
	int leftNumCount = I1710countInRange(nums, leftNum, left, mid);
	int rightNumCount = I1710countInRange(nums, rightNum, mid + 1, right);
	/*这里记录当前左右数组的一半，如果当前元素出现次数大于当前数组的一半，那么肯定是这个数组的主要元素*/
	int leftHalf = (mid - left) >> 1;
	int rightHalf = (right - (mid + 1)) >> 1;
	/*这里两个判断条件，首先是当前元素出现的次数要大于当前数组的一半，另一个是左边元素出现的次数要大于右边元素出现的次数，这样左边就是当前数组的主要元素*/
	if (leftNumCount > leftHalf && leftNumCount > rightNumCount)
	{
		return leftNum;
	}
	/*右边判断同上*/
	if (rightNumCount > rightHalf && leftNumCount < rightNumCount)
	{
		return rightNum;
	}
	/*正常情况下，当左边元素出现次数和右边元素出现次数相等时，返回左右元素均可，但这里为了避免特殊情况，例如[8,8,7,7,7]，这种情况左边8出现2次，右边7出现2次，看似出现次数一样，其实左边小数组是[8,8,7]，右边小数组是[7,7]，这样对右边小数组是不公平的，因为有一次7没算进去，所以当他们个数相等时，返回右边的*/
	if (leftNumCount == rightNumCount)
	{
		return rightNum;
	}
	/*如果上述情况都不满足，返回-1*/
	return -1;
}

int I1710majorityElement(int* nums, int numsSize)
{
	return I1710majorityElementReturn(nums, 0, numsSize - 1);
}

/*主函数省略*/
