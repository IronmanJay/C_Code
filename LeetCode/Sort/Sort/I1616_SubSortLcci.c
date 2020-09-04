#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int I1616_SubSortLcci_compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int* subSort(int* array, int arraySize, int* returnSize)
{
	int* temp = (int *)malloc(sizeof(int) * arraySize);
	memcpy(temp, array, sizeof(int) * arraySize);
	qsort(array, arraySize, sizeof(int), I1616_SubSortLcci_compare);
	int* res = (int *)malloc(sizeof(int) * 2);
	res[0] = -1;
	res[1] = -1;
	for (int i = 0; i < arraySize; i++)
	{
		if (temp[i] != array[i])
		{
			if (res[0] == -1)
			{
				res[0] = i;
			}
			res[1] = i;
		}
	}
	*returnSize = 2;
	return res;
}