#include<stdio.h>
#include<stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
	int res = 0;
	for (int i = 0; i < flowerbedSize; i++)
	{
		if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i + 1 == flowerbedSize || flowerbed[i + 1] == 0))
		{
			flowerbed[i] = 1;
			res++;
		}
	}
	return res >= n;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/