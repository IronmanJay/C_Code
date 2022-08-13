#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char * removeKdigits(char * num, int k)
{
	int len = strlen(num);
	char* stack = (char*)malloc(sizeof(char) * (len + 1));
	int top = 0;
	for (int i = 0; i < len; i++)
	{
		while (top > 0 && stack[top] > num[i] && k)
		{
			top--;
			k--;
		}
		stack[++top] = num[i];
	}
	top -= k;
	char* res = (char*)malloc(sizeof(char) * (len + 1));
	int resIndex = 0;
	bool isLeadingZero = true;
	for (int i = 1; i <= top; i++)
	{
		if (isLeadingZero && stack[i] == '0')
		{
			continue;
		}
		isLeadingZero = false;
		res[resIndex++] = stack[i];
	}
	if (resIndex == 0)
	{
		res[0] = '0', res[1] = '\0';
	}
	else
	{
		res[resIndex] = '\0';
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/