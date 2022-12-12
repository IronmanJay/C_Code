#include<stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int dfsDiameter(struct TreeNode* root, int* res)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = dfsDiameter(root->left, res);
	int right = dfsDiameter(root->right, res);
	*res = fmax(*res, left + right);
	return fmax(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
	int res = 0;
	dfsDiameter(root, &res);
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/