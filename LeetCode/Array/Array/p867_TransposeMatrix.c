#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes)
{
	/*矩阵转置之后的行就是原来的列，矩阵转置之后的列就是原来的行*/
	int** res = (int **)malloc(sizeof(int*) * *AColSize);
	for (int i = 0; i < *AColSize; i++)
	{
		res[i] = (int *)malloc(sizeof(int)*ASize);
	}
	/*按照a[i][j] = a[j][i]矩阵转置定义遍历赋值即可*/
	for (int i = 0; i < *AColSize; i++)
	{
		for (int j = 0; j < ASize; j++)
		{
			res[i][j] = A[j][i];
		}
	}
	/*设置返回的行和列的数量*/
	*returnSize = *AColSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * * AColSize);
	for (int i = 0; i < *AColSize; i++)
	{
		(*returnColumnSizes)[i] = ASize;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
