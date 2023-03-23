#include<stdio.h>
#include<stdint.h>

int hammingWeight(uint32_t n)
{
	int res = 0;
	while (n != 0)
	{
		res++;
		n &= n - 1;
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/