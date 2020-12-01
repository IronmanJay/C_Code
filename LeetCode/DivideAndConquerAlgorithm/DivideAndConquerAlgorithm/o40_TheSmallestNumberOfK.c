#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*��������������Ԫ��*/
void swap_o40_TheSmallestNumberOfK(int* arr, int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

/*��������*/
int partition_o40_TheSmallestNumberOfK(int* arr, int left, int right)
{
	/*ѡȡ�����Ԫ��Ϊ����ֵ����������*/
	int pivot = arr[left];
	/*���ڵ�������ֵֵ������*/
	int leftEnd = left;
	/*��������ֵС��Ԫ�ض��ŵ�����ֵ�����*/
	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] < pivot)
		{
			leftEnd++;
			swap_o40_TheSmallestNumberOfK(arr, i, leftEnd);
		}
	}
	/*������ֵ�������м�λ��*/
	swap_o40_TheSmallestNumberOfK(arr, left, leftEnd);
	/*��������ֵ����*/
	return leftEnd;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	/*��ȡ���鳤��*/
	int len = arrSize;
	/*�������*/
	int* res = (int*)malloc(sizeof(int)*arrSize);
	/*�жϱ߽�ֵ����*/
	if (k == 0 || k > len)
	{
		*returnSize = 0;
		return res;
	}
	/*��������k��������������-1*/
	int target = k - 1;
	int left = 0;
	int right = len - 1;
	while (true)
	{
		/*��������ֵ����*/
		int pIndex = partition_o40_TheSmallestNumberOfK(arr, left, right);
		/*ǡ������ֵ��������Ŀ��������˵��ǰk�����Ѿ�����С��������ֱ�ӷ��ؼ���*/
		if (pIndex == target)
		{
			for (int i = 0; i < k; i++)
			{
				res[i] = arr[i];
			}
			*returnSize = k;
			return res;
		}
		/*�������ֵ����С��Ŀ����������Ҫ���Ҽ�������*/
		else if (pIndex < target)
		{
			left = pIndex + 1;
		}
		/*�������ֵ��������Ŀ����������Ҫ�����������*/
		else
		{
			right = pIndex - 1;
		}
	}
}

/*������ʡ��*/
