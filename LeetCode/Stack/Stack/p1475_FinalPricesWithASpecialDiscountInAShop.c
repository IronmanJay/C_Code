#include<stdio.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize)
{
	int* stack = (int*)malloc(sizeof(int) * pricesSize);
	int top = -1;
	for (int i = 0; i < pricesSize; i++)
	{
		while (top != -1 && prices[stack[top]] >= prices[i])
		{
			prices[stack[top--]] -= prices[i];
		}
		stack[++top] = i;
	}
	*returnSize = pricesSize;
	return prices;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/