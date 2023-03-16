#include<stdio.h>

void moveZeroes(int* nums, int numsSize)
{
	for (int i = 0, j = 0; i < numsSize; i++)
	{
		if (nums[i] != 0)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j++] = temp;
		}
	}
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/