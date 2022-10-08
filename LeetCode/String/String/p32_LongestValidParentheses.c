#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int longestValidParentheses(char * s)
{
	int stack[30001] = { 0 };
	int top = -1;
	int res = 0;
	int start = -1;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '(')
		{
			stack[++top] = i;
		}
		else
		{
			if (top != -1)
			{
				top--;
				if (top != -1)
				{
					res = fmax(res, i - stack[top]);
				}
				else
				{
					res = fmax(res, i - start);
				}
			}
			else
			{
				start = i;
			}
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/