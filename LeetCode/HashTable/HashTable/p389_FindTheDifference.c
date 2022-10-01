#include<stdio.h>
#include<string.h>

char findTheDifference(char * s, char * t)
{
	char map[26] = { 0 };
	for (int i = 0; i < strlen(t); i++)
	{
		map[t[i] - 'a']++;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		map[s[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (map[i] != 0)
		{
			return i + 'a';
		}
	}
	return NULL;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/