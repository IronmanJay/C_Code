#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char * reverseWords(char * s)
{
	int len = strlen(s);
	char* stack = (char*)malloc(sizeof(char) * (len + 1));
	char* res = (char*)malloc(sizeof(char) * (len + 1));
	int resIndex = 0;
	int top = 0;
	bool flag = false;
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			stack[top++] = s[i];
			flag = true;
		}
		else if (s[i] == ' ' && flag == true)
		{
			while (top > 0)
			{
				res[resIndex++] = stack[--top];
			}
			res[resIndex++] = ' ';
			flag = false;
		}
	}
	if (top == 0)
	{
		resIndex--;
	}
	while (top > 0)
	{
		res[resIndex++] = stack[--top];
	}
	res[resIndex] = '\0';
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/