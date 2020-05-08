#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"dict.h"
#include<stdio.h>
#include<string.h>

#define SIZE 111104


int main(void)
{
	GetWord();
	//接收用户输入的单词
	char* word = (char*)malloc(sizeof(char) * 1024);
	//根据单词提供翻译
	char* trans = (char*)malloc(sizeof(char) * 1024);
	int idx = 0;
	while (1)
	{
		memset(word, 0, 1024);
		memset(trans, 0, 1024);
		scanf("%s", word);
		//出口
		if (!strcmp(word, "comm=exit"))
		{
			break;
		}
		//格式化 大小写转换
		if (*word >= 'a'&&*word <= 'z')
		{
			idx = *word - 'a';
		}
		else {
			idx = 26;
		}
		if (!SearchWord(word, trans,idx))
		{
			printf("%s\n", trans);
		}
		else {
			printf("未找到该单词\n");
		}
	}
	free(word);
	free(trans);
	DestorySpace();
	getchar();
}
 
//函数声明
int GetWord()
{
	FILE* fp = fopen("D:/d.txt", "r");
	if (!fp)
	{
		printf("加载单词库失败\n");
		return -1;
	}

	list = (dict*)malloc((sizeof(dict) * SIZE));
	index = (pos*)malloc(sizeof(pos) * 27);
	char flag = 'a';
	index[0].start = 0;
	index[0].end = 0;
	int idx = 0;
	int i = 0;
	char* temp = (char*)malloc(sizeof(char) * 1024);
	while (!feof(fp))
	{
		memset(temp, 0, 1024);
		fgets(temp, 1024, fp);
		//开辟单词的堆空间
		//去掉\n
		temp[strlen(temp) - 1] = 0;
		list[i].word = (char*)malloc(sizeof(char)*strlen(temp));
		//将单词放在指定堆空间中
		strcpy(list[i].word, &temp[1]);
		//创建索引
		if (idx != 26)
		{
			if (list[i].word[0] == flag)
			{
				index[idx].end++;
			}
			else {
				idx++;
				index[idx].start = index[idx - 1].end;
				index[idx].end = index[idx - 1].end + 1;
				flag++;
			}
		}
		memset(temp, 0, 1024);
		fgets(temp, 1024, fp);
		//去掉\n
		temp[strlen(temp) - 1] = 0;
		list[i].trans = (char*)malloc(sizeof(char)*strlen(temp) - 5);
		strcpy(list[i].trans, &temp[6]);
		i++;
	}
	//释放和关闭文件
	free(temp);
	fclose(fp);
	//记录中文的索引
	index[26].start = index[25].end;
	index[26].end = SIZE;
	return i;
}

//查找单词
int SearchWord(char * word, char * trans, int idx)
{
	if (!word || !trans)
	{
		printf("输入发生异常\n");
		return -1;
	}

	for (int i = index[idx].start; i < index[idx].end; i++)
	{
		//如果用户输入的单词和词库中相同返回单词对应的翻译
		if (!strcmp(word, list[i].word))
		{
			strcpy(trans, list[i].trans);
			return 0;
		}
	}

	return 1;
}

//销毁数据
void DestorySpace()
{
	if (list == NULL)
	{
		return;
	}
	if (index)
	{
		free(index);
		index = NULL;
	}
	for (int i = 0; i < SIZE; i++)
	{
		free(list[i].word);
		free(list[i].trans);
	}
	free(list);
	list = NULL;
}
