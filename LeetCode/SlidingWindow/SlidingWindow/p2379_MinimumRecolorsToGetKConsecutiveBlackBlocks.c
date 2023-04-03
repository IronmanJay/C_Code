#include<stdio.h>
#include<string.h>

int minimumRecolors(char * blocks, int k)
{
	int sumW = 0;
	for (int i = 0; i < k; i++)
	{
		if (blocks[i] == 'W')
		{
			sumW++;
		}
	}
	int res = sumW;
	for (int i = k; i < strlen(blocks); i++)
	{
		if (blocks[i] == 'W')
		{
			sumW++;
		}
		if (blocks[i - k] == 'W')
		{
			sumW--;
		}
		res = fmin(res, sumW);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/