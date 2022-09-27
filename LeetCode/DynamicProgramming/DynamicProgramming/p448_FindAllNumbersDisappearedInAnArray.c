#include<stdio.h>
#include<stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
	int* res = (int*)calloc(numsSize, sizeof(int));
	int resIndex = 0;
	int* map = (int*)calloc(numsSize + 1, sizeof(int));
	for (int i = 0; i < numsSize; i++)
	{
		map[nums[i]]++;
	}
	for (int i = 1; i <= numsSize; i++)
	{
		if (map[i] == 0)
		{
			res[resIndex++] = i;
		}
	}
	*returnSize = resIndex;
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/