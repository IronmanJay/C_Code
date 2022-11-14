#include<stdio.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize)
{
	int left = 0;
	int right = numsSize - 1;
	while (left < right)
	{
		while (left < right && nums[left] % 2 == 0)
		{
			left++;
		}
		while (left < right && nums[right] % 2 != 0)
		{
			right--;
		}
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
	}
	*returnSize = numsSize;
	return nums;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/