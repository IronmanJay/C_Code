#include<stdio.h>
#include<stdbool.h>

bool backspaceCompare(char * s, char * t)
{
	int topS = -1;
	int topT = -1;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != '#')
		{
			s[++topS] = s[i];
		}
		else
		{
			if (topS != -1)
			{
				topS--;
			}
			else
			{
				topS = -1;
			}
		}
	}
	for (int i = 0; i < strlen(t); i++)
	{
		if (t[i] != '#')
		{
			t[++topT] = t[i];
		}
		else
		{
			if (topT != -1)
			{
				topT--;
			}
			else
			{
				topT = -1;
			}
		}
	}
	if (topS != topT)
	{
		return false;
	}
	else
	{
		for (int i = 0; i <= topS; i++)
		{
			if (s[i] != t[i])
			{
				return false;
			}
		}
	}
	return true;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/