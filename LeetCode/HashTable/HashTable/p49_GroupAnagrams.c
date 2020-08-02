#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*������󳤶�*/
#define STR_SIZE 100

/*ģ��Hash��ṹ*/
typedef struct Node
{
	char str[STR_SIZE]; /*keyΪ�ַ���*/
	int row; /*valueΪ������ڵ���*/
	struct Node* next;
}HashNode;

/*��Hashֵ*/
int hash(char* str, int size)
{
	long h = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		/*�ַ�����hashcode, ȨΪ26����ΪСд��ĸ��������ʱΪ128�������ܹ��ý�㾡���ֲܷ����ȣ����ٵ�ַ��ͻ��ȡģ��Ϊ�˷�ֹint�����*/
		h = (h * 26 % size + str[i] - 'a') % size;
	}
	return h % size;
}

/*�ж��Ƿ����Hash����*/
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

/*���ֵ*/
void add(HashNode* hashTable, char* str, int size, int row)
{
	if (contain(hashTable, str, size))
	{
		return;
	}
	HashNode *head = &hashTable[hash(str, size)];
	/*ͷ�彨��*/
	HashNode *q = malloc(sizeof(HashNode));
	strcpy(q->str, str);
	q->row = row;
	q->next = head->next;
	head->next = q;
}

/*���������*/
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

/*�Ƚ�������������*/
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
		/*����*/
		qsort(curStr, lenStr, sizeof(char), cmp);
		/*key�Ѿ�������*/
		if (contain(hashTable, curStr, strsSize))
		{
			/*���֮ǰkey�Ľ��������*/
			int row = getRows(hashTable, curStr, strsSize);
			int col = (*returnColumnSizes)[row];
			res[row][col] = malloc(sizeof(char) * (lenStr + 1));
			strcpy(res[row][col], strs[i]);
			(*returnColumnSizes)[row]++;
		}
		/*key������*/
		else
		{
			/*����Hash����*/
			add(hashTable, curStr, strsSize, *returnSize);
			/*����һ��*/
			res[*returnSize] = malloc(sizeof(char *) * strsSize);
			res[*returnSize][0] = malloc(sizeof(char) * (lenStr + 1));
			strcpy(res[*returnSize][0], strs[i]);
			(*returnColumnSizes)[*returnSize] = 1;
			(*returnSize)++;
		}
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/