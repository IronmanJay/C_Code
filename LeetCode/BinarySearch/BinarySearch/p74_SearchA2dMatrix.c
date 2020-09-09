#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
	/*�пշ���*/
	if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0)
	{
		return false;
	}
	/*�ֱ�������������*/
	int row = matrixSize - 1;
	int col = matrixColSize[0] - 1;
	/*posͨ���Ƚ�ÿһ�е����һ��Ԫ��ȷ��Ŀ��ֵ����һ��*/
	int pos = 0;
	/*�ֱ����ÿһ�����һ��Ԫ�أ��ҵ�Ŀ��ֵ����һ��*/
	for (int i = 0; i <= row; i++)
	{
		/*�����ǰ�е����һ��Ԫ�غ�Ŀ��ֵ��ȣ�ֱ�ӷ���true*/
		if (matrix[i][col] == target)
		{
			return true;
		}
		/*�����ǰ�е����һ��Ԫ��С��Ŀ��ֵ��˵��Ŀ��ֵ�ڵ�ǰ��֮�����*/
		else if (matrix[i][col] < target)
		{
			pos = i + 1;
		}
	}
	/*������Ϊ�˷�ֹÿһ�ж�û�з�������������Խ�磬˵���������鶼û�з���������*/
	if (pos > row)
	{
		return false;
	}
	/*��Ȼ�ҵ���Ŀ��ֵ����һ�У������Ķ��ֲ��Ҽ���*/
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
	/*�����û�ҵ�������false*/
	return false;
}

/*������ʡ��*/
