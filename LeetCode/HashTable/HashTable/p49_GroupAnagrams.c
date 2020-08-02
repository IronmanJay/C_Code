#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*定义最大长度*/
#define STR_SIZE 100

/*模拟Hash表结构*/
typedef struct Node
{
	char str[STR_SIZE]; /*key为字符串*/
	int row; /*value为结果所在的行*/
	struct Node* next;
}HashNode;

/*找Hash值*/
int hash(char* str, int size)
{
	long h = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		/*字符串的hashcode, 权为26是因为小写字母，不限制时为128，这样能够让结点尽可能分布均匀，减少地址冲突，取模是为了防止int型溢出*/
		h = (h * 26 % size + str[i] - 'a') % size;
	}
	return h % size;
}

/*判断是否存在Hash表中*/
bool contain(HashNode* hashTable, char* str, int size)
{
	HashNode *head = &hashTable[hash(str, size)];
	HashNode *tail = head->next;
	while (tail) {
		if (strcmp(tail->str, str) == 0)
		{
			return true;
		}
		tail = tail->next;
	}
	return false;
}

/*添加值*/
void add(HashNode* hashTable, char* str, int size, int row)
{
	if (contain(hashTable, str, size))
	{
		return;
	}
	HashNode *head = &hashTable[hash(str, size)];
	/*头插建表*/
	HashNode *q = malloc(sizeof(HashNode));
	strcpy(q->str, str);
	q->row = row;
	q->next = head->next;
	head->next = q;
}

/*获得所在行*/
int getRows(HashNode *hashTable, char *str, int size)
{
	HashNode *head = &hashTable[hash(str, size)];
	HashNode *tail = head->next;
	while (tail)
	{
		if (strcmp(tail->next, str) == 0)
		{
			return tail->row;
		}
		tail = tail->next;
	}
	return -1;
}

/*比较器，用于排序*/
int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
	if (strsSize == 0 || strs == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	HashNode *hashTable = malloc(sizeof(HashNode) * strsSize);
	memset(hashTable, 0, sizeof(HashNode) * strsSize);
	char ***res = malloc(sizeof(char **) * strsSize);
	*returnSize = 0;
	*returnColumnSizes = malloc(sizeof(int) * strsSize);
	for (int i = 0; i < strsSize; i++)
	{
		char curStr[STR_SIZE] = "";
		strcpy(curStr, strs[i]);
		int lenStr = strlen(curStr);
		/*排序*/
		qsort(curStr, lenStr, sizeof(char), cmp);
		/*key已经存在了*/
		if (contain(hashTable, curStr, strsSize))
		{
			/*获得之前key的结果所在行*/
			int row = getRows(hashTable, curStr, strsSize);
			int col = (*returnColumnSizes)[row];
			res[row][col] = malloc(sizeof(char) * (lenStr + 1));
			strcpy(res[row][col], strs[i]);
			(*returnColumnSizes)[row]++;
		}
		/*key不存在*/
		else
		{
			/*插入Hash表中*/
			add(hashTable, curStr, strsSize, *returnSize);
			/*申请一行*/
			res[*returnSize] = malloc(sizeof(char *) * strsSize);
			res[*returnSize][0] = malloc(sizeof(char) * (lenStr + 1));
			strcpy(res[*returnSize][0], strs[i]);
			(*returnColumnSizes)[*returnSize] = 1;
			(*returnSize)++;
		}
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/