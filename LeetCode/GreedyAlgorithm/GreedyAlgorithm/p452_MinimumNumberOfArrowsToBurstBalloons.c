#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*�Զ������򣬰��ն�ά�������һ��Ԫ�ش�С��������*/
int compare_p452_MinimumNumberOfArrowsToBurstBalloons(const void *a, const void *b)
{
	/*a>b������ֵ���������У���С����*/
	return (*(int**)a)[1] > (*(int**)b)[1] ? 1 : -1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
	/*�пշ���*/
	if (pointsSize < 1)
	{
		return 0;
	}
	/*�Զ�ά���鰴������ֱ������λ�ô�С��������Ŀ�����ҳ��ص�����*/
	qsort(points, pointsSize, sizeof(int) * 2, compare_p452_MinimumNumberOfArrowsToBurstBalloons);
	/*�ӵ�һ������ʼ��*/
	int temp = points[0][1];
	/*��Ҫһ����*/
	int res = 1;
	/*��ʼ����*/
	for (int i = 1; i < pointsSize; i++)
	{
		/*�������һ���ص����䣬˵�����ǵڶ���������Ҫ��һ���������Լ���+1��������µ�ǰ�������λ��Ϊ��ǰλ��*/
		if (temp < points[i][0])
		{
			res++;
			temp = points[i][1];
		}
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
