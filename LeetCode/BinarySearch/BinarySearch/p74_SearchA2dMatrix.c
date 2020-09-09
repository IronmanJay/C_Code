#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
	/*判空返回*/
	if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0)
	{
		return false;
	}
	/*分别获得行数和列数*/
	int row = matrixSize - 1;
	int col = matrixColSize[0] - 1;
	/*pos通过比较每一行的最后一个元素确定目标值在哪一行*/
	int pos = 0;
	/*分别遍历每一行最后一个元素，找到目标值在哪一行*/
	for (int i = 0; i <= row; i++)
	{
		/*如果当前行的最后一个元素和目标值相等，直接返回true*/
		if (matrix[i][col] == target)
		{
			return true;
		}
		/*如果当前行的最后一个元素小于目标值，说明目标值在当前行之后的行*/
		else if (matrix[i][col] < target)
		{
			pos = i + 1;
		}
	}
	/*这里是为了防止每一行都没有符合条件的数组越界，说明整个数组都没有符合条件的*/
	if (pos > row)
	{
		return false;
	}
	/*既然找到了目标值在哪一行，正常的二分查找即可*/
	int left = 0;
	int right = col;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (matrix[pos][mid] == target)
		{
			return true;
		}
		else if (matrix[pos][mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	/*如果都没找到，返回false*/
	return false;
}

/*主函数省略*/
