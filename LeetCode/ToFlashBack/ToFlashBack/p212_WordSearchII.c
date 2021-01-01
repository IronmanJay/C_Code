#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool p212_WordSearchII_backTrack(char** board, int boardSize, int boardColSize, char* word, int wordIndex, bool** visited, int x, int y)
{
	/*��֦�������߽�ֵ���ߵ�ǰλ���Ѿ����ʹ����ߵ�ǰ�ַ��ʹ�ƥ���ַ������ֱ�ӷ���false*/
	if (x < 0 || x >= boardSize || y < 0 || y >= boardColSize || visited[x][y] || board[x][y] != word[wordIndex])
	{
		return false;
	}
	/*�ݹ������������ⲽ������ڼ�֦�����ĺ��棬�������жϵ�ǰ�ַ��ʹ�ƥ���ַ���ȣ��������ҽ���ƥ���ַ������Ѿ�ƥ����ˣ��ݹ�����������true*/
	if (wordIndex + 1 == strlen(word))
	{
		return true;
	}
	/*����ǰλ�õ��ַ���Ϊ�ѷ���*/
	visited[x][y] = 1;
	/*�ֱ������������ĸ��������ƥ��*/
	if (p212_WordSearchII_backTrack(board, boardSize, boardColSize, word, wordIndex + 1, visited, x + 1, y))
	{
		return true;
	}
	else if (p212_WordSearchII_backTrack(board, boardSize, boardColSize, word, wordIndex + 1, visited, x, y + 1))
	{
		return true;
	}
	else if (p212_WordSearchII_backTrack(board, boardSize, boardColSize, word, wordIndex + 1, visited, x - 1, y))
	{
		return true;
	}
	else if (p212_WordSearchII_backTrack(board, boardSize, boardColSize, word, wordIndex + 1, visited, x, y - 1))
	{
		return true;
	}
	/*���ݲ�����������������ĸ������û��ƥ��ɹ����ص���һ��״̬�����ҷ���false��˵����ǰ·����ͨ��Ҳ����û���ҵ�*/
	else
	{
		visited[x][y] = 0;
		return false;
	}
}

bool p212_WordSearchII_exist(char** board, int boardSize, int boardColSize, char* word, int wordIndex, bool** visited)
{
	/*����ÿһ��λ����Ϊ���*/
	for (int x = 0; x < boardSize; x++)
	{
		for (int y = 0; y < boardColSize; y++)
		{
			/*����ڱ�����ҵ������ҵ��ʾͷ���true���������������������*/
			if (p212_WordSearchII_backTrack(board, boardSize, boardColSize, word, wordIndex, visited, x, y))
			{
				return true;
			}
		}
	}
	/*����ڱ����û���ҵ������ҵ��ʾͷ���true������������Ҫ�����������*/
	return false;
}

char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize)
{
	/*������飬���ڴ���ҵ��ĵ���*/
	char** res = (char**)malloc(sizeof(char*) * 1000);
	/*�������ָ��*/
	int resIndex = 0;
	/*���÷��ʶ�ά���飬��ֹ���α���*/
	int** visited = (int**)malloc(sizeof(int*)*boardSize);
	/*����ÿһ�������ҵ���*/
	for (int i = 0; i < wordsSize; i++)
	{
		/*��ÿһ�������ҵ��ʶ�����һ���µķ��ʶ�ά���飬��ֹ���α���*/
		for (int j = 0; j < boardSize; j++)
		{
			visited[j] = (int*)calloc(boardColSize[0], sizeof(int));
		}
		/*����ڱ�����ҵ������ҵ��ʾͼ��뵽���������*/
		if (p212_WordSearchII_exist(board, boardSize, boardColSize[0], words[i], 0, visited))
		{
			res[resIndex++] = words[i];
		}
	}
	/*���÷��صĽ������Ĵ�С*/
	*returnSize = resIndex;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
