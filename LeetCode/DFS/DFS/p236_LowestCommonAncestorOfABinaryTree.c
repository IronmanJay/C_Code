#include<stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	if (root == NULL)
	{
		return root;
	}
	if (root == p || root == q)
	{
		return root;
	}
	struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
	struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
	if (left != NULL && right != NULL)
	{
		return root;
	}
	else if (left != NULL)
	{
		return left;
	}
	else if (right != NULL)
	{
		return right;
	}
	return NULL;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/