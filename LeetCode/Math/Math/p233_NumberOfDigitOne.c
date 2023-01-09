#include<stdio.h>

int countDigitOne(int n)
{
	long mul = 1;
	int res = 0;
	while (mul <= n)
	{
		res += (n / (mul * 10)) * mul + fmin(fmax(n % (mul * 10) - mul + 1, 0), mul);
		mul *= 10;
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/