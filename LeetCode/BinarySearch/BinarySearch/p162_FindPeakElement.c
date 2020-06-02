#include<stdio.h>
#include<stdlib.h>
#include<io.h>

int findPeakElement(int* nums, int numsSize)
{
	if (numsSize == 1)
	{
		return 0;
	}
	if (numsSize == 2)
	{
		return nums[0] > nums[1] ? 0 : 1;
	}
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		if (left == right)
		{
			return right;
		}
		if (right - left == 1)
		{
			return nums[left] > nums[right] ? left : right;
		}
		int mid = (left + right) / 2;
		if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
		{
			return mid;
		}
		if (nums[mid] < nums[mid + 1])
		{
			left = mid + 1;
		}
		else if (nums[mid] < nums[mid - 1])
		{
			right = mid - 1;
		}
	}
	return -1;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/
