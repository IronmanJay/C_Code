#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool row[9][9];
bool col[9][9];
bool block[3][3][9];
bool valid;
int* spaces[81];
int spaceSize;

void dfs_back_p37_SudokuSolver(char** board, int pos)
{
	if (pos == spaceSize)
	{
		valid = true;
		return;
	}
	int i = spaces[pos][0];
	int j = spaces[pos][1];
	for (int digit = 0; digit < 9 && !valid; digit++)
	{
		if (!row[i][digit] && !col[j][digit] && !block[i / 3][j / 3][digit])
		{
			row[i][digit] = true;
			col[j][digit] = true;
			block[i / 3][j / 3][digit] = true;
			board[i][j] = digit + '0' + 1;
			dfs_back_p37_SudokuSolver(board, pos + 1);
			row[i][digit] = false;
			col[j][digit] = false;
			block[i / 3][j / 3][digit] = false;
		}
	}
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	memset(block, false, sizeof(block));
	valid = false;
	spaceSize = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				spaces[spaceSize] = malloc(sizeof(int) * 2);
				spaces[spaceSize][0] = i;
				spaces[spaceSize++][1] = j;
			}
			else
			{
				int digit = board[i][j] - '0' - 1;
				row[i][digit] = true;
				col[j][digit] = true;
				block[i / 3][j / 3][digit] = true;
			}
		}
	}
	dfs_back_p37_SudokuSolver(board, 0);
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/