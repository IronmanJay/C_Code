#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool I1009_SortedMatrixSearchLcci_searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
	/*判空返回*/
	if (matrix == NULL || matrixSize == 0 || matrixColSize == 0)
	{
		return false;
	}
	/*分别获取行数和列数*/
	int row = matrixSize;
	int col = matrixColSize;
	/*行的开始位置从第一行*/
	int rowIndex = 0;
	/*列的开始位置从最后一列*/
	int colIndex = col - 1;
	/*从右上角开始比较*/
	while (rowIndex < row && colIndex >= 0)
	{
		/*因为二维数组从上到下升序，从左到右升序，所以如果当前值大于目标值，说明目标值需要向左查找，所以列索引-1*/
		if (matrix[rowIndex][colIndex] > target)
		{
			colIndex--;
		}
		/*因为二维数组从上到下升序，从左到右升序，所以如果当前值小于目标值，说明目标值需要向下查找，所以行索引+1*/
		else if (matrix[rowIndex][colIndex] < target)
		{
			rowIndex++;
		}
		/*如果找到返回true*/
		else
		{
			return true;
		}
	}
	/*如果没找到返回false*/
	return false;
}

/*主函数省略*/
