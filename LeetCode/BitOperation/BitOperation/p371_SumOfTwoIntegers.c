#include<stdio.h>

int getSum(int a, int b)
{
	while (b != 0)
	{
		int carry = ((unsigned int)(a & b)) << 1;
		a ^= b;
		b = carry;
	}
	return a;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/