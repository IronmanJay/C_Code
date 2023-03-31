#include<stdio.h>
#include<stdlib.h>

int countTriplets(int* nums, int numsSize)
{
	int* count = (int*)calloc((1 << 16), sizeof(int));
	int res = 0;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = 0; j < numsSize; j++)
		{
			count[nums[i] & nums[j]]++;
		}
	}
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = 0; j < (1 << 16); j++)
		{
			if ((j & nums[i]) == 0)
			{
				res += count[j];
			}
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/