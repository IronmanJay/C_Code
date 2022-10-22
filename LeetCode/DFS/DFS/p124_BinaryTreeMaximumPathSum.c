#include<stdio.h>
#include<limits.h>
#include<math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int res;

int getRes(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = fmax(0, getRes(root->left));
	int right = fmax(0, getRes(root->right));
	res = fmax(res, left + right + root->val);
	return fmax(left, right) + root->val;
}

int maxPathSum(struct TreeNode* root)
{
	res = INT_MIN;
	getRes(root);
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/