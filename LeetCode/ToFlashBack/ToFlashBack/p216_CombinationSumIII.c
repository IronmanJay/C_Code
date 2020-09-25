#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*结果数组长度、指针*/
int resSize;

/*结果数组列长度*/
int* resColumnSize;

/*路径数组长度、指针*/
int pathSize;

void p216_CombinationSumIII_dfs(int k, int n, int** res, int* path, int index)
{
	/*如果目标值n最后减的小于0说明当前和后面的数字都大于目标值，剪枝，因为从1~9有序排列*/
	if (n < 0)
	{
		return;
	}
	/*如果目标值n等于0并且k等于0说明找到一个成功组合的，并且符合要求长度，不再需要新的元素，那么添加这条路径即可*/
	if (k == 0 && n == 0)
	{
		int* temp = (int*)malloc(sizeof(int) * pathSize);
		for (int i = 0; i < pathSize; i++)
		{
			temp[i] = path[i];
		}
		res[resSize] = temp;
		resColumnSize[resSize++] = pathSize;
		return;
	}
	/*这里之前用过的数字不能再用，否则会出现重复的组合，并且因为从1~9有序排列，所以遍历到9*/
	for (int i = index; i <= 9; i++)
	{
		/*将当前结点添加到路径中*/
		path[pathSize++] = i;
		/*开始递归搜索*/
		/*k-1就是因为路径加入了一个元素，那么所需长度也就减少一个*/
		/*n-i就是做减法，最后目标值n等于0就是成功找到一个组合*/
		/*i+1就是下次递归不能选取当前值，避免重复*/
		p216_CombinationSumIII_dfs(k - 1, n - i, res, path, i + 1);
		/*这里回溯，重置状态*/
		pathSize--;
	}
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
{
	/*结果数组长度、指针，路径数组长度、指针*/
	resSize = pathSize = 0;
	/*创建结果数组*/
	int** res = malloc(sizeof(int*) * 1001);
	/*创建列数组*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*创建路径数组*/
	int path[2001];
	/*开始搜索*/
	p216_CombinationSumIII_dfs(k, n, res, path, 1);
	/*返回数组长度*/
	*returnSize = resSize;
	/*返回数组列长度*/
	*returnColumnSizes = resColumnSize;
	/*返回结果*/
	return res;
}

/*主函数省略*/
