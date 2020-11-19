#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*�Զ������򣬰��ն�ά�������һ��Ԫ�ش�С��������*/
int compare_p435_NonOverlappingIntervals(const void *a, const void *b)
{
	return (*(int**)a)[1] - (*(int**)b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
	/*�пշ���*/
	if (intervalsSize == 0)
	{
		return 0;
	}
	/*�Զ�ά���������һ��Ԫ�ش�С��������Ŀ�����ҵ����ص�����*/
	qsort(intervals, intervalsSize, sizeof(int) * 2, compare_p435_NonOverlappingIntervals);
	/*��һ��С������Ϊ��һ�����ص����䣬count��ʾ���ص�����ĸ���*/
	int count = 1;
	int temp = intervals[0][1];
	/*��ʼ����*/
	for (int i = 1; i < intervalsSize; i++)
	{
		/*����ǲ��ص����䣬��ô���ص������С�������+1�����Ҹ����������ص������β��λ�ã��Ա���һ�αȽϣ���������ص�����ֱ������*/
		if (temp <= intervals[i][0])
		{
			count++;
			temp = intervals[i][1];
		}
	}
	/*ȫ����С�����ȥȫ����С������ɵĲ��ص�����ĸ���������Ҫȥ����С����*/
	return intervalsSize - count;
}

/*������ʡ��*/
