#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 1024 /*����������󳤶�*/

/*�жϵ�ǰ��ȡ���Ƿ����*/
bool isValid(char *s, int len)
{
	if (s == '\0')
	{
		return false;
	}
	if (s[0] == '0' && len > 1)
	{
		return false;
	}
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		num = num * 10 + s[i] - '0';
	}
	if (num >= 0 && num <= 255)
	{
		return true;
	}
	return false;
}

/*ʹ��������ȱ���*/
void dfs(char *s, char **res, int *returnSize, char *str, int idx, int validNum)
{
	if (validNum > 4)
	{
		return;
	}
	if (s[0] == '\0' && validNum == 4)
	{
		res[*returnSize] = (char *)malloc(strlen(str) + 1);
		strcpy(res[*returnSize], str);
		(*returnSize)++;
	}
	if (validNum > 0 && validNum < 4)
	{
		str[idx++] = '.';
	}
	for (int len = 1; len <= 3 && len <= strlen(s); len++)
	{
		if (isValid(s, len))
		{
			for (int i = 0; i < len; i++)
			{
				str[idx + 1] = s[i];
			}
			dfs(s + len, res, returnSize, str, idx + len, validNum + 1);
		}
	}
}

/*����������������*/
char ** restoreIpAddresses(char * s, int* returnSize)
{
	char **res = (char **)malloc(MAX_SIZE * sizeof(char *));
	*returnSize = 0;
	char *str = (char *)calloc(strlen(s) + 4, sizeof(char));
	dfs(s, res, returnSize, str, 0, 0);
	return res;
}

/*������ʡ��*/
