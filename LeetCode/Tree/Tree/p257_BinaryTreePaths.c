#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void p257_BinaryTreePaths_getRes(struct TreeNode* root, char** res, int* returnSize, int* path, int pathIndex)
{
	/*�ս�㷵��NULL*/
	if (root == NULL)
	{
		return NULL;
	}
	/*����Ҷ�ӽ�������·���ŵ����������*/
	if (root->left == NULL && root->right == NULL)
	{
		char* temp = (char*)malloc(sizeof(char*) * 1001);
		int len = 0;
		for (int i = 0; i < pathIndex; i++)
		{
			len += sprintf(temp + len, "%d->", path[i]);
		}
		sprintf(temp + len, "%d", root->val);
		res[(*returnSize)++] = temp;
	}
	/*�������Ҷ�ӽڵ���뵽·��������*/
	else
	{
		path[pathIndex++] = root->val;
	}
	/*���������ݹ�*/
	p257_BinaryTreePaths_getRes(root->left, res, returnSize, path, pathIndex);
	/*���������ݹ�*/
	p257_BinaryTreePaths_getRes(root->right, res, returnSize, path, pathIndex);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
	/*�������*/
	char** res = (char**)malloc(sizeof(char*) * 1001);
	/*�������ָ�룬Ҳ�Ƿ��صĽ�����鳤��*/
	*returnSize = 0;
	/*���·������*/
	int path[1001];
	/*·������ָ��*/
	int pathIndex = 0;
	/*��ʼ�ݹ�*/
	p257_BinaryTreePaths_getRes(root, res, returnSize, path, pathIndex);
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
