#include<stdio.h>
#include<stdlib.h>

const int dirs[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int dfs_p329_LongestIncreasingPathInAMatrix(int** matrix, int m, int n, int i, int j, int** temp)
{
	if (temp[i][j] != 0)
	{
		return temp[i][j];
	}
	temp[i][j]++;
	for (int k = 0; k < 4; k++)
	{
		int newRow = i + dirs[k][0];
		int newCol = j + dirs[k][1];
		if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[i][j])
		{
			temp[i][j] = fmax(temp[i][j], dfs_p329_LongestIncreasingPathInAMatrix(matrix, m, n, newRow, newCol, temp) + 1);
		}
	}
	return temp[i][j];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize)
{
	int m = matrixSize;
	int n = matrixColSize[0];
	int** temp = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
	{
		temp[i] = (int*)calloc(n, sizeof(int));
	}
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res = fmax(res, dfs_p329_LongestIncreasingPathInAMatrix(matrix, m, n, i, j, temp));
		}
	}
	free(temp);
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/