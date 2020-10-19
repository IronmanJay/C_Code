#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes)
{
	/*����ת��֮����о���ԭ�����У�����ת��֮����о���ԭ������*/
	int** res = (int **)malloc(sizeof(int*) * *AColSize);
	for (int i = 0; i < *AColSize; i++)
	{
		res[i] = (int *)malloc(sizeof(int)*ASize);
	}
	/*����a[i][j] = a[j][i]����ת�ö��������ֵ����*/
	for (int i = 0; i < *AColSize; i++)
	{
		for (int j = 0; j < ASize; j++)
		{
			res[i][j] = A[j][i];
		}
	}
	/*���÷��ص��к��е�����*/
	*returnSize = *AColSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * * AColSize);
	for (int i = 0; i < *AColSize; i++)
	{
		(*returnColumnSizes)[i] = ASize;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
