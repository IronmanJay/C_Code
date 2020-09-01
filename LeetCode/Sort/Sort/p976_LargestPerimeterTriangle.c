#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*快速排序*/
void quickSort(int* arr, int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int left = low;
	int right = high;
	int key = arr[low];
	while (left < right)
	{
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = key;
	quickSort(arr, low, left - 1);
	quickSort(arr, left + 1, high);
}

int largestPerimeter(int* A, int ASize)
{
	/*判空返回*/
	if (A == NULL || ASize < 3)
	{
		return 0;
	}
	/*对数组进行排序*/
	quickSort(A, 0, ASize - 1);
	/*从后向前比较，如果发现两边之和大于第三边即可，因为从后向前找，所以只要有满足的就是最大的*/
	for (int i = ASize - 1; i >= 2; i--)
	{
		if (A[i] < A[i - 1] + A[i - 2])
		{
			return A[i] + A[i - 1] + A[i - 2];
		}
	}
	return 0;
}

/*主函数省略*/