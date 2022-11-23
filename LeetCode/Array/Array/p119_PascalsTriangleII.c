#include<stdio.h>
#include<stdlib.h>

int* getRow(int rowIndex, int* returnSize)
{
	*returnSize = rowIndex + 1;
	int* res = (int*)calloc((*returnSize), sizeof(int));
	res[0] = 1;
	for (int i = 1; i <= rowIndex; i++)
	{
		for (int j = i; j > 0; j--)
		{
			res[j] = res[j] + res[j - 1];
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/