#include<stdio.h>

int maxProfit(int* prices, int pricesSize)
{
	int maxProfit = 0;
	int minPrice = prices[0];
	for (int i = 0; i < pricesSize; i++)
	{
		if (prices[i] < minPrice)
		{
			minPrice = prices[i];
		}
		if ((prices[i] - minPrice) > maxProfit)
		{
			maxProfit = prices[i] - minPrice;
		}
	}
	return maxProfit;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/
