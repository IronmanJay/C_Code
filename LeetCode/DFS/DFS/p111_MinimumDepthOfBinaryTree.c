#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*树的结构体*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*求两个数最小值*/
int MIN(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

/*二叉树的最小深度*/
int minDepth(struct TreeNode *root)
{
	/*如果当前结点为空直接返回0*/
	if (root == NULL)
	{
		return 0;
	}
	/*如果左子树为空，右子树不空，向右继续递归，别忘了+1，因为遍历一个节点深度就+1，当遍历到空节点返回0把之前的都加起来就是当前深度*/
	if (root->left == NULL && root->right != NULL)
	{
		return minDepth(root->right) + 1;
	}
	/*如果右子树为空，左子树不空，向左继续递归，别忘了+1，因为遍历一个节点深度就+1，当遍历到空节点返回0把之前的都加起来就是当前深度*/
	if (root->right == NULL && root->left != NULL)
	{
		return minDepth(root->left) + 1;
	}
	/*返回每次递归的最小值就是最小深度*/
	return MIN((minDepth(root->left) + 1), (minDepth(root->right) + 1));
}

/*主函数省略*/
