#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*������鳤�ȡ�ָ��*/
int resSize;

/*��������г���*/
int* resColumnSize;

/*·�����鳤�ȡ�ָ��*/
int pathSize;

void p216_CombinationSumIII_dfs(int k, int n, int** res, int* path, int index)
{
	/*���Ŀ��ֵn������С��0˵����ǰ�ͺ�������ֶ�����Ŀ��ֵ����֦����Ϊ��1~9��������*/
	if (n < 0)
	{
		return;
	}
	/*���Ŀ��ֵn����0����k����0˵���ҵ�һ���ɹ���ϵģ����ҷ���Ҫ�󳤶ȣ�������Ҫ�µ�Ԫ�أ���ô�������·������*/
	if (k == 0 && n == 0)
	{
		int* temp = (int*)malloc(sizeof(int) * pathSize);
		for (int i = 0; i < pathSize; i++)
		{
			temp[i] = path[i];
		}
		res[resSize] = temp;
		resColumnSize[resSize++] = pathSize;
		return;
	}
	/*����֮ǰ�ù������ֲ������ã����������ظ�����ϣ�������Ϊ��1~9�������У����Ա�����9*/
	for (int i = index; i <= 9; i++)
	{
		/*����ǰ�����ӵ�·����*/
		path[pathSize++] = i;
		/*��ʼ�ݹ�����*/
		/*k-1������Ϊ·��������һ��Ԫ�أ���ô���賤��Ҳ�ͼ���һ��*/
		/*n-i���������������Ŀ��ֵn����0���ǳɹ��ҵ�һ�����*/
		/*i+1�����´εݹ鲻��ѡȡ��ǰֵ�������ظ�*/
		p216_CombinationSumIII_dfs(k - 1, n - i, res, path, i + 1);
		/*������ݣ�����״̬*/
		pathSize--;
	}
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
{
	/*������鳤�ȡ�ָ�룬·�����鳤�ȡ�ָ��*/
	resSize = pathSize = 0;
	/*�����������*/
	int** res = malloc(sizeof(int*) * 1001);
	/*����������*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*����·������*/
	int path[2001];
	/*��ʼ����*/
	p216_CombinationSumIII_dfs(k, n, res, path, 1);
	/*�������鳤��*/
	*returnSize = resSize;
	/*���������г���*/
	*returnColumnSizes = resColumnSize;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
