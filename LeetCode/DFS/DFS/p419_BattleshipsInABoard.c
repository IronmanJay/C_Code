#include<stdio.h>

int countBattleships(char** board, int boardSize, int* boardColSize)
{
	int m = boardSize;
	int n = boardColSize[0];
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((board[i][j] == 'X') && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
			{
				count++;
			}
		}
	}
	return count;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/