#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*�������鳤��*/
int numslen;

/*������鳤�ȡ�ָ��*/
int resSize;

/*��������г���*/
int* resColumnSize;

/*·�����鳤�ȡ�ָ��*/
int pathSize;

/*���������������������*/
int p47_PermutationsII_compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void p47_PermutationsII_dfs(int* nums, int** res, int* path, bool* used, int depth)
{
	/*�����ǰ�ݹ����Ⱥ����鳤��һ��˵���ҵ���һ�����У����������飬�����˴εݹ鷵��*/
	if (depth == numslen)
	{
		/*���ﲻ��ֱ�ӽ�path��ֵ��res����Ϊֱ�Ӽ����ǵ�ַ���ã����뿽��һ������ֵ���ܵõ����*/
		int* temp = malloc(sizeof(int) * pathSize);
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
		/*ֻ�е�ǰԪ��û��ʹ�ù��ſ�������һ����ʼ�����У�����������ǰѭ��*/
		if (used[i])
		{
			continue;
		}
		/*i > 0��Ϊ�˱�֤nums[i - 1]������*/
		/*nums[i] == nums[i - 1]Ŀ���Ǽ�֦��ǰ��������������ظ���*/
		/*!used[i-1]��Ϊ�˱�֤ǰһ���ظ�������δʹ�ù�������˵��֮ǰ���ݹ��Ѿ�ʹ���ˣ������ʹ�þͻ�����ظ��������Ҳ���Ǽ�֦������*/
		if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
		{
			continue;
		}
		/*����ǰԪ�ؼ�������·��*/
		path[pathSize++] = nums[i];
		/*����ǰԪ����Ϊ�Ѿ�ʹ��*/
		used[i] = true;
		/*�Ե�ǰԪ�ؿ�ʼ�ݹ�������п��ܵĽ�������+1*/
		p47_PermutationsII_dfs(nums, res, path, used, depth + 1);
		/*�����￪ʼ���ݣ��ص���һ��״̬��Ҳ���ǵ�ǰԪ�ػ�û�б�ʹ��*/
		used[i] = false;
		/*�����Ѿ��õ��Ľ��Ԫ��ɾ��������״̬*/
		pathSize--;
	}
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
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
	/*ֻ�������˲��ܼ�֦�������򶼿��ԣ������ظ�������ǰһ���ظ���δʹ�þͼ�֦*/
	qsort(nums, numsSize, sizeof(int), p47_PermutationsII_compare);
	/*��ʼ����*/
	p47_PermutationsII_dfs(nums, res, path, used, 0);
	/*�������鳤��*/
	*returnSize = resSize;
	/*���������г���*/
	*returnColumnSizes = resColumnSize;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
