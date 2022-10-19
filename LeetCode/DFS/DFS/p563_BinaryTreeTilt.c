#include<stdio.h>
#include<math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int getTilt(struct TreeNode* root, int* sum)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftVal = getTilt(root->left, sum);
	int rightVal = getTilt(root->right, sum);
	*sum += abs(leftVal - rightVal);
	return root->val + leftVal + rightVal;
}

int findTilt(struct TreeNode* root)
{
	int sum = 0;
	getTilt(root, &sum);
	return sum;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/