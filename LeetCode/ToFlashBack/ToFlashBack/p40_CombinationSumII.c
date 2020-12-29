#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*待查数组长度*/
int candidatesLen;

/*结果数组长度、指针*/
int resSize;

/*结果数组列长度*/
int* resColumnSize;

/*路径数组长度、指针*/
int pathSize;

/*对数组进行排序的排序规则*/
int p40_CombinationSumII_compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void p40_CombinationSumII_dfs(int* candidates, int** res, int* path, int target, int begin)
{
	/*target为负数说明当前搜索失败，没找到对应的组合，因为做减法，只有最后减到0才有相应的组合*/
	if (target < 0)
	{
		return;
	}
	/*target为0说明搜索到对应的组合，将这条路径加入到结果中，并返回*/
	if (target == 0)
	{
		int* temp = malloc(sizeof(int)*pathSize);
		for (int i = 0; i < pathSize; i++)
		{
			temp[i] = path[i];
		}
		res[resSize] = temp;
		resColumnSize[resSize++] = pathSize;
		return;
	}
	/*这里之前用过的数字不能再用，否则会出现重复的组合*/
	for (int i = begin; i < candidatesLen; i++)
	{
		/*因为数组升序，当前的元素都不满足条件，后面的肯定更不满足*/
		if (target - candidates[i] < 0)
		{
			continue;
		}
		/*这里可以理解为同一层的路径选择，比如[1,2,2,2,5]中，选了第一个2，变成[1,2]，第一个2的下一选项也是2，所以在这里剪枝，因为选它，就还是[1,2]*/
		if (i > begin && candidates[i] == candidates[i - 1])
		{
			continue;
		}
		/*将当前结点添加到路径中*/
		path[pathSize++] = candidates[i];
		/*开始搜索，每次从头开始减，因为元素不可以重复使用，所以下一轮的起点是i+1，target由于做减法，减去当前遍历到的值，最后如果减到0说明找到了对应的组合*/
		p40_CombinationSumII_dfs(candidates, res, path, target - candidates[i], i + 1);
		/*每找到一个路径，重置状态*/
		pathSize--;
	}
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
	/*获取待查数组长度*/
	candidatesLen = candidatesSize;
	/*结果数组长度、指针，路径数组长度、指针*/
	resSize = pathSize = 0;
	/*创建结果数组*/
	int** res = malloc(sizeof(int*) * 1001);
	/*创建列数组*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*创建路径数组*/
	int path[2001];
	/*只有进行排序才能去重，且升序*/
	qsort(candidates, candidatesSize, sizeof(int), p40_CombinationSumII_compare);
	/*开始搜索*/
	p40_CombinationSumII_dfs(candidates, res, path, target, 0);
	/*返回数组长度*/
	*returnSize = resSize;
	/*返回数组列长度*/
	*returnColumnSizes = resColumnSize;
	/*返回结果*/
	return res;
}

/*主函数省略*/
