#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*���Ľṹ��*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*����������Сֵ*/
int MIN(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

/*����������С���*/
int minDepth(struct TreeNode *root)
{
	/*�����ǰ���Ϊ��ֱ�ӷ���0*/
	if (root == NULL)
	{
		return 0;
	}
	/*���������Ϊ�գ����������գ����Ҽ����ݹ飬������+1����Ϊ����һ���ڵ���Ⱦ�+1�����������սڵ㷵��0��֮ǰ�Ķ����������ǵ�ǰ���*/
	if (root->left == NULL && root->right != NULL)
	{
		return minDepth(root->right) + 1;
	}
	/*���������Ϊ�գ����������գ���������ݹ飬������+1����Ϊ����һ���ڵ���Ⱦ�+1�����������սڵ㷵��0��֮ǰ�Ķ����������ǵ�ǰ���*/
	if (root->right == NULL && root->left != NULL)
	{
		return minDepth(root->left) + 1;
	}
	/*����ÿ�εݹ����Сֵ������С���*/
	return MIN((minDepth(root->left) + 1), (minDepth(root->right) + 1));
}

/*������ʡ��*/
