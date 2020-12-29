#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool p79_WordSearch_backTrack(char** board, int** visited, char* word, int wordIndex, char* path, int pathIndex, int x, int y, int row, int col)
{
	/*剪枝操作：边界值或者当前位置已经访问过或者当前字符和待匹配字符不相等直接返回false*/
	if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || board[x][y] != word[wordIndex])
	{
		return false;
	}
	/*递归跳出条件：这步必须放在剪枝操作的后面，必须先判断当前字符和待匹配字符相等，如果相等且将待匹配字符串都已经匹配过了，递归跳出，返回true*/
	if (wordIndex + 1 == strlen(word))
	{
		return true;
	}
	/*将当前字符加入到字符路径中*/
	path[pathIndex++] = board[x][y];
	/*将当前位置的字符置为已访问*/
	visited[x][y] = 1;
	/*分别向右上下左四个方向继续匹配*/
	if (p79_WordSearch_backTrack(board, visited, word, wordIndex + 1, path, pathIndex, x, y + 1, row, col))
	{
		return true;
	}
	else if (p79_WordSearch_backTrack(board, visited, word, wordIndex + 1, path, pathIndex, x - 1, y, row, col))
	{
		return true;
	}
	else if (p79_WordSearch_backTrack(board, visited, word, wordIndex + 1, path, pathIndex, x + 1, y, row, col))
	{
		return true;
	}
	else if (p79_WordSearch_backTrack(board, visited, word, wordIndex + 1, path, pathIndex, x, y - 1, row, col))
	{
		return true;
	}
	/*回溯操作：如果右上下左四个方向均没有匹配成功返回到上一个状态，并且返回false，说明当前路径不通，也就是没有找到*/
	else
	{
		path[--pathIndex] == 0;
		visited[x][y] = 0;
		return false;
	}
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
	/*获取表格长度和宽度*/
	int row = boardSize;
	int col = boardColSize[0];
	/*边界条件直接返回false*/
	if (row * col < strlen(word) || strlen(word) == 0)
	{
		return false;
	}
	/*设置访问二维数组，防止二次遍历*/
	int** visited = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		visited[i] = (int*)calloc(col, sizeof(int));
	}
	/*路经数组，存放满足条件的字符串*/
	char* path = (char*)malloc(strlen(word) * sizeof(char));
	for (int i = 0; i < strlen(word); i++)
	{
		path[i] = 0;
	}
	/*遍历每一个位置作为起点*/
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			/*找到一条满足条件的路径就返回true*/
			if (p79_WordSearch_backTrack(board, visited, word, 0, path, 0, x, y, row, col))
			{
				return true;
			}
		}
	}
	/*一条满足条件的路径都没找到返回false*/
	return false;
}
