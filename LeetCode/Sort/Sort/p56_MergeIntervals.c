#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>

/*比较器*/
int p56_MergeIntervals_compare(void *a, void *b)
{
	int *arr1 = *(int **)a;
	int *arr2 = *(int **)b;
	if (arr1[0] == arr2[0])
	{
		return arr1[1] - arr2[1];
	}
	return arr1[0] - arr2[0];
}

/*合并区间*/
int** merge(int** intervals, int intervalsSize, int *intervalsColSize, int* returnSize, int** returnColumnSizes)
{
	*returnSize = 0;
	if (intervalsSize < 1)
	{
		return NULL;
	}
	qsort(intervals, intervalsSize, sizeof(int *), p56_MergeIntervals_compare);
	int **result = (int **)malloc(sizeof(int *)*intervalsSize);
	int flag = 0;
	int start = -1;
	int end = -1;
	for (int i = 0; i < intervalsSize; i++)
	{
		if (i + 1 < intervalsSize && intervals[i + 1][0] >= intervals[i][0] && intervals[i + 1][0] <= intervals[i][1])
		{
			intervals[i + 1][0] = intervals[i][0];
			intervals[i + 1][1] = intervals[i][1] > intervals[i + 1][1] ? intervals[i][1] : intervals[i + 1][1];
		}
		else
		{
			result[*returnSize] = (int *)malloc(sizeof(int) * 2);
			result[*returnSize][0] = intervals[i][0];
			result[*returnSize][1] = intervals[i][1];
			(*returnSize)++;
		}
	}
	*returnColumnSizes = intervalsColSize;
	return result;
}

/*主函数省略*/
