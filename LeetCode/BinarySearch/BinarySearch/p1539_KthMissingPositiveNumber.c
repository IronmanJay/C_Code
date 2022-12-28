#include<stdio.h>

int findKthPositive(int* arr, int arrSize, int k)
{
	if (arr[0] > k)
	{
		return k;
	}
	int left = 0;
	int right = arrSize;
	while (left < right)
	{
		int mid = (left + right) / 2;
		int dif = arr[mid] - mid - 1;
		if (dif >= k)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return k - (arr[left - 1] - (left - 1) - 1) + arr[left - 1];
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/