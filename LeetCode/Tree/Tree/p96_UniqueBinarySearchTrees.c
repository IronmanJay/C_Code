#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int numTrees(int n)
{
	/*结果数组，长度+1是因为数组从0开始*/
	int *dp = (int *)calloc(n + 1, sizeof(int));
	/*空树个数为1*/
	dp[0] = 1;
	/*一个结点的树个数为1*/
	dp[1] = 1;
	/*从两个结点的树开始遍历，遍历到n个结点的不同树的情况*/
	for (int i = 2; i <= n; i++)
	{
		/*内层循环是每个结点数对应的二叉搜索树，从1~n分别作为不同root的不同二叉搜索树*/
		for (int j = 1; j <= i; j++)
		{
			/*动态方程的意思就是从左边没有结点到左边全是结点的组合情况*/
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	/*返回结果*/
	return dp[n];
}

/*主函数省略*/
