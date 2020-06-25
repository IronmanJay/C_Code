#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MAX(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int maxArea(int* height, int heightSize)
{
	int leftIndex = 0;
	int rightIndex = heightSize - 1;
	int res = 0;
	while (leftIndex < rightIndex)
	{
		res = height[leftIndex] < height[rightIndex] ? MAX(res, (rightIndex - leftIndex) * height[leftIndex++]) : MAX(res, (rightIndex - leftIndex) * height[rightIndex--]);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/