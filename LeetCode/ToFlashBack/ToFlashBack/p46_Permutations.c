#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*待查数组长度*/
int numslen;

/*结果数组长度、指针*/
int resSize;

/*结果数组列长度*/
int* resColumnSize;

/*路径数组长度、指针*/
int pathSize;

void p46_Permutations_dfs(int* nums, int** res, int* path, bool* used, int depth)
{
	/*如果当前递归的深度和数组长度一样说明找到了一个排列，加入结果数组，并将此次递归返回*/
	if (depth == numslen)
	{
		/*这里不能直接将path赋值给res，因为直接加入是地址引用，必须拷贝一下数据值才能得到结果*/
		int* temp = (int*)malloc(sizeof(int)*pathSize);
		for (int i = 0; i < pathSize; i++)
		{
			temp[i] = path[i];
		}
		res[resSize] = temp;
		resColumnSize[resSize++] = pathSize;
		return;
	}
	/*遍历数组中每一个元素为第一个开始的排列*/
	for (int i = 0; i < numslen; i++)
	{
		/*只有当前元素没有使用过才可以做第一个开始的排列*/
		if (!used[i])
		{
			/*将当前元素加入排列路径*/
			path[pathSize++] = nums[i];
			/*将当前元素置为已经使用*/
			used[i] = true;
			/*以当前元素开始递归遍历所有可能的结果，深度+1*/
			p46_Permutations_dfs(nums, res, path, used, depth + 1);
			/*从这里开始回溯，回到上一个状态，也就是当前元素还没有被使用*/
			used[i] = false;
			/*并将已经得到的结果元素删除，重置状态*/
			pathSize--;
		}
	}
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	/*获取待查数组长度*/
	numslen = numsSize;
	/*结果数组长度、指针，路径数组长度、指针*/
	resSize = pathSize = 0;
	/*创建结果数组*/
	int** res = malloc(sizeof(int*) * 1001);
	/*创建列数组*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*创建路径数组*/
	int path[2001];
	/*判断对应元素是否使用过*/
	bool* used = (bool*)malloc(sizeof(bool)*numslen);
	memset(used, 0, numslen * sizeof(bool));
	/*开始搜索*/
	p46_Permutations_dfs(nums, res, path, used, 0);
	/*返回数组长度*/
	*returnSize = resSize;
	/*返回数组列长度*/
	*returnColumnSizes = resColumnSize;
	/*返回结果*/
	return res;
}

/*主函数省略*/
