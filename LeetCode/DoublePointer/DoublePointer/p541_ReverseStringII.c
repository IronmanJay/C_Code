#include<stdio.h>
#include<string.h>

#define min(a,b) (a > b ? b : a)

void reverse(char* s, int left, int right)
{
	while (left < right)
	{
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
}

char * reverseStr(char * s, int k)
{
	int len = strlen(s);
	for (int i = 0; i < len; i += (2 * k))
	{
		reverse(s, i, min(i + k, len) - 1);
	}
	return s;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/