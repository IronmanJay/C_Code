#include<stdio.h>
#include<string.h>

int findLUSlength(char * a, char * b)
{
	if (strcmp(a, b) == 0)
	{
		return -1;
	}
	return strlen(a) > strlen(b) ? strlen(a) : strlen(b);
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/
