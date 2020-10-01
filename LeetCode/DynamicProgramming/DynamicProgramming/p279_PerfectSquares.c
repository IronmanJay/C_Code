#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*���ؽ�Сֵ*/
int p279_PerfectSquares_Min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

int numSquares(int n)
{
	/*��̬����*/
	int* dp = (int*)malloc(sizeof(int)*(n + 1));
	/*��һ������0��û�����ĺ���0��������0*/
	dp[0] = 0;
	/*��������*/
	for (int i = 1; i <= n; i++)
	{
		/*��������1+1+1+����+1*/
		dp[i] = i;
		/*��ÿһ��״̬�����Ž�*/
		for (int j = 1; i - j * j >= 0; j++)
		{
			dp[i] = p279_PerfectSquares_Min(dp[i], dp[i - j * j] + 1);
		}
	}
	/*���ؽ��*/
	return dp[n];
}

/*������ʡ��*/
