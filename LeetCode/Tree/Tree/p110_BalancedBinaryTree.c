#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*树的结构体*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root)
{
	/*返回结果*/
	return recur(root) != -1;
}

/*求最大值*/
int MAX(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int recur(struct TreeNode* root)
{
	/*遍历到叶子节点直接返回*/
	if (root == NULL)
	{
		return 0;
	}
	/*向左子树递归，返回左子树高度*/
	int left = recur(root->left);
	/*如果左子树本身不平衡就直接返回-1*/
	if (left == -1)
	{
		return -1;
	}
	/*向右子树递归，返回右子树高度*/
	int right = recur(root->right);
	/*如果右子树本身不平衡就直接返回-1*/
	if (right == -1)
	{
		return -1;
	}
	/*如果当前递归子树左右子树高度差不超过1，说明当前递归子树是平衡二叉树，只需要在当前把递归的子树+1，说明整棵树高度+1*/
	/*如果当前递归子树左右子树高度差超过1，说明当前递归子树不是平衡二叉树，直接返回-1*/
	return abs(left - right) < 2 ? MAX(left, right) + 1 : -1;
}

/*主函数省略*/
int main(void)
{

}
