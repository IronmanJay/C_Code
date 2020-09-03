#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * 交换数组中两个元素
 *
 * @param nums   待交换数组
 * @param index1 索引1
 * @param index2 索引2
 */
void swap(int* nums, int index1, int index2)
{
	int temp = nums[index1];
	nums[index1] = nums[index2];
	nums[index2] = temp;
}

void sortColors(int* nums, int numsSize)
{
	/*0在数组中的索引位置，nums[0,zeroIndex] = 0*/
	int zeroIndex = 0;
	/*2在数组中的索引位置，nums[twoIndex,nums.length-1] = 2*/
	int twoIndex = numsSize - 1;
	/**
	 * 遍历数组，自定义i的变化，另外注意这里要小于twoIndex，因为twoIndex是随着排序变化
	 * 而变化的，我们排序好的就不需要遍历了，所以不能小于等于数组长度
	 */
	for (int i = 0; i <= twoIndex;)
	{
		/**
		 * 因为就三个数字，所以定义1为基准值，如果当前元素等于基准（1）值数组不发生变化，
		 * nums[zeroIndex,twoIndex] = 1;
		 */
		if (nums[i] == 1)
		{
			i++;
		}
		/**
		 * 如果当前元素等于0，说明要放到最左边，这里注意交换之后i要+1，+1的目的是保证只要遇到0两个指针一起移动，
		 * 又因为i是从小遍历到大，说明之前的已经排好序了，按照0->1排序那么遇到1，i++，zeroIndex不++，
		 * 保证从左边交换来的值肯定是1，不影响数组排序结果，所以无需二次比较
		 */
		else if (nums[i] == 0)
		{
			swap(nums, i++, zeroIndex++);
		}
		/**
		 * 如果当前元素等于2，说明要放到最右边，这里注意交换之后，i不发生变化，
		 * 因为右边交换过来的值有可能大也有可能小，所以需要二次比较
		 */
		else
		{
			swap(nums, i, twoIndex--);
		}
	}
}

/*主函数省略*/