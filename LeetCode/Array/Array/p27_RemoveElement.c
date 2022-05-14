#include<stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
	int len = numsSize, index = 0;
	if (len == 0 || nums == NULL)
	{
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		if (nums[i] != val)
		{
			nums[index++] = nums[i];
		}
	}
	return index;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/
