#include<stdio.h>
#include<stdlib.h>

int waysToStep(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	if (n == 3)
	{
		return 4;
	}
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000007 + dp[i - 3]) % 1000000007;
	}
	return dp[n];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/