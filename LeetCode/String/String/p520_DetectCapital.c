#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool detectCapitalUse(char * word)
{
	/*��д��ĸ����*/
	int upWord = 0;
	/*Сд��ĸ����*/
	int lowWord = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] - 'a' < 0)
		{
			upWord++;
		}
		else
		{
			lowWord++;
		}
	}
	/*���ȫ�Ǵ�д��ĸ����ȫ��Сд��ĸ��������ĸ��д����ȫΪСд��ĸ������Ҫ�󣬷���true*/
	if (upWord == strlen(word) || lowWord == strlen(word) || (upWord == 1 && word[0] < 'a'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	/*������ʡ��*/
}