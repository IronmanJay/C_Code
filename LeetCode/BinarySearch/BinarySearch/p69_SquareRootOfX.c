#include<stdio.h>

int mySqrt(int x)
{
	int left = 0;
	int right = x;
	int res = -1;
	while (left <= right)
	{
		long mid = left + (right - left) / 2;
		if (mid * mid <= x)
		{
			res = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/