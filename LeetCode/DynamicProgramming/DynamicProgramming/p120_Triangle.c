#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*���ؽ�Сֵ*/
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
	/*����*/
	if (triangleSize == 0 || triangle == NULL)
	{
		return 0;
	}
	/*�Ե����Ͽ�ʼ�滮*/
	for (int i = triangleSize - 2; i >= 0; i--)
	{
		/*�ڼ��о��м�������������ǰ�е�������*/
		for (int j = 0; j <= i; j++)
		{
			/*����Ҫ���ҳ�����������ֵ*/
			triangle[i][j] = p120_Triangle_Min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
		}
	}
	/*���ؽ��*/
	return triangle[0][0];
}

/*������ʡ��*/
