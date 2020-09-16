#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
	// 如果是叶子结点直接返回
	if (root == NULL)
	{
		return 0;
	}
	// 向左递归，返回当前结点左子树高度，递归一次就说明高度+1
	int left = maxDepth(root->left) + 1;
	// 向右递归，返回当前结点右子树高度，递归一次就说明高度+1
	int right = maxDepth(root->right) + 1;
	// 两者中的最大值就是树的高度
	return left > right ? left : right;
}

/*主函数省略*/
