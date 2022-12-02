#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * countAndSay(int n)
{
	char* str = (char*)malloc(sizeof(char) * 5001);
	str[0] = '1';
	str[1] = '\0';
	for (int i = 2; i <= n; i++)
	{
		char* temp = (char*)malloc(sizeof(char) * 5001);
		int pos = 0;
		for (int j = 0; j < strlen(str); j++)
		{
			int count = 1;
			while (str[j + 1] && str[j] == str[j + 1])
			{
				count++;
				j++;
			}
			temp[pos++] = count + 48;
			temp[pos++] = str[j];
			temp[pos] = '\0';
		}
		strcpy(str, temp);
	}
	return str;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/