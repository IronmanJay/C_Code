#include<stdio.h>
#include<limits.h>

int thirdMax(int* nums, int numsSize)
{
	long a = LONG_MIN;
	long b = LONG_MIN;
	long c = LONG_MIN;
	for (int i = 0; i < numsSize; i++)
	{
		int num = nums[i];
		if (num > a)
		{
			c = b;
			b = a;
			a = num;
		}
		else if (a > num && num > b)
		{
			c = b;
			b = num;
		}
		else if (b > num && num > c)
		{
			c = num;
		}
	}
	return c == LONG_MIN ? (int)a : (int)c;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/