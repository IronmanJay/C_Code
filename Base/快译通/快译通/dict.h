#pragma once

typedef struct DICT
{
	char* word;
	char* trans;
}dict;

typedef struct POSTION
{
	int start;
	int end;
}pos;

dict *list = NULL;
//��¼�����±�
pos* index = NULL;

int GetWord();

int SearchWord(char* word,char* trans, int idx);

void DestorySpace();