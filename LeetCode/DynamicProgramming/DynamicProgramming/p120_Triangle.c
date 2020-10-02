#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*返回较小值*/
int p120_Triangle_Min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
	/*特判*/
	if (triangleSize == 0 || triangle == NULL)
	{
		return 0;
	}
	/*自底向上开始规划*/
	for (int i = triangleSize - 2; i >= 0; i--)
	{
		/*第几行就有几个数，遍历当前行的所有数*/
		for (int j = 0; j <= i; j++)
		{
			/*按照要求找出符合条件的值*/
			triangle[i][j] = p120_Triangle_Min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
		}
	}
	/*返回结果*/
	return triangle[0][0];
}

/*主函数省略*/
