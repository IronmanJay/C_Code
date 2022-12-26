#include<stdio.h>
#include<stdlib.h>

int mySqrt_o72_TakeASquareRoot(int x)
{
	if (x == 0)
	{
		return 0;
	}
	long left = 1;
	long right = x;
	while (left < right)
	{
		long mid = left + (right - left + 1) / 2;
		if (mid * mid <= x)
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/