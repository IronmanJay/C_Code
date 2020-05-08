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
	//�����û�����ĵ���
	char* word = (char*)malloc(sizeof(char) * 1024);
	//���ݵ����ṩ����
	char* trans = (char*)malloc(sizeof(char) * 1024);
	int idx = 0;
	while (1)
	{
		memset(word, 0, 1024);
		memset(trans, 0, 1024);
		scanf("%s", word);
		//����
		if (!strcmp(word, "comm=exit"))
		{
			break;
		}
		//��ʽ�� ��Сдת��
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
			printf("δ�ҵ��õ���\n");
		}
	}
	free(word);
	free(trans);
	DestorySpace();
	getchar();
}
 
//��������
int GetWord()
{
	FILE* fp = fopen("D:/d.txt", "r");
	if (!fp)
	{
		printf("���ص��ʿ�ʧ��\n");
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
		//���ٵ��ʵĶѿռ�
		//ȥ��\n
		temp[strlen(temp) - 1] = 0;
		list[i].word = (char*)malloc(sizeof(char)*strlen(temp));
		//�����ʷ���ָ���ѿռ���
		strcpy(list[i].word, &temp[1]);
		//��������
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
		//ȥ��\n
		temp[strlen(temp) - 1] = 0;
		list[i].trans = (char*)malloc(sizeof(char)*strlen(temp) - 5);
		strcpy(list[i].trans, &temp[6]);
		i++;
	}
	//�ͷź͹ر��ļ�
	free(temp);
	fclose(fp);
	//��¼���ĵ�����
	index[26].start = index[25].end;
	index[26].end = SIZE;
	return i;
}

//���ҵ���
int SearchWord(char * word, char * trans, int idx)
{
	if (!word || !trans)
	{
		printf("���뷢���쳣\n");
		return -1;
	}

	for (int i = index[idx].start; i < index[idx].end; i++)
	{
		//����û�����ĵ��ʺʹʿ�����ͬ���ص��ʶ�Ӧ�ķ���
		if (!strcmp(word, list[i].word))
		{
			strcpy(trans, list[i].trans);
			return 0;
		}
	}

	return 1;
}

//��������
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
