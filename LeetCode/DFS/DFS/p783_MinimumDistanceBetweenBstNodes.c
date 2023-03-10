#include<stdio.h>
#include<math.h>
#include<limits.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void inOrder_p783_MinimumDistanceBetweenBstNodes(struct TreeNode* root, int* pre, int* min)
{
	if (root != NULL)
	{
		inOrder_p783_MinimumDistanceBetweenBstNodes(root->left, pre, min);
		if (*pre != -1)
		{
			*min = fmin(*min, abs(root->val - (*pre)));
		}
		*pre = root->val;
		inOrder_p783_MinimumDistanceBetweenBstNodes(root->right, pre, min);
	}
}

int minDiffInBST(struct TreeNode* root)
{
	int* pre = -1;
	int min = INT_MAX;
	inOrder_p783_MinimumDistanceBetweenBstNodes(root, &pre, &min);
	return min;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/