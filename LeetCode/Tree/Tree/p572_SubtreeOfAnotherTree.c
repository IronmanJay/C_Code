#include<stdio.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool judge(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p == NULL || q == NULL)
	{
		return false;
	}
	else if (p->val != q->val)
	{
		return false;
	}
	return judge(p->left, q->left) && judge(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (judge(root, subRoot) || subRoot == NULL)
	{
		return true;
	}
	if (root == NULL)
	{
		return false;
	}
	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/