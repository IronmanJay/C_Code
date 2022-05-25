#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int uniquePaths(int m, int n)
{
	/*��̬���飬���ÿһ��λ�ÿ��Ե���Ĳ�ͬ·����Ŀ*/
	int** dp = (int **)malloc(sizeof(int *)*m);
	for (int i = 0; i < m; i++)
	{
		dp[i] = (int*)calloc(n, sizeof(int));
	}
	/*����ÿһ��λ��*/
	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			/*��Ϊ��Ŀ˵������ֻ�������߻��������ߣ����Ե�һ�к͵�һ�е�����Ԫ��λ��ֻ����ֱ�ߵ����ô���Ե���Ĳ�ͬ·����Ŀ����1*/
			if (x == 0 || y == 0)
			{
				dp[x][y] = 1;
			}
			/*ͬ����Ϊ��Ŀ˵������ֻ�������߻��������ߣ���Ϊ֮ǰ��״̬�Ѿ����£���ô���˵�һ�к͵�һ�е�����λ�ö����Ը���Ϊ�������������Ŀɵ���Ĳ�ͬ·����Ŀ֮��*/
			else
			{
				dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
			}
		}
	}
	/*���ն�̬���鵽�����½Ǿ͸���Ϊ���в�ͬ·������Ŀ*/
	return dp[m - 1][n - 1];
}

/*������ʡ��*/