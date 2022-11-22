#include<stdio.h>
#include<stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
	int** res = (int**)malloc(sizeof(int*)*numRows);
	*returnSize = numRows;
	*returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
	for (int i = 0; i < numRows; i++)
	{
		res[i] = (int*)malloc(sizeof(int) * (i + 1));
		(*returnColumnSizes)[i] = i + 1;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				res[i][j] = 1;
			}
			else
			{
				int x = res[i - 1][j - 1];
				int y = res[i - 1][j];
				res[i][j] = x + y;
			}
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/