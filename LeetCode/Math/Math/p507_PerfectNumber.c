#include<stdio.h>
#include<stdbool.h>

bool checkPerfectNumber(int num)
{
	if (num == 1)
	{
		return false;
	}
	int res = 1;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			res += i;
			if (i * i < num)
			{
				res += num / i;
			}
		}
	}
	return res == num;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/