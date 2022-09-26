#include<stdio.h>

int firstUniqChar(char * s)
{
	int map[26] = { 0 };
	for (int i = 0; i < strlen(s); i++)
	{
		map[s[i] - 'a']++;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		if (map[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/