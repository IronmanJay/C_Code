#include<stdio.h>
#include<stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
	/*���*/
	int res = 0;
	/* ֻҪ��һ���ǰһ����׬Ǯ�����Ǻ�һ���ֵ>ǰһ���ֵ��Ҳ��������>0������Ǿֲ����Ž⣬̰���㷨��˼��*/
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] > prices[i - 1])
		{
			res += prices[i] - prices[i - 1];
		}
	}
	/*���ؽ��*/
	return res;
}

int main(void)
{
	/*������ʡ��*/
}
