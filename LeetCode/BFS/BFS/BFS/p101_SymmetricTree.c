#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*注：1为true，0为false*/
typedef int bool;

/*定义树*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	return fun(root->left, root->right);
}

bool fun(struct TreeNode* l_root, struct TreeNode* r_root)
{
	if (l_root == NULL && r_root == NULL)
	{
		return 1;
	}
	if (l_root == NULL || r_root == NULL)
	{
		return 0;
	}
	return (l_root->val == r_root->val) && fun(l_root->left, r_root->right) && fun(l_root->right, r_root->left);
}

/*主函数内容省略，上面的算法是核心*/
