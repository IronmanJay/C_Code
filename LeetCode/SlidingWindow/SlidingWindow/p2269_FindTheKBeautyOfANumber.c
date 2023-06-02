#include<stdio.h>
#include<stdlib.h>

int divisorSubstrings(int num, int k)
{
	int res = 0;
	int* temp_num = (int*)malloc(sizeof(int) * 10);
	int i, count, temp;
	for (i = 0, temp = num; temp > 0; temp /= 10, i++)
	{
		temp_num[i] = temp % 10;
	}
	count = i - k + 1;
	for (i = 0; i < count; i++)
	{
		int sum = 0;
		for (int j = 0; j < k; j++)
		{
			sum *= 10;
			sum += temp_num[i + k - j - 1];
		}
		if (sum != 0 && num % sum == 0)
		{
			res++;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/