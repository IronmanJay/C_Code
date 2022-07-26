#include<stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int res = 0;
	if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
	{
		res += root->left->val;
	}
	return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}


/*Ö÷º¯ÊıÊ¡ÂÔ*/