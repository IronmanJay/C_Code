#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isSubsequence(char * s, char * t)
{
	int lenT = strlen(t);
	int lenS = strlen(s);
	int indexS = 0;
	for (int i = 0; i < lenT; i++)
	{
		if (t[i] == s[indexS])
		{
			indexS++;
		}
	}
	return indexS == lenS;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/