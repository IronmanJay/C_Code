#include<stdio.h>
#include<stdlib.h>

int missingNumber(int* nums, int numsSize)
{
	int* map = (int*)calloc(numsSize + 1, sizeof(int));
	for (int i = 0; i < numsSize; i++)
	{
		map[nums[i]] = 1;
	}
	for (int i = 0; i <= numsSize; i++)
	{
		if (map[i] == 0)
		{
			return i;
		}
	}
	return NULL;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/