#include<stdio.h>
#include<math.h>

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
	if (matrixSize == 0)
	{
		return 0;
	}
	int dp[301][301] = { 0 };
	int max = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixColSize[0]; j++)
		{
			if (matrix[i][j] == '1')
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = fmin(dp[i - 1][j - 1], fmin(dp[i][j - 1], dp[i - 1][j])) + 1;
				}
			}
			max = fmax(max, dp[i][j]);
		}
	}
	return max * max;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/