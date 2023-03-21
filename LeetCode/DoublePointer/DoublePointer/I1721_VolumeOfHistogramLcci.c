#include<stdio.h>
#include<limits.h>

int trap(int* height, int heightSize)
{
	int res = 0;
	int left = 0;
	int right = heightSize - 1;
	int leftMax = 0;
	int rightMax = 0;
	while (left <= right)
	{
		if (leftMax < rightMax)
		{
			res += fmax(0, leftMax - height[left]);
			leftMax = fmax(leftMax, height[left]);
			left++;
		}
		else
		{
			res += fmax(0, rightMax - height[right]);
			rightMax = fmax(rightMax, height[right]);
			right--;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/