#include<stdio.h>

int* grayCode(int n, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * (1 << n));
	int len = 1 << n;
	res[0] = 0;
	int head = 1;
	int index = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = index - 1; j >= 0; j--)
		{
			res[index++] = head + res[j];
		}
		head <<= 1;
	}
	*returnSize = index;
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/