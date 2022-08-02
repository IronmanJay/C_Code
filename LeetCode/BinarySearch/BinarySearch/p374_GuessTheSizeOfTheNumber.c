#include<stdio.h>

int guess(int num)
{
	int pick = 6;
	if (num == pick)
	{
		return 0;
	}
	else if (num < pick)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int guessNumber(int n)
{
	int left = 1;
	int right = n;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int pick = guess(mid);
		if (pick == 0)
		{
			return mid;
		}
		else if (pick == 1)
		{
			left = mid + 1;
		}
		else if (pick == -1)
		{
			right = mid - 1;
		}
	}
	return 0;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/