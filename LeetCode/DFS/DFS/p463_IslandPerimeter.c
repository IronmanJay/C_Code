#include<stdio.h>

int dfs_p463_IslandPerimeter(int** grid, int r, int c, int row, int col)
{
	if (!(0 <= r && r < row && 0 <= c && c < col))
	{
		return 1;
	}
	if (grid[r][c] == 0)
	{
		return 1;
	}
	if (grid[r][c] != 1)
	{
		return 0;
	}
	grid[r][c] = 2;
	return dfs_p463_IslandPerimeter(grid, r - 1, c, row, col) + dfs_p463_IslandPerimeter(grid, r + 1, c, row, col) + dfs_p463_IslandPerimeter(grid, r, c - 1, row, col) + dfs_p463_IslandPerimeter(grid, r, c + 1, row, col);
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize)
{
	int row = gridSize;
	int col = gridColSize[0];
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			if (grid[r][c] == 1)
			{
				return dfs_p463_IslandPerimeter(grid, r, c, row, col);
			}
		}
	}
	return 0;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/