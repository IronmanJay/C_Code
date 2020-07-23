#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�Զ���Ƚ���*/
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
	/*ʹ���Զ���Ƚ����Զ�ά����������򣬰�����߽�����������������Ȱ�ǰ���ж��ٸ�������˸�����*/
	qsort(people, peopleSize, sizeof(int *), Compare);
	/*����������*/
	int **res = (int **)malloc(sizeof(int *) * peopleSize);
	*returnSize = peopleSize;
	/*��Ϊ�����ӵ�������ڸ߸��ӵ����ǿ������ģ�����ֻ��Ҫ�����Ӧ����λ�ü��ɣ������������ǰ���ж��ٸ�������˸ߵ�ֵ*/
	for (int i = 0; i < peopleSize; i++)
	{
		int k = people[i][1];
		memmove(&res[k + 1], &res[k], (i - k) * sizeof(int *));
		res[k] = (int *)malloc(sizeof(int) * 2);
		res[k][0] = people[i][0];
		res[k][1] = people[i][1];
	}
	/*���巵�ص�����*/
	*returnColumnSizes = (int *)malloc(sizeof(int) * peopleSize);
	for (int i = 0; i < peopleSize; i++)
	{
		(*returnColumnSizes)[i] = 2;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
