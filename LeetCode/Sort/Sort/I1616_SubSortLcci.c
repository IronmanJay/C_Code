#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*自定义排序*/
int I1616_SubSortLcci_compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int* subSort(int* array, int arraySize, int* returnSize)
{
	/*复制一个数组，用于后续比较*/
	int* temp = (int *)malloc(sizeof(int) * arraySize);
	memcpy(temp, array, sizeof(int) * arraySize);
	/*对原数组进行排序*/
	qsort(array, arraySize, sizeof(int), I1616_SubSortLcci_compare);
	/*定义结果数组*/
	int* res = (int *)malloc(sizeof(int) * 2);
	res[0] = -1;
	res[1] = -1;
	/*开始遍历对比对应位置的元素*/
	for (int i = 0; i < arraySize; i++)
	{
		/*只有原数组和复制的数组不对应的位置就是发生排序改变的位置*/
		if (temp[i] != array[i])
		{
			/*第一个遇到的不对应的位置就是开始位置*/
			if (res[0] == -1)
			{
				res[0] = i;
			}
			/*第二个遇到的不对应的位置就是结束位置*/
			res[1] = i;
		}
	}
	/*返回结果*/
	*returnSize = 2;
	return res;
}