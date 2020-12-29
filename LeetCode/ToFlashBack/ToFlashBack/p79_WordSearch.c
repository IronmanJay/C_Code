#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool p79_WordSearch_backTrack(char** board, int** visited, char* word, int wordIndex, char* path, int pathIndex, int x, int y, int row, int col)
{
	/*��֦�������߽�ֵ���ߵ�ǰλ���Ѿ����ʹ����ߵ�ǰ�ַ��ʹ�ƥ���ַ������ֱ�ӷ���false*/
	if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || board[x][y] != word[wordIndex])
	{
		return false;
	}
	/*�ݹ������������ⲽ������ڼ�֦�����ĺ��棬�������жϵ�ǰ�ַ��ʹ�ƥ���ַ���ȣ��������ҽ���ƥ���ַ������Ѿ�ƥ����ˣ��ݹ�����������true*/
	if (wordIndex + 1 == strlen(word))
	{
		return true;
	}
	/*����ǰ�ַ����뵽�ַ�·����*/
	path[pathIndex++] = board[x][y];
	/*����ǰλ�õ��ַ���Ϊ�ѷ���*/
	visited[x][y] = 1;
	/*�ֱ������������ĸ��������ƥ��*/
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
	/*���ݲ�����������������ĸ������û��ƥ��ɹ����ص���һ��״̬�����ҷ���false��˵����ǰ·����ͨ��Ҳ����û���ҵ�*/
	else
	{
		path[--pathIndex] == 0;
		visited[x][y] = 0;
		return false;
	}
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
	/*��ȡ��񳤶ȺͿ��*/
	int row = boardSize;
	int col = boardColSize[0];
	/*�߽�����ֱ�ӷ���false*/
	if (row * col < strlen(word) || strlen(word) == 0)
	{
		return false;
	}
	/*���÷��ʶ�ά���飬��ֹ���α���*/
	int** visited = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		visited[i] = (int*)calloc(col, sizeof(int));
	}
	/*·�����飬��������������ַ���*/
	char* path = (char*)malloc(strlen(word) * sizeof(char));
	for (int i = 0; i < strlen(word); i++)
	{
		path[i] = 0;
	}
	/*����ÿһ��λ����Ϊ���*/
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			/*�ҵ�һ������������·���ͷ���true*/
			if (p79_WordSearch_backTrack(board, visited, word, 0, path, 0, x, y, row, col))
			{
				return true;
			}
		}
	}
	/*һ������������·����û�ҵ�����false*/
	return false;
}
