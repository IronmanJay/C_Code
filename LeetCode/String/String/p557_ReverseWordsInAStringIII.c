#include<stdio.h>
#include<string.h>

char * reverseWordsIII(char * s)
{
	int index = 0;
	int len = strlen(s);
	while (index < len)
	{
		int left = index;
		while (index < len && s[index] != ' ')
		{
			index++;
		}
		int right = index - 1;
		while (left < right)
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
		index++;
	}
	return s;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/