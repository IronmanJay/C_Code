#include<stdio.h>

int rangeBitwiseAnd(int left, int right)
{
	int count = 0;
	while (left != right)
	{
		left >>= 1;
		right >>= 1;
		count++;
	}
	return left << count;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/