#include<stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int dfs_p671_SecondMinimumNodeInABinaryTree(struct TreeNode* root, int minVal)
{
	if (root == NULL)
	{
		return -1;
	}
	if (root->val > minVal)
	{
		return root->val;
	}
	int left = dfs_p671_SecondMinimumNodeInABinaryTree(root->left, minVal);
	int right = dfs_p671_SecondMinimumNodeInABinaryTree(root->right, minVal);
	if (left >= 0 && right >= 0)
	{
		return fmin(left, right);
	}
	return fmax(left, right);
}

int findSecondMinimumValue(struct TreeNode* root)
{
	return dfs_p671_SecondMinimumNodeInABinaryTree(root, root->val);
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/