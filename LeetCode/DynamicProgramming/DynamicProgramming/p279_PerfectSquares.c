#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*返回较小值*/
int p279_PerfectSquares_Min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

int numSquares(int n)
{
	/*动态数组*/
	int* dp = (int*)malloc(sizeof(int)*(n + 1));
	/*第一个数是0，没有数的和是0，所以是0*/
	dp[0] = 0;
	/*遍历数组*/
	for (int i = 1; i <= n; i++)
	{
		/*最坏的情况是1+1+1+……+1*/
		dp[i] = i;
		/*找每一个状态的最优解*/
		for (int j = 1; i - j * j >= 0; j++)
		{
			dp[i] = p279_PerfectSquares_Min(dp[i], dp[i - j * j] + 1);
		}
	}
	/*返回结果*/
	return dp[n];
}

/*主函数省略*/
