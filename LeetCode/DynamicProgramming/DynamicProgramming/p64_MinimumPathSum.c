#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*���ؽ�Сֵ*/
int p64_MinimumPathSum_Min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
	/*��ȡ����*/
	int row = gridSize;
	/*��ȡ����*/
	int col = gridColSize[0];
	/*����ǿվ��󷵻�0*/
	if (row == 0 || col == 0)
	{
		return 0;
	}
	/*���ֻ��һ����ֱ�ӷ���*/
	if (row == 1 && col == 1)
	{
		return grid[0][0];
	}
	/*����������ά����*/
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			/*��㣬ֱ����������Ϊû����������·��*/
			if (i == 0 && j == 0)
			{
				continue;
			}
			/*��һ�У�ֻ��������*/
			else if (i == 0)
			{
				grid[i][j] = grid[i][j] + grid[i][j - 1];
			}
			/*��һ�У�ֻ��������*/
			else if (j == 0)
			{
				grid[i][j] = grid[i][j] + grid[i - 1][j];
			}
			/*���ǵ�һ��Ҳ���ǵ�һ�У��������ߺ���������ѡȡС��·����״̬��*/
			else
			{
				grid[i][j] = p64_MinimumPathSum_Min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
			}
		}
	}
	/*�յ���������С·����*/
	return grid[row - 1][col - 1];
}

/*������ʡ��*/
