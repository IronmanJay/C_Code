#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* mirrorTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return root;
	}
	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1001);
	int front = 0;
	int rear = 0;
	queue[rear++] = root;
	while (front != rear)
	{
		struct TreeNode* node = queue[front++];
		struct TreeNode* temp = node->left;
		node->left = node->right;
		node->right = temp;
		if (node->left != NULL)
		{
			queue[rear++] = node->left;
		}
		if (node->right != NULL)
		{
			queue[rear++] = node->right;
		}
	}
	return root;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/