#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b)) /*�жϴ�С*/
#define LEN 1000 /*�������鳤��*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void getMaxValue(struct TreeNode* root, int* res, int level, int* returnSize)
{
	/*�����ǰ�ڵ�Ϊ��ֱ�ӷ���*/
	if (root == NULL)
	{
		return;
	}
	/*�����������һ���ڵ㣬ֱ�Ӽ��룬�����ж������ǲ���������Ԫ�ظ��������������ȣ�˵�������Ѿ�+1�ˣ���ô�ѵ�ǰ�ڵ���뼴�ɣ����⣬���鳤����Ӧ+1*/
	if (*returnSize == level)
	{
		res[level] = root->val;
		*returnSize += 1;
	}
	/*����������˵���������ֵܽڵ㣬��ô��Ҫ�Ƚ������ֵܽڵ�˭�󣬰Ѵ�ķŵ�������飬level���ǽ�������λ������������ÿһ������ֵ*/
	else
	{
		res[level] = MAX(res[level], root->val);
	}
	/*�քe�����ҵݹ飬ÿ�εݹ����+1��˵���ݹ������һ��*/
	getMaxValue(root->left, res, level + 1, returnSize);
	getMaxValue(root->right, res, level + 1, returnSize);
}

int* largestValues(struct TreeNode* root, int* returnSize)
{
	/*���鳤�ȳ�ʼ��Ϊ0*/
	*returnSize = 0;
	/*��������*/
	int* res = (int *)malloc(LEN * sizeof(int));
	/*���Ϊ��ֱ�ӷ��ؿ�*/
	if (root == NULL)
	{
		return NULL;
	}
	/*���ú�����ʼ�ݹ飬����level�����������0�㿪ʼ�����鿪ʼλ��һ����ע�⣬ÿһ��ֻ��һ��Ԫ��*/
	getMaxValue(root, res, 0, returnSize);
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
