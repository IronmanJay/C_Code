#include<stdio.h>

double findMaxAverage(int* nums, int numsSize, int k)
{
	int tempSum = 0;
	for (int i = 0; i < k; i++)
	{
		tempSum += nums[i];
	}
	int sum = tempSum;
	for (int i = k; i < numsSize; i++)
	{
		sum = sum - nums[i - k] + nums[i];
		tempSum = fmax(tempSum, sum);
	}
	return (double)tempSum / k;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/
int main()
{
	return 0;
}