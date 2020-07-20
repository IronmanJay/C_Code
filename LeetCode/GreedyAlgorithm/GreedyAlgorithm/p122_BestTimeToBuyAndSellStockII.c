#include<stdio.h>
#include<stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
	/*结果*/
	int res = 0;
	/* 只要后一天比前一天能赚钱，就是后一天的值>前一天的值，也就是利润>0，这就是局部最优解，贪心算法的思想*/
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] > prices[i - 1])
		{
			res += prices[i] - prices[i - 1];
		}
	}
	/*返回结果*/
	return res;
}

int main(void)
{
	/*主函数省略*/
}
