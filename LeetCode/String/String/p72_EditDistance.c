#include<stdio.h>
#include<stdlib.h>

int minDistance(char * word1, char * word2)
{
	int dp[501][501];
	int m = strlen(word1);
	int n = strlen(word2);
	dp[0][0] = 0;
	for (int i = 0; i <= m; i++)
	{
		dp[i][0] = i;
	}
	for (int j = 0; j <= n; j++)
	{
		dp[0][j] = j;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = fmin(dp[i][j - 1], fmin(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
			if (word1[i - 1] == word2[j - 1])
			{
				dp[i][j] = fmin(dp[i][j], dp[i - 1][j - 1]);
			}
		}
	}
	return dp[m][n];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/