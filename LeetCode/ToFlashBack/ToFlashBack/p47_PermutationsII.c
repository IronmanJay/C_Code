#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*待查数组长度*/
int numslen;

/*结果数组长度、指针*/
int resSize;

/*结果数组列长度*/
int* resColumnSize;

/*路经数组长度、指针*/
int pathSize;

/*对数组进行排序的排序规则*/
int p47_PermutationsII_compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void p47_PermutationsII_dfs(int* nums, int** res, int* path, bool* used, int depth)
{
	/*如果当前递归的深度和数组长度一样说明找到了一个排列，加入结果数组，并将此次递归返回*/
	if (depth == numslen)
	{
		/*这里不能直接将path赋值给res，因为直接加入是地址引用，必须拷贝一下数据值才能得到结果*/
		int* temp = malloc(sizeof(int) * pathSize);
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
		/*只有当前元素没有使用过才可以做第一个开始的排列，否则跳出当前循环*/
		if (used[i])
		{
			continue;
		}
		/*i > 0是为了保证nums[i - 1]有意义*/
		/*nums[i] == nums[i - 1]目的是剪枝的前提是这个数字是重复的*/
		/*!used[i-1]是为了保证前一个重复的数字未使用过，这样说明之前回溯过已经使用了，如果再使用就会产生重复结果，这也就是剪枝的条件*/
		if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
		{
			continue;
		}
		/*将当前元素加入排列路经*/
		path[pathSize++] = nums[i];
		/*将当前元素置为已经使用*/
		used[i] = true;
		/*以当前元素开始递归遍历所有可能的结果，深度+1*/
		p47_PermutationsII_dfs(nums, res, path, used, depth + 1);
		/*从这里开始回溯，回到上一个状态，也就是当前元素还没有被使用*/
		used[i] = false;
		/*并将已经得到的结果元素删除，重置状态*/
		pathSize--;
	}
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	/*获取待查数组长度*/
	numslen = numsSize;
	/*结果数组长度、指针，路经数组长度、指针*/
	resSize = pathSize = 0;
	/*创建结果数组*/
	int** res = malloc(sizeof(int*) * 1001);
	/*创建列数组*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*创建路经数组*/
	int path[2001];
	/*判断对应元素是否使用过*/
	bool* used = (bool*)malloc(sizeof(bool)*numslen);
	memset(used, 0, numslen * sizeof(bool));
	/*只有排序了才能剪枝，升序降序都可以，遇到重复数并且前一个重复的未使用就剪枝*/
	qsort(nums, numsSize, sizeof(int), p47_PermutationsII_compare);
	/*开始搜索*/
	p47_PermutationsII_dfs(nums, res, path, used, 0);
	/*返回数组长度*/
	*returnSize = resSize;
	/*返回数组列长度*/
	*returnColumnSizes = resColumnSize;
	/*返回结果*/
	return res;
}

/*主函数省略*/
