#include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize <= 2)
	{
		return numsSize;
	}
	int slow = 2;
	int fast = 2;
	while (fast < numsSize)
	{
		if (nums[slow - 2] != nums[fast])
		{
			nums[slow++] = nums[fast];
		}
		fast++;
	}
	return slow;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/