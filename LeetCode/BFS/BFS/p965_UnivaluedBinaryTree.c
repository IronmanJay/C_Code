#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode* root)
{
	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 101);
	int front = 0;
	int rear = 0;
	queue[rear++] = root;
	while (front != rear)
	{
		struct TreeNode* node = queue[front++];
		if (node->left != NULL)
		{
			if (node->val != node->left->val)
			{
				return false;
			}
			queue[rear++] = node->left;
		}
		if (node->right != NULL)
		{
			if (node->val != node->right->val)
			{
				return false;
			}
			queue[rear++] = node->right;
		}
	}
	return true;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/