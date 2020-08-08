#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	/*判空返回false*/
	if (matrix == NULL || matrixRowSize == 0 || matrixColSize == 0)
	{
		return false;
	}
	/*获取行数*/
	int row = matrixRowSize;
	/*获取列数*/
	int col = matrixColSize;
	/*行索引，从最后一行开始*/
	int rowIndex = row - 1;
	/*列索引，从第一列开始*/
	int colIndex = 0;
	/*扫描数组*/
	while (rowIndex >= 0 && colIndex < col)
	{
		/*如果左下角元素等于目标值返回true*/
		if (target == matrix[rowIndex][colIndex])
		{
			return true;
		}
		/*如果目标值小于左下角元素，说明目标值比这一行所有元素都小，因为左下角元素是这一行最小的元素*/
		else if (target < matrix[rowIndex][colIndex])
		{
			/*那么目标值肯定不在这一行，开始扫描上一行*/
			rowIndex--;
		}
		/*如果目标值大于左下角元素，说明目标值比这一列所有元素都大，因为左下角元素是这一列最大的元素*/
		else
		{
			/*那么目标值肯定不在这一列，开始扫描下一列*/
			colIndex++;
		}
	}
	/*如果没找到返回false*/
	return false;
}

/*主函数省略*/
