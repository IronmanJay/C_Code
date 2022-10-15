#include<stdio.h>
#include<string.h>

int compareStr(char* text, int i, int j, int len)
{
	if ((j + len) > strlen(text))
	{
		return -1;
	}
	return strncmp(&text[i], &text[j], len);
}

int longestDecomposition(char * text)
{
	int len = strlen(text);
	int k = 0;
	int subLen = 1;
	for (int i = 0; i < len; i += subLen)
	{
		subLen = 1;
		for (int j = len - 1 - i; j >= 0; j--)
		{
			if ((text[i] == text[j]) && (compareStr(text, i, j, subLen) == 0))
			{
				k++;
				break;
			}
			subLen++;
		}
	}
	return k;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/