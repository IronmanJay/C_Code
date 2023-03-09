#include<stdio.h>
#include<math.h>

int candy(int* ratings, int ratingsSize)
{
	int* left = (int*)malloc(sizeof(int) * ratingsSize);
	int* right = (int*)malloc(sizeof(int) * ratingsSize);
	left[0] = 1;
	for (int i = 1; i < ratingsSize; i++)
	{
		left[i] = ratings[i] > ratings[i - 1] ? left[i - 1] + 1 : 1;
	}
	right[ratingsSize - 1] = 1;
	for (int i = ratingsSize - 2; i >= 0; i--)
	{
		right[i] = ratings[i] > ratings[i + 1] ? right[i + 1] + 1 : 1;
	}
	int res = 0;
	for (int i = 0; i < ratingsSize; i++)
	{
		res += fmax(left[i], right[i]);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/