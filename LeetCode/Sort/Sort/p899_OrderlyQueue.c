#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int compare_p899_OrderlyQueue(char* a, char* b)
{
	return *(char *)a - *(char *)b;
}

char * orderlyQueue(char * s, int k)
{
	int len = strlen(s);
	if (k == 1)
	{
		char* str = (char *)malloc(sizeof(char) * (len + 1));
		strcpy(str, s);
		for (int i = 1; i < len; i++)
		{
			char c = s[0];
			for (int j = 0; j < len - 1; j++)
			{
				s[j] = s[j + 1];
			}
			s[len - 1] = c;
			if (strcmp(s, str) < 0)
			{
				strcpy(str, s);
			}
		}
		return str;
	}
	else
	{
		qsort(s, len, sizeof(char), compare_p899_OrderlyQueue);
		return s;
	}
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/