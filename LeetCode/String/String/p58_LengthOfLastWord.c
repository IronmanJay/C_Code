#include<stdio.h>
#include<stdlib.h>

int lengthOfLastWord(char * s)
{
	int res = 0;
	int index = strlen(s) - 1;
	while (index >= 0 && s[index] == ' ')
	{
		index--;
	}
	while (index >= 0 && s[index] != ' ')
	{
		res++;
		index--;
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/