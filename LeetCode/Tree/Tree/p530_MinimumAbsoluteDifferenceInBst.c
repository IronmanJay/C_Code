#include<stdio.h>
#include<limits.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void dfs_getRes(struct TreeNode* root, int* min, int* pre)
{
	if (root != NULL)
	{
		dfs_getRes(root->left, min, pre);
		if (*pre != -1 && root->val - *pre < *min)
		{
			*min = root->val - *pre;
		}
		*pre = root->val;
		dfs_getRes(root->right, min, pre);
	}
}

int getMinimumDifference(struct TreeNode* root)
{
	int min = INT_MAX;
	int pre = -1;
	dfs_getRes(root, &min, &pre);
	return min;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/