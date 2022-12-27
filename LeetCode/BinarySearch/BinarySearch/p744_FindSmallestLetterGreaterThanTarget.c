#include<stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target)
{
	int left = 0;
	int right = lettersSize - 1;
	if (letters[right] <= target)
	{
		return letters[0];
	}
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (letters[mid] <= target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return letters[left];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/