#include<stdio.h>

#define MAX_ 10 /*数组个数*/
#define RADIX 10 /*整型排序*/
#define KEYNUM 10 /*关键字个数，这里为整型位数*/

/*打印结果*/
void Show(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*找到num的从低到高的第pos位的数据*/
int GetNumInPos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
	{
		temp *= 10;
	}
	return (num / temp) % 10;
}

/*pDataArray:无序数组*/
/*iDataNum:无序数组个数*/
void RadixSort(int* pDataArray, int iDataNum)
{
	int *radixArrays[RADIX]; /*分别为0~9的序列空间*/
	for (int i = 0; i < 10; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
		radixArrays[i][0] = 0; /*index为0处记录这组数据的个数*/
	}
	for (int pos = 1; pos <= KEYNUM; pos++) /*从个位开始到十位*/
	{
		for (int i = 0; i < iDataNum; i++) /*分配过程*/
		{
			int num = GetNumInPos(pDataArray[i], pos); /*获得当前位的值*/
			int index = ++radixArrays[num][0]; /*当前位置的元素个数+1*/
			radixArrays[num][index] = pDataArray[i]; /*将当前元素赋值给这个桶，index为0处记录当前元素个数*/
		}
		for (int i = 0, j = 0; i < RADIX; i++) /*收集过程*/
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
			{
				pDataArray[j++] = radixArrays[i][k]; /*将数字从桶中取出来*/
			}
			radixArrays[i][0] = 0; /*将当前桶的数字个数复位，供下次遍历时使用*/
		}
	}
}

/*基数排序*/
int mainRadixSort(void)
{

	/*测试数据*/
	int arr_test[MAX_] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
	/*排序前数组序列*/
	printf("排序前：");
	Show(arr_test, MAX_);
	RadixSort(arr_test, MAX_);
	/*排序后数组序列*/
	printf("排序后：");
	Show(arr_test, MAX_);

	getchar();

}
