#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int lengthOfLongestSubstring(char * s)
{
	int start = 0;
	int end = 0;
	int len = 0;
	int res = 0;
	while (end < strlen(s))
	{
		for (int index = start; index < end; index++)
		{
			if (s[index] == s[end])
			{
				start = index + 1;
				len = end - start;
				break;
			}
		}
		len++;
		end++;
		res = Max(len, res);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/