#include<stdio.h>
#include<limits.h>

int maxProduct(int* nums, int numsSize)
{
	int res = INT_MIN;
	int tempMax = 1;
	int tempMin = 1;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] < 0)
		{
			int temp = tempMax;
			tempMax = tempMin;
			tempMin = temp;
		}
		tempMax = fmax(tempMax * nums[i], nums[i]);
		tempMin = fmin(tempMin * nums[i], nums[i]);
		res = fmax(res, tempMax);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/