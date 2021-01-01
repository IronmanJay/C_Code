#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool p212_WordSearchII_backTrack(char** board, int boardSize, int boardColSize, char* word, int wordIndex, bool** visited, int x, int y)
{
	/*剪枝操作：边界值或者当前位置已经访问过或者当前字符和待匹配字符不相等直接返回false*/
	if (x < 0 || x >= boardSize || y < 0 || y >= boardColSize || visited[x][y] || board[x][y] != word[wordIndex])
	{
		return false;
	}
	/*递归跳出条件：这步必须放在剪枝操作的后面，必须先判断当前字符和待匹配字符相等，如果相等且将待匹配字符串都已经匹配过了，递归跳出，返回true*/
	if (wordIndex + 1 == strlen(word))
	{
		return true;
	}
	/*将当前位置的字符置为已访问*/
	visited[x][y] = 1;
	/*分别向右上下左四个方向继续匹配*/
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
	/*回溯操作：如果右上下左四个方向均没有匹配成功返回到上一个状态，并且返回false，说明当前路径不通，也就是没有找到*/
	else
	{
		visited[x][y] = 0;
		return false;
	}
}

bool p212_WordSearchII_exist(char** board, int boardSize, int boardColSize, char* word, int wordIndex, bool** visited)
{
	/*遍历每一个位置作为起点*/
	for (int x = 0; x < boardSize; x++)
	{
		for (int y = 0; y < boardColSize; y++)
		{
			/*如果在表格中找到待查找单词就返回true，让主函数加入这个单词*/
			if (p212_WordSearchII_backTrack(board, boardSize, boardColSize, word, wordIndex, visited, x, y))
			{
				return true;
			}
		}
	}
	/*如果在表格中没有找到待查找单词就返回true，让主函数不要加入这个单词*/
	return false;
}

char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize)
{
	/*结果数组，用于存放找到的单词*/
	char** res = (char**)malloc(sizeof(char*) * 1000);
	/*结果数组指针*/
	int resIndex = 0;
	/*设置访问二维数组，防止二次遍历*/
	int** visited = (int**)malloc(sizeof(int*)*boardSize);
	/*遍历每一个待查找单词*/
	for (int i = 0; i < wordsSize; i++)
	{
		/*对每一个待查找单词都设置一个新的访问二维数组，防止二次遍历*/
		for (int j = 0; j < boardSize; j++)
		{
			visited[j] = (int*)calloc(boardColSize[0], sizeof(int));
		}
		/*如果在表格中找到待查找单词就加入到结果数组中*/
		if (p212_WordSearchII_exist(board, boardSize, boardColSize[0], words[i], 0, visited))
		{
			res[resIndex++] = words[i];
		}
	}
	/*设置返回的结果数组的大小*/
	*returnSize = resIndex;
	/*返回结果*/
	return res;
}

/*主函数省略*/
