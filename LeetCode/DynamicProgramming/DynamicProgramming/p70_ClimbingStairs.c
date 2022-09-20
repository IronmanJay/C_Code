#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n)
{
	if (n <= 1)
	{
		return n;
	}
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/