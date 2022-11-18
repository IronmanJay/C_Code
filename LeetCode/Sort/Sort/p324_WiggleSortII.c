#include<stdio.h>

void wiggleSort(int* nums, int numsSize)
{
	int* bucket = (int*)calloc(5001, sizeof(int));
	for (int i = 0; i < numsSize; i++)
	{
		bucket[nums[i]]++;
	}
	for (int i = 1, j = 5000; i < numsSize; i += 2)
	{
		while (bucket[j] == 0)
		{
			j--;
		}
		nums[i] = j;
		bucket[j]--;
	}
	for (int i = 0, j = 5000; i < numsSize; i += 2)
	{
		while (bucket[j] == 0)
		{
			j--;
		}
		nums[i] = j;
		bucket[j]--;
	}
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/