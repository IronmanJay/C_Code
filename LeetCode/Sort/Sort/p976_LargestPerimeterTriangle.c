#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*��������*/
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
	/*�пշ���*/
	if (A == NULL || ASize < 3)
	{
		return 0;
	}
	/*�������������*/
	quickSort(A, 0, ASize - 1);
	/*�Ӻ���ǰ�Ƚϣ������������֮�ʹ��ڵ����߼��ɣ���Ϊ�Ӻ���ǰ�ң�����ֻҪ������ľ�������*/
	for (int i = ASize - 1; i >= 2; i--)
	{
		if (A[i] < A[i - 1] + A[i - 2])
		{
			return A[i] + A[i - 1] + A[i - 2];
		}
	}
	return 0;
}

/*������ʡ��*/