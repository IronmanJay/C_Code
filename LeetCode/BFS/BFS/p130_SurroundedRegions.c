#include<stdio.h>
#include<stdlib.h>

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };

void solve(char** board, int boardSize, int* boardColSize)
{
	int m = boardSize;
	int n = boardColSize[0];
	int** queue = (int**)malloc(sizeof(int*) * (m * n));
	for (int i = 0; i < (m*n); i++)
	{
		queue[i] = (int*)malloc(sizeof(int) * 2);
	}
	int front = 0;
	int rear = 0;
	for (int i = 0; i < m; i++)
	{
		if (board[i][0] == 'O')
		{
			board[i][0] = 'A';
			queue[rear][0] = i;
			queue[rear++][1] = 0;
		}
		if (board[i][n - 1] == 'O')
		{
			board[i][n - 1] = 'A';
			queue[rear][0] = i;
			queue[rear++][1] = n - 1;
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (board[0][i] == 'O')
		{
			board[0][i] = 'A';
			queue[rear][0] = 0;
			queue[rear++][1] = i;
		}
		if (board[m - 1][i] == 'O')
		{
			board[m - 1][i] = 'A';
			queue[rear][0] = m - 1;
			queue[rear++][1] = i;
		}
	}
	while (front < rear)
	{
		int x = queue[front][0];
		int y = queue[front++][1];
		for (int i = 0; i < 4; i++)
		{
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cx >= m || cy < 0 || cy >= n || board[cx][cy] != 'O')
			{
				continue;
			}
			board[cx][cy] = 'A';
			queue[rear][0] = cx;
			queue[rear++][1] = cy;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'A')
			{
				board[i][j] = 'O';
			}
			else if (board[i][j] == 'O')
			{
				board[i][j] = 'X';
			}
		}
	}
	for (int i = 0; i < (m*n); i++)
	{
		free(queue[i]);
	}
	free(queue);
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/