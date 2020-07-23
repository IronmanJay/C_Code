#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*自定义比较器*/
int Compare(const void *a, const void *b)
{
	int *peopleA = *(int **)a;
	int *peopleB = *(int **)b;
	int hA = peopleA[0];
	int hB = peopleB[0];
	int kA = peopleA[1];
	int kB = peopleB[1];
	if (hA == hB)
	{
		return kA - kB;
	}
	return hB - hA;
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
	/*使用自定义比较器对二维数组进行排序，按照身高降序，如果两个人身高相等按前面有多少个比这个人高升序*/
	qsort(people, peopleSize, sizeof(int *), Compare);
	/*定义结果数组*/
	int **res = (int **)malloc(sizeof(int *) * peopleSize);
	*returnSize = peopleSize;
	/*因为矮个子的人相对于高个子的人是看不见的，所以只需要插入对应索引位置即可，这个索引就是前面有多少个比这个人高的值*/
	for (int i = 0; i < peopleSize; i++)
	{
		int k = people[i][1];
		memmove(&res[k + 1], &res[k], (i - k) * sizeof(int *));
		res[k] = (int *)malloc(sizeof(int) * 2);
		res[k][0] = people[i][0];
		res[k][1] = people[i][1];
	}
	/*定义返回的列数*/
	*returnColumnSizes = (int *)malloc(sizeof(int) * peopleSize);
	for (int i = 0; i < peopleSize; i++)
	{
		(*returnColumnSizes)[i] = 2;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
