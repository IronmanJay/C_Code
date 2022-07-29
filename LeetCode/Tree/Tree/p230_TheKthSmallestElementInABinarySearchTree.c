#include<stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int size;

void inOrder(struct TreeNode* root, int *nums)
{
	if (root != NULL)
	{
		inOrder(root->left, nums);
		nums[size++] = root->val;
		inOrder(root->right, nums);
	}
}

int kthSmallest(struct TreeNode* root, int k)
{
	size = 0;
	int nums[10001] = { 0 };
	inOrder(root, nums);
	return nums[k - 1];
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/