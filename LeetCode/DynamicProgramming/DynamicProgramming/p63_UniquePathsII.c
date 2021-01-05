#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
	/*获取行数*/
	int raw = obstacleGridSize;
	/*获取列数*/
	int col = obstacleGridColSize[0];
	/*动态数组，存放每一个位置可以到达的不同路径数目*/
	int** dp = (int*)malloc(sizeof(int*)*raw);
	for (int i = 0; i < raw; i++)
	{
		dp[i] = (int*)calloc(col, sizeof(int));
	}
	/*遍历每一个位置*/
	for (int x = 0; x < raw; x++)
	{
		for (int y = 0; y < col; y++)
		{
			/*遇到障碍物到达当前位置的不同路径数目就为0*/
			if (obstacleGrid[x][y] == 1)
			{
				dp[x][y] = 0;
			}
			else
			{
				/*起点可以到达的不同路径数目肯定为1*/
				if (x == 0 && y == 0)
				{
					dp[x][y] = 1;
				}
				/*第一行不能全部初始化为1，要根据是否有障碍物判断*/
				else if (x == 0)
				{
					dp[x][y] = dp[x][y - 1];
				}
				/*第一列不能全部初始化为1，要根据是否有障碍物判断*/
				else if (y == 0)
				{
					dp[x][y] = dp[x - 1][y];
				}
				/*因为题目说机器人只能向下走或者向右走，因为之前的状态已经更新，那么除了第一行和第一列的所有位置都可以更新为左面和上面过来的可到达的不同路径数目之和*/
				else
				{
					dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
				}
			}
		}
	}
	/*最终动态数组到达右下角就更新为所有不同路径的数目*/
	return dp[raw - 1][col - 1];
}

/*主函数省略*/
