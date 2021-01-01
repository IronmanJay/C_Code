#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void p200_NumberOfIslands_backTrack(char** grid, int gridSize, int gridColSize, int x, int y)
{
	/*递归跳出条件：边界条件跳出递归或只要不是岛屿就剪枝*/
	if (x < 0 || x >= gridSize || y < 0 || y >= gridColSize || grid[x][y] != '1')
	{
		return;
	}
	/*将当前岛屿染色*/
	grid[x][y] = '2';
	/*继续分别向右下左上寻找岛屿*/
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x + 1, y);
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x, y + 1);
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x - 1, y);
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x, y - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
	/*结果*/
	int res = 0;
	/*遍历每一个位置*/
	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridColSize[0]; y++)
		{
			/*只有岛屿会进入染色函数*/
			if (grid[x][y] == '1')
			{
				/*将所有连接的这一片岛屿染色*/
				p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize[0], x, y);
				/*结果+1*/
				res++;
			}
		}
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
