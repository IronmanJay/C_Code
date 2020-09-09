#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool I1009_SortedMatrixSearchLcci_searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
	/*�пշ���*/
	if (matrix == NULL || matrixSize == 0 || matrixColSize == 0)
	{
		return false;
	}
	/*�ֱ��ȡ����������*/
	int row = matrixSize;
	int col = matrixColSize;
	/*�еĿ�ʼλ�ôӵ�һ��*/
	int rowIndex = 0;
	/*�еĿ�ʼλ�ô����һ��*/
	int colIndex = col - 1;
	/*�����Ͻǿ�ʼ�Ƚ�*/
	while (rowIndex < row && colIndex >= 0)
	{
		/*��Ϊ��ά������ϵ������򣬴������������������ǰֵ����Ŀ��ֵ��˵��Ŀ��ֵ��Ҫ������ң�����������-1*/
		if (matrix[rowIndex][colIndex] > target)
		{
			colIndex--;
		}
		/*��Ϊ��ά������ϵ������򣬴������������������ǰֵС��Ŀ��ֵ��˵��Ŀ��ֵ��Ҫ���²��ң�����������+1*/
		else if (matrix[rowIndex][colIndex] < target)
		{
			rowIndex++;
		}
		/*����ҵ�����true*/
		else
		{
			return true;
		}
	}
	/*���û�ҵ�����false*/
	return false;
}

/*������ʡ��*/
