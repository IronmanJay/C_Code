#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
	/*��ȡ����*/
	int raw = obstacleGridSize;
	/*��ȡ����*/
	int col = obstacleGridColSize[0];
	/*��̬���飬���ÿһ��λ�ÿ��Ե���Ĳ�ͬ·����Ŀ*/
	int** dp = (int*)malloc(sizeof(int*)*raw);
	for (int i = 0; i < raw; i++)
	{
		dp[i] = (int*)calloc(col, sizeof(int));
	}
	/*����ÿһ��λ��*/
	for (int x = 0; x < raw; x++)
	{
		for (int y = 0; y < col; y++)
		{
			/*�����ϰ��ﵽ�ﵱǰλ�õĲ�ͬ·����Ŀ��Ϊ0*/
			if (obstacleGrid[x][y] == 1)
			{
				dp[x][y] = 0;
			}
			else
			{
				/*�����Ե���Ĳ�ͬ·����Ŀ�϶�Ϊ1*/
				if (x == 0 && y == 0)
				{
					dp[x][y] = 1;
				}
				/*��һ�в���ȫ����ʼ��Ϊ1��Ҫ�����Ƿ����ϰ����ж�*/
				else if (x == 0)
				{
					dp[x][y] = dp[x][y - 1];
				}
				/*��һ�в���ȫ����ʼ��Ϊ1��Ҫ�����Ƿ����ϰ����ж�*/
				else if (y == 0)
				{
					dp[x][y] = dp[x - 1][y];
				}
				/*��Ϊ��Ŀ˵������ֻ�������߻��������ߣ���Ϊ֮ǰ��״̬�Ѿ����£���ô���˵�һ�к͵�һ�е�����λ�ö����Ը���Ϊ�������������Ŀɵ���Ĳ�ͬ·����Ŀ֮��*/
				else
				{
					dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
				}
			}
		}
	}
	/*���ն�̬���鵽�����½Ǿ͸���Ϊ���в�ͬ·������Ŀ*/
	return dp[raw - 1][col - 1];
}

/*������ʡ��*/
