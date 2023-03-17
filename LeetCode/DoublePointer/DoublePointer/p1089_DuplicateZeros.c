#include<stdio.h>

void duplicateZeros(int* arr, int arrSize)
{
	int i = -1;
	int top = 0;
	while (top < arrSize)
	{
		i++;
		if (arr[i] != 0)
		{
			top++;
		}
		else
		{
			top += 2;
		}
	}
	int j = arrSize - 1;
	if (top == arrSize + 1)
	{
		arr[j] = 0;
		i--;
		j--;
	}
	while (j >= 0)
	{
		arr[j] = arr[i];
		j--;
		if (arr[i] == 0)
		{
			arr[j] = arr[i];
			j--;
		}
		i--;
	}
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/