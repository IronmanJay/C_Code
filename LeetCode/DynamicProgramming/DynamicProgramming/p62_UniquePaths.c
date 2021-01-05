#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int uniquePaths(int m, int n)
{
	/*动态数组，存放每一个位置可以到达的不同路径数目*/
	int** dp = (int **)malloc(sizeof(int *)*m);
	for (int i = 0; i < m; i++)
	{
		dp[i] = (int*)calloc(n, sizeof(int));
	}
	/*遍历每一个位置*/
	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			/*因为题目说机器人只能向下走或者向右走，所以第一行和第一列的所有元素位置只能走直线到达，那么可以到达的不同路径数目就是1*/
			if (x == 0 || y == 0)
			{
				dp[x][y] = 1;
			}
			/*同样因为题目说机器人只能向下走或者向右走，因为之前的状态已经更新，那么除了第一行和第一列的所有位置都可以更新为左面和上面过来的可到达的不同路径数目之和*/
			else
			{
				dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
			}
		}
	}
	/*最终动态数组到达右下角就更新为所有不同路径的数目*/
	return dp[m - 1][n - 1];
}

/*主函数省略*/
