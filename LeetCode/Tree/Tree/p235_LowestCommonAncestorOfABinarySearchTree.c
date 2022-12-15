#include<stdio.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	struct TreeNode* dad = root;
	while (true)
	{
		if (dad->val > p->val && dad->val > q->val)
		{
			dad = dad->left;
		}
		else if (dad->val < p->val && dad->val < q->val)
		{
			dad = dad->right;
		}
		else
		{
			break;
		}
	}
	return dad;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/