#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	/*�пշ���false*/
	if (matrix == NULL || matrixRowSize == 0 || matrixColSize == 0)
	{
		return false;
	}
	/*��ȡ����*/
	int row = matrixRowSize;
	/*��ȡ����*/
	int col = matrixColSize;
	/*�������������һ�п�ʼ*/
	int rowIndex = row - 1;
	/*���������ӵ�һ�п�ʼ*/
	int colIndex = 0;
	/*ɨ������*/
	while (rowIndex >= 0 && colIndex < col)
	{
		/*������½�Ԫ�ص���Ŀ��ֵ����true*/
		if (target == matrix[rowIndex][colIndex])
		{
			return true;
		}
		/*���Ŀ��ֵС�����½�Ԫ�أ�˵��Ŀ��ֵ����һ������Ԫ�ض�С����Ϊ���½�Ԫ������һ����С��Ԫ��*/
		else if (target < matrix[rowIndex][colIndex])
		{
			/*��ôĿ��ֵ�϶�������һ�У���ʼɨ����һ��*/
			rowIndex--;
		}
		/*���Ŀ��ֵ�������½�Ԫ�أ�˵��Ŀ��ֵ����һ������Ԫ�ض�����Ϊ���½�Ԫ������һ������Ԫ��*/
		else
		{
			/*��ôĿ��ֵ�϶�������һ�У���ʼɨ����һ��*/
			colIndex++;
		}
	}
	/*���û�ҵ�����false*/
	return false;
}

/*������ʡ��*/
