#include<stdio.h>

int hIndex(int* citations, int citationsSize)
{
	int len = citationsSize;
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (citations[mid] >= len - mid)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return citations[right] >= len - right ? len - right : 0;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/