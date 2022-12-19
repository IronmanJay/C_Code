#include<stdio.h>
#include<stdlib.h>

int* countBits(int n, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * (n + 1));
	res[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			res[i] = res[i / 2];
		}
		else
		{
			res[i] = res[i / 2] + 1;
		}
	}
	*returnSize = n + 1;
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/