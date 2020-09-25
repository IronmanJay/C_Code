#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*�������鳤��*/
int numslen;

/*������鳤�ȡ�ָ��*/
int resSize;

/*��������г���*/
int* resColumnSize;

/*·�����鳤�ȡ�ָ��*/
int pathSize;

void p46_Permutations_dfs(int* nums, int** res, int* path, bool* used, int depth)
{
	/*�����ǰ�ݹ����Ⱥ����鳤��һ��˵���ҵ���һ�����У����������飬�����˴εݹ鷵��*/
	if (depth == numslen)
	{
		/*���ﲻ��ֱ�ӽ�path��ֵ��res����Ϊֱ�Ӽ����ǵ�ַ���ã����뿽��һ������ֵ���ܵõ����*/
		int* temp = (int*)malloc(sizeof(int)*pathSize);
		for (int i = 0; i < pathSize; i++)
		{
			temp[i] = path[i];
		}
		res[resSize] = temp;
		resColumnSize[resSize++] = pathSize;
		return;
	}
	/*����������ÿһ��Ԫ��Ϊ��һ����ʼ������*/
	for (int i = 0; i < numslen; i++)
	{
		/*ֻ�е�ǰԪ��û��ʹ�ù��ſ�������һ����ʼ������*/
		if (!used[i])
		{
			/*����ǰԪ�ؼ�������·��*/
			path[pathSize++] = nums[i];
			/*����ǰԪ����Ϊ�Ѿ�ʹ��*/
			used[i] = true;
			/*�Ե�ǰԪ�ؿ�ʼ�ݹ�������п��ܵĽ�������+1*/
			p46_Permutations_dfs(nums, res, path, used, depth + 1);
			/*�����￪ʼ���ݣ��ص���һ��״̬��Ҳ���ǵ�ǰԪ�ػ�û�б�ʹ��*/
			used[i] = false;
			/*�����Ѿ��õ��Ľ��Ԫ��ɾ��������״̬*/
			pathSize--;
		}
	}
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	/*��ȡ�������鳤��*/
	numslen = numsSize;
	/*������鳤�ȡ�ָ�룬·�����鳤�ȡ�ָ��*/
	resSize = pathSize = 0;
	/*�����������*/
	int** res = malloc(sizeof(int*) * 1001);
	/*����������*/
	resColumnSize = malloc(sizeof(int) * 1001);
	/*����·������*/
	int path[2001];
	/*�ж϶�ӦԪ���Ƿ�ʹ�ù�*/
	bool* used = (bool*)malloc(sizeof(bool)*numslen);
	memset(used, 0, numslen * sizeof(bool));
	/*��ʼ����*/
	p46_Permutations_dfs(nums, res, path, used, 0);
	/*�������鳤��*/
	*returnSize = resSize;
	/*���������г���*/
	*returnColumnSizes = resColumnSize;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
