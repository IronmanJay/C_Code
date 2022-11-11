#include<stdio.h>

int maxProfit_p714_BestTimeToBuyAndSellStockWithTransactionFee(int* prices, int pricesSize, int fee)
{
	if (pricesSize <= 1)
	{
		return 0;
	}
	int base = prices[0] + fee;
	int profit = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] > base)
		{
			profit += prices[i] - base;
			base = prices[i];
		}
		else if (prices[i] + fee < base)
		{
			base = prices[i] + fee;
		}
	}
	return profit;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/