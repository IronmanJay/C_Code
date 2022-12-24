#include<stdio.h>
#include<stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
	int** dp = (int**)malloc(sizeof(int*)*pricesSize);
	for (int i = 0; i < pricesSize; i++)
	{
		dp[i] = (int*)calloc(5, sizeof(int));
	}
	dp[0][0] = 0;
	dp[0][1] = -prices[0];
	dp[0][2] = 0;
	dp[0][3] = -prices[0];
	dp[0][4] = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		dp[i][2] = fmax(dp[i - 1][2], dp[i - 1][1] + prices[i]);
		dp[i][3] = fmax(dp[i - 1][3], dp[i - 1][2] - prices[i]);
		dp[i][4] = fmax(dp[i - 1][4], dp[i - 1][3] + prices[i]);
	}
	return dp[pricesSize - 1][4];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/