#include<stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int getRes(struct TreeNode* root, int* res)
{
	if (root == NULL)
	{
		return 2;
	}
	int left = getRes(root->left, res);
	int right = getRes(root->right, res);
	if (left == 3 || right == 3)
	{
		(*res)++;
		return 1;
	}
	if (left == 1 || right == 1)
	{
		return 2;
	}
	return 3;
}

int minCameraCover(struct TreeNode* root)
{
	int res = 0;
	if (getRes(root, &res) == 3)
	{
		res++;
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/