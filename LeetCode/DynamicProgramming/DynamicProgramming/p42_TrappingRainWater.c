#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int trap(int* height, int heightSize)
{
	int* dpLeft = (int*)malloc(sizeof(int) * heightSize);
	dpLeft[0] = height[0];
	int* dpRight = (int*)malloc(sizeof(int) * heightSize);
	dpRight[heightSize - 1] = height[heightSize - 1];
	int water = 0;
	for (int i = 1; i < heightSize; i++)
	{
		dpLeft[i] = max(dpLeft[i - 1], height[i]);
	}
	for (int i = heightSize - 2; i >= 0; i--)
	{
		dpRight[i] = max(dpRight[i + 1], height[i]);
	}
	for (int i = 1; i < heightSize - 1; i++)
	{
		int level = min(dpLeft[i], dpRight[i]);
		water += max(0, level - height[i]);
	}
	return water;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/