#include<stdio.h>

int dfs(int** grid, int i, int j, int row, int col)
{
	if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0)
	{
		return 0;
	}
	grid[i][j] = 0;
	int count = 1;
	count += dfs(grid, i + 1, j, row, col);
	count += dfs(grid, i, j + 1, row, col);
	count += dfs(grid, i - 1, j, row, col);
	count += dfs(grid, i, j - 1, row, col);
	return count;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
	int row = gridSize;
	int col = gridColSize[0];
	int res = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			res = fmax(res, dfs(grid, i, j, row, col));
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/