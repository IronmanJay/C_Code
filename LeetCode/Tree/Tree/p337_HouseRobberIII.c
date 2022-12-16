#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* getResByDfs(struct TreeNode* root)
{
	if (root == NULL)
	{
		int* res = (int*)malloc(sizeof(int) * 2);
		res[0] = 0;
		res[1] = 0;
		return res;
	}
	int* left = getResByDfs(root->left);
	int* right = getResByDfs(root->right);
	int selectVal = root->val + left[1] + right[1];
	int noSelectVal = fmax(left[0], left[1]) + fmax(right[0], right[1]);
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = selectVal;
	res[1] = noSelectVal;
	return res;
}

int rob(struct TreeNode* root)
{
	int* res = getResByDfs(root);
	return fmax(res[0], res[1]);
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/