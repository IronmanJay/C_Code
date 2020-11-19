#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*自定义排序，按照二维数组最后一个元素从小到大排序*/
int compare_p452_MinimumNumberOfArrowsToBurstBalloons(const void *a, const void *b)
{
	/*a>b返回正值，升序排列，从小到大*/
	return (*(int**)a)[1] > (*(int**)b)[1] ? 1 : -1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
	/*判空返回*/
	if (pointsSize < 1)
	{
		return 0;
	}
	/*对二维数组按照气球直径结束位置从小到大排序，目的是找出重叠区间*/
	qsort(points, pointsSize, sizeof(int) * 2, compare_p452_MinimumNumberOfArrowsToBurstBalloons);
	/*从第一个气球开始射*/
	int temp = points[0][1];
	/*需要一个箭*/
	int res = 1;
	/*开始遍历*/
	for (int i = 1; i < pointsSize; i++)
	{
		/*如果不在一个重叠区间，说明这是第二块区域需要另一个箭，所以箭数+1，另外更新当前箭的射出位置为当前位置*/
		if (temp < points[i][0])
		{
			res++;
			temp = points[i][1];
		}
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
