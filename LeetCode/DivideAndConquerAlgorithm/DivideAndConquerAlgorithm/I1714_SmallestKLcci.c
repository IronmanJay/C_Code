#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int quickSortPartition(int* arr, int left, int right)
{
	/*取最后一个元素为中枢值*/
	int pivot = arr[right];
	/*定义左指针，总是指向小于中枢值的最后一个元素的下一个元素位置*/
	int l = left;
	/*依次遍历，进行排序*/
	for (int r = left; r < right; r++)
	{
		/*如果当前元素值小于中枢值，那么交换当前小于中枢值的值和大于中枢值的值的位置，目的是让所有小于中枢值的值都放在前面*/
		if (arr[r] < pivot)
		{
			int temp = arr[r];
			arr[r] = arr[l];
			arr[l] = temp;
			/*总是指向小于中枢值的最后一个元素的下一个元素位置*/
			l++;
		}
	}
	/*排序完毕之后，因为我们选取的中枢值是数组的最后一个元素，所以我们要把它放在l的右面，也就是小于中枢值的最后一个元素的下一个元素位置，进行交换*/
	int temp = arr[right];
	arr[right] = arr[l];
	arr[l] = temp;
	/*因为我们需要中枢值的位置，所以返回左指针，当前左指针就是中枢值的位置*/
	return l;
}

void quickSort(int* arr, int left, int right, int k)
{
	/*如果左指针大于等于右指针，说明递归结束*/
	if (left >= right)
	{
		return;
	}
	/*进行排序且找到中枢值的位置*/
	int partitionIndex = quickSortPartition(arr, left, right);
	/*如果中枢值下标等于k，说明左边全是小于k的元素，直接返回即可*/
	if (partitionIndex == k)
	{
		return;
	}
	/*如果k小于中枢值下标，说明结果在左边，向左递归*/
	if (k < partitionIndex)
	{
		quickSort(arr, left, partitionIndex - 1, k);
	}
	/*如果k大于中枢值下标，说明结果在右边，向右递归*/
	if (k > partitionIndex)
	{
		quickSort(arr, partitionIndex + 1, right, k);
	}
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize)
{
	/*进行快速排序，结束递归之后已经将整个数组变成了中枢值左边的元素就是结果的样子*/
	quickSort(arr, 0, arrSize - 1, k);
	*returnSize = k;
	/*新建数组，接收结果*/
	int* res = (int *)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
	{
		res[i] = arr[i];
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/