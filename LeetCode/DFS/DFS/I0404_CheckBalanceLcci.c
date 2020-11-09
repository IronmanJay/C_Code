#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/*返回两个数中的最大值*/
int I0404_CheckBalanceLcci_Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int getHeight(struct TreeNode* root)
{
	/*判空返回0，循环跳出条件*/
	if (root == NULL)
	{
		return 0;
	}
	/*左子树高度*/
	int leftHeight = getHeight(root->left);
	/*右子树高度*/
	int rightHeight = getHeight(root->right);
	/*如果左右子树高度差大于1或者左右子树有一个不满足要求返回-1*/
	if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
	{
		return -1;
	}
	/*返回当前子树高度*/
	else
	{
		return I0404_CheckBalanceLcci_Max(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(struct TreeNode* root)
{
	/*返回结果*/
	return getHeight(root) >= 0;
}

/*主函数省略*/
