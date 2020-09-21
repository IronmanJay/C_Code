#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�������鳤��*/
int candidatesLen;

/*������鳤�ȡ�ָ��*/
int resSize;

/*��������г���*/
int* resColumnSize;

/*·�����鳤�ȡ�ָ��*/
int pathSize;

void dfs(int* candidates, int begin, int target, int** res, int* path)
{
	/*targetΪ����˵����ǰ����ʧ�ܣ�û�ҵ���Ӧ����ϣ���Ϊ��������ֻ��������0������Ӧ�����*/
	if (target < 0)
	{
		return;
	}
	/*targetΪ0˵����������Ӧ����ϣ�������·�����뵽����У�������*/
	if (target == 0)
	{
		int* temp = malloc(sizeof(int) * pathSize);
		for (int i = 0; i < pathSize; ++i)
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
		/*����ǰ�����ӵ�·����*/
		path[pathSize++] = candidates[i];
		/*��ʼ������ÿ�δ�ͷ��ʼ������ΪԪ�ؿ����ظ�ʹ�ã�������һ�ֵ���㻹��i��target��������������ȥ��ǰ��������ֵ������������0˵���ҵ��˶�Ӧ�����*/
		dfs(candidates, i, target - candidates[i], res, path);
		/*ÿ�ҵ�һ��·��������״̬*/
		pathSize--;
	}
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
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
	/*��ʼ����*/
	dfs(candidates, 0, target, res, path);
	/*�������鳤��*/
	*returnSize = resSize;
	/*���������г���*/
	*returnColumnSizes = resColumnSize;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
int main(void)
{

}
