#include<stdio.h>
#include<stdbool.h>

bool isParlindrome(char *s, int i, int j)
{
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

bool validPalindrome(char * s)
{
	int left = 0;
	int right = strlen(s) - 1;
	while (left < right)
	{
		if (s[left] != s[right])
		{
			return isParlindrome(s, left + 1, right) || isParlindrome(s, left, right - 1);
		}
		left++;
		right--;
	}
	return true;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/