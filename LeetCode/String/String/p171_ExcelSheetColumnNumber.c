#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int titleToNumber(char * columnTitle)
{
	int res = 0;
	for (int i = 0; i < strlen(columnTitle); i++)
	{
		int num = columnTitle[i] - 'A' + 1;
		res = res * 26 + num;
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/