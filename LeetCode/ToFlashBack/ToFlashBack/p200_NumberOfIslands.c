#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void p200_NumberOfIslands_backTrack(char** grid, int gridSize, int gridColSize, int x, int y)
{
	/*�ݹ������������߽����������ݹ��ֻҪ���ǵ���ͼ�֦*/
	if (x < 0 || x >= gridSize || y < 0 || y >= gridColSize || grid[x][y] != '1')
	{
		return;
	}
	/*����ǰ����Ⱦɫ*/
	grid[x][y] = '2';
	/*�����ֱ�����������Ѱ�ҵ���*/
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x + 1, y);
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x, y + 1);
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x - 1, y);
	p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize, x, y - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
	/*���*/
	int res = 0;
	/*����ÿһ��λ��*/
	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridColSize[0]; y++)
		{
			/*ֻ�е�������Ⱦɫ����*/
			if (grid[x][y] == '1')
			{
				/*���������ӵ���һƬ����Ⱦɫ*/
				p200_NumberOfIslands_backTrack(grid, gridSize, gridColSize[0], x, y);
				/*���+1*/
				res++;
			}
		}
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
