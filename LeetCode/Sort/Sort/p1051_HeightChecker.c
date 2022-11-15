#include<stdio.h>

int heightChecker(int* heights, int heightsSize)
{
	int maxHeight = 0;
	for (int i = 0; i < heightsSize; i++)
	{
		if (heights[i] > maxHeight)
		{
			maxHeight = heights[i];
		}
	}
	int* count = (int*)calloc(maxHeight + 1, sizeof(int));
	for (int i = 0; i < heightsSize; i++)
	{
		count[heights[i]]++;
	}
	int index = 0;
	int res = 0;
	for (int i = 1; i <= maxHeight; i++)
	{
		for (int j = 1; j <= count[i]; j++)
		{
			if (heights[index] != i)
			{
				res++;
			}
			index++;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/