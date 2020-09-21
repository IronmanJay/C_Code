#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*待查数组长度*/
int candidatesLen;

/*结果数组长度、指针*/
int resSize;

/*结果数组列长度*/
int* resColumnSize;

/*路经数组长度、指针*/
int pathSize;

void dfs(int* candidates, int begin, int target, int** res, int* path)
{
	/*target为负数说明当前搜索失败，没找到对应的组合，因为做减法，只有最后减到0才有相应的组合*/
	if (target < 0)
	{
		return;
	}
	/*target为0说明搜索到对应的组合，将这条路经加入到结果中，并返回*/
	if (target == 0)
	{
		int* temp = malloc(sizeof(int) * pathSize);
		for (int i = 0; i < pathSize; ++i)
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
		/*将当前结点添加到路径中*/
		path[pathSize++] = candidates[i];
		/*开始搜索，每次从头开始减，因为元素可以重复使用，所以下一轮的起点还是i，target由于做减法，减去当前遍历到的值，最后如果减到0说明找到了对应的组合*/
		dfs(candidates, i, target - candidates[i], res, path);
		/*每找到一个路经，重置状态*/
		pathSize--;
	}
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
	/*获取待查数组长度*/
	candidatesLen = candidatesSize;
	/*结果数组长度、指针，路经数组长度、指针*/
	resSize = pathSize = 0;
	/*创建结果数组*/
	int** res = malloc(sizeof(int*) * 1001);
	/*创建列数组*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*创建路经数组*/
	int path[2001];
	/*开始搜索*/
	dfs(candidates, 0, target, res, path);
	/*返回数组长度*/
	*returnSize = resSize;
	/*返回数组列长度*/
	*returnColumnSizes = resColumnSize;
	/*返回结果*/
	return res;
}

/*主函数省略*/
int main(void)
{

}
