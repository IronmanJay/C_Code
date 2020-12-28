#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*�ж��Ƿ��ǻ����Ӵ�*/
bool checkPalindrome(char* s, int left, int right)
{
	while (left < right)
	{
		if (s[left] != s[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}

/*����*/
void p131_PalindromePartitioning_getRes(char* s, int start, int end, char*** res, int* resIndex, int* colSize, char path[][100], int pathIndex)
{
	/*�ҵ�һ������Ӵ��ͼ��뵽���������*/
	if (start == end)
	{
		colSize[*resIndex] = pathIndex;
		res[*resIndex] = malloc(sizeof(char**)*pathIndex);
		for (int i = 0; i < pathIndex; i++)
		{
			res[*resIndex][i] = malloc(strlen(path[i]) + 1);
			strncpy(res[*resIndex][i], path[i], strlen(path[i]) + 1);
		}
		(*resIndex)++;
		return;
	}
	/*���������Ӵ�*/
	for (int i = start; i < end; i++)
	{
		/*��֦*/
		if (checkPalindrome(s, start, i))
		{
			strncpy(path[pathIndex++], s + start, i - start + 1);
			p131_PalindromePartitioning_getRes(s, i + 1, end, res, resIndex, colSize, path, pathIndex);
			/*���ݵ���һ��״̬*/
			memset(path[--pathIndex], 0, 100);
		}
	}
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes)
{
	/*�������*/
	char*** res = (char***)malloc(sizeof(char**) * 10000);
	/*�������ָ��*/
	int resIndex = 0;
	/*��Ŷ�ά�����С*/
	int* colSize = (int*)malloc(sizeof(int) * 10000);
	/*·������*/
	char path[10000][100] = { 0 };
	/*��ʼ�ݹ�*/
	p131_PalindromePartitioning_getRes(s, 0, strlen(s), res, &resIndex, colSize, path, 0);
	/*���÷��ز���*/
	*returnSize = resIndex;
	*returnColumnSizes = colSize;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
