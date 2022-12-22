#include<stdio.h>
#include<stdlib.h>

int nthUglyNumber(int n)
{
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	dp[1] = 1;
	int p2 = 1;
	int p3 = 1;
	int p5 = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = fmin(dp[p2] * 2, fmin(dp[p3] * 3, dp[p5] * 5));
		if (dp[i] == dp[p2] * 2)
		{
			p2++;
		}
		if (dp[i] == dp[p3] * 3)
		{
			p3++;
		}
		if (dp[i] == dp[p5] * 5)
		{
			p5++;
		}
	}
	return dp[n];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/