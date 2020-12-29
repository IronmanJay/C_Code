#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*�������鳤��*/
int candidatesLen;

/*������鳤�ȡ�ָ��*/
int resSize;

/*��������г���*/
int* resColumnSize;

/*·�����鳤�ȡ�ָ��*/
int pathSize;

/*���������������������*/
int p40_CombinationSumII_compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void p40_CombinationSumII_dfs(int* candidates, int** res, int* path, int target, int begin)
{
	/*targetΪ����˵����ǰ����ʧ�ܣ�û�ҵ���Ӧ����ϣ���Ϊ��������ֻ��������0������Ӧ�����*/
	if (target < 0)
	{
		return;
	}
	/*targetΪ0˵����������Ӧ����ϣ�������·�����뵽����У�������*/
	if (target == 0)
	{
		int* temp = malloc(sizeof(int)*pathSize);
		for (int i = 0; i < pathSize; i++)
		{
			temp[i] = path[i];
		}
		res[resSize] = temp;
		resColumnSize[resSize++] = pathSize;
		return;
	}
	/*����֮ǰ�ù������ֲ������ã����������ظ������*/
	for (int i = begin; i < candidatesLen; i++)
	{
		/*��Ϊ�������򣬵�ǰ��Ԫ�ض�����������������Ŀ϶���������*/
		if (target - candidates[i] < 0)
		{
			continue;
		}
		/*����������Ϊͬһ���·��ѡ�񣬱���[1,2,2,2,5]�У�ѡ�˵�һ��2�����[1,2]����һ��2����һѡ��Ҳ��2�������������֦����Ϊѡ�����ͻ���[1,2]*/
		if (i > begin && candidates[i] == candidates[i - 1])
		{
			continue;
		}
		/*����ǰ�����ӵ�·����*/
		path[pathSize++] = candidates[i];
		/*��ʼ������ÿ�δ�ͷ��ʼ������ΪԪ�ز������ظ�ʹ�ã�������һ�ֵ������i+1��target��������������ȥ��ǰ��������ֵ������������0˵���ҵ��˶�Ӧ�����*/
		p40_CombinationSumII_dfs(candidates, res, path, target - candidates[i], i + 1);
		/*ÿ�ҵ�һ��·��������״̬*/
		pathSize--;
	}
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
	/*��ȡ�������鳤��*/
	candidatesLen = candidatesSize;
	/*������鳤�ȡ�ָ�룬·�����鳤�ȡ�ָ��*/
	resSize = pathSize = 0;
	/*�����������*/
	int** res = malloc(sizeof(int*) * 1001);
	/*����������*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*����·������*/
	int path[2001];
	/*ֻ�н����������ȥ�أ�������*/
	qsort(candidates, candidatesSize, sizeof(int), p40_CombinationSumII_compare);
	/*��ʼ����*/
	p40_CombinationSumII_dfs(candidates, res, path, target, 0);
	/*�������鳤��*/
	*returnSize = resSize;
	/*���������г���*/
	*returnColumnSizes = resColumnSize;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
