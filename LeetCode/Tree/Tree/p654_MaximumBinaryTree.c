#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int getMaxIndex(int* nums, int left, int right)
{
	int max = -1;
	int maxIndex = left;
	for (int i = left; i <= right; i++)
	{
		if (max < nums[i])
		{
			max = nums[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

struct TreeNode* getMaxTree(int* nums, int left, int right)
{
	if (left > right)
	{
		return NULL;
	}
	int maxIndex = getMaxIndex(nums, left, right);
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = nums[maxIndex];
	root->left = getMaxTree(nums, left, maxIndex - 1);
	root->right = getMaxTree(nums, maxIndex + 1, right);
	return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
	return getMaxTree(nums, 0, numsSize - 1);
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/