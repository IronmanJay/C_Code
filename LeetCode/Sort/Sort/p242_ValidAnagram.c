#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*�Զ���������򣬴�С��������*/
int p242_ValidAnagram_cmp(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}

bool isAnagram(char * s, char * t)
{
	/*������Ȳ���ȣ�������һ���ַ���Ϊ�գ�˵��������Ч����ĸ��λ�ʣ�����false����*/
	if (strlen(s) != strlen(t) || !s || !t)
	{
		return false;
	}
	/*ʹ��C����qsort�Զ��������������*/
	qsort(s, strlen(s), sizeof(char), p242_ValidAnagram_cmp);
	qsort(t, strlen(t), sizeof(char), p242_ValidAnagram_cmp);
	/*�������֮�������ַ�������ȣ�˵������Ч����ĸ��λ�ʣ��������֮����ȣ�Ҳ����ζ�������ַ�����������ĸ����ͬ��˵����������Ч����ĸ��λ��*/
	return strcmp(s, t) == 0;
}

/*������ʡ��*/
