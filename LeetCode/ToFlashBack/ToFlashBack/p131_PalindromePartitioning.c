#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*判断是否是回文子串*/
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

/*回溯*/
void p131_PalindromePartitioning_getRes(char* s, int start, int end, char*** res, int* resIndex, int* colSize, char path[][100], int pathIndex)
{
	/*找到一组回文子串就加入到结果数组中*/
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
	/*遍历整个子串*/
	for (int i = start; i < end; i++)
	{
		/*剪枝*/
		if (checkPalindrome(s, start, i))
		{
			strncpy(path[pathIndex++], s + start, i - start + 1);
			p131_PalindromePartitioning_getRes(s, i + 1, end, res, resIndex, colSize, path, pathIndex);
			/*回溯到上一个状态*/
			memset(path[--pathIndex], 0, 100);
		}
	}
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes)
{
	/*结果数组*/
	char*** res = (char***)malloc(sizeof(char**) * 10000);
	/*结果数组指针*/
	int resIndex = 0;
	/*存放二维数组大小*/
	int* colSize = (int*)malloc(sizeof(int) * 10000);
	/*路径数组*/
	char path[10000][100] = { 0 };
	/*开始递归*/
	p131_PalindromePartitioning_getRes(s, 0, strlen(s), res, &resIndex, colSize, path, 0);
	/*设置返回参数*/
	*returnSize = resIndex;
	*returnColumnSizes = colSize;
	/*返回结果*/
	return res;
}

/*主函数省略*/
