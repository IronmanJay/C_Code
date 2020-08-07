#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int quickSortPartition(int* arr, int left, int right)
{
	/*ȡ���һ��Ԫ��Ϊ����ֵ*/
	int pivot = arr[right];
	/*������ָ�룬����ָ��С������ֵ�����һ��Ԫ�ص���һ��Ԫ��λ��*/
	int l = left;
	/*���α�������������*/
	for (int r = left; r < right; r++)
	{
		/*�����ǰԪ��ֵС������ֵ����ô������ǰС������ֵ��ֵ�ʹ�������ֵ��ֵ��λ�ã�Ŀ����������С������ֵ��ֵ������ǰ��*/
		if (arr[r] < pivot)
		{
			int temp = arr[r];
			arr[r] = arr[l];
			arr[l] = temp;
			/*����ָ��С������ֵ�����һ��Ԫ�ص���һ��Ԫ��λ��*/
			l++;
		}
	}
	/*�������֮����Ϊ����ѡȡ������ֵ����������һ��Ԫ�أ���������Ҫ��������l�����棬Ҳ����С������ֵ�����һ��Ԫ�ص���һ��Ԫ��λ�ã����н���*/
	int temp = arr[right];
	arr[right] = arr[l];
	arr[l] = temp;
	/*��Ϊ������Ҫ����ֵ��λ�ã����Է�����ָ�룬��ǰ��ָ���������ֵ��λ��*/
	return l;
}

void quickSort(int* arr, int left, int right, int k)
{
	/*�����ָ����ڵ�����ָ�룬˵���ݹ����*/
	if (left >= right)
	{
		return;
	}
	/*�����������ҵ�����ֵ��λ��*/
	int partitionIndex = quickSortPartition(arr, left, right);
	/*�������ֵ�±����k��˵�����ȫ��С��k��Ԫ�أ�ֱ�ӷ��ؼ���*/
	if (partitionIndex == k)
	{
		return;
	}
	/*���kС������ֵ�±꣬˵���������ߣ�����ݹ�*/
	if (k < partitionIndex)
	{
		quickSort(arr, left, partitionIndex - 1, k);
	}
	/*���k��������ֵ�±꣬˵��������ұߣ����ҵݹ�*/
	if (k > partitionIndex)
	{
		quickSort(arr, partitionIndex + 1, right, k);
	}
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize)
{
	/*���п������򣬽����ݹ�֮���Ѿ�������������������ֵ��ߵ�Ԫ�ؾ��ǽ��������*/
	quickSort(arr, 0, arrSize - 1, k);
	*returnSize = k;
	/*�½����飬���ս��*/
	int* res = (int *)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
	{
		res[i] = arr[i];
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/