#include<stdio.h>
#include<stdlib.h>

char * convert(char * s, int numRows)
{
	int len = strlen(s);
	if (len == 0 || numRows == 1)
	{
		return s;
	}
	char* res = (char*)malloc(sizeof(int) * (len + 1));
	res[len] = '\0';
	int index = 0;
	int t = 2 * numRows - 2;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (j % t == i || j % t == t - i)
			{
				res[index++] = s[j];
			}
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/