#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isVowels(char s)
{
	if (s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U')
	{
		return true;
	}
	return false;
}

char * reverseVowels(char * s)
{
	int left = 0;
	int right = strlen(s) - 1;
	while (left < right)
	{
		while (left < right && !isVowels(s[left]))
		{
			left++;
		}
		while (left < right && !isVowels(s[right]))
		{
			right--;
		}
		if (left < right)
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
	}
	return s;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/