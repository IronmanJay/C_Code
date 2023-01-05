#include<stdio.h>

double myPow(double x, int n)
{
	double res = 1.0;
	if (n < 0)
	{
		x = 1 / x;
	}
	while (n != 0)
	{
		if ((n & 1) == 1)
		{
			res = res * x;
		}
		x = x * x;
		n = n / 2;
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/