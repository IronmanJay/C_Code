#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*自定义排序，按照二维数组最后一个元素从小到大排序*/
int compare_p435_NonOverlappingIntervals(const void *a, const void *b)
{
	return (*(int**)a)[1] - (*(int**)b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
	/*判空返回*/
	if (intervalsSize == 0)
	{
		return 0;
	}
	/*对二维数组以最后一个元素从小到大排序，目的是找到不重叠区间*/
	qsort(intervals, intervalsSize, sizeof(int) * 2, compare_p435_NonOverlappingIntervals);
	/*第一个小区间设为第一个不重叠区间，count表示不重叠区间的个数*/
	int count = 1;
	int temp = intervals[0][1];
	/*开始遍历*/
	for (int i = 1; i < intervalsSize; i++)
	{
		/*如果是不重叠区间，那么不重叠区间的小区间个数+1，并且更新整个不重叠区间的尾部位置，以便下一次比较，如果遇到重叠区间直接跳过*/
		if (temp <= intervals[i][0])
		{
			count++;
			temp = intervals[i][1];
		}
	}
	/*全部的小区间减去全部的小区间组成的不重叠区间的个数就是需要去掉的小区间*/
	return intervalsSize - count;
}

/*主函数省略*/
