#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* t1;
struct TreeNode* t2;
struct TreeNode* pre;

void inOrder(struct TreeNode* root)
{
	if (root)
	{
		inOrder(root->left);
		if (pre != NULL && pre->val > root->val)
		{
			if (t1 == NULL)
			{
				t1 = pre;
			}
			t2 = root;
		}
		pre = root;
		inOrder(root->right);
	}
}

void recoverTree(struct TreeNode* root)
{
	t1 = NULL;
	t2 = NULL;
	pre = NULL;
	inOrder(root);
	int temp = t1->val;
	t1->val = t2->val;
	t2->val = temp;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/