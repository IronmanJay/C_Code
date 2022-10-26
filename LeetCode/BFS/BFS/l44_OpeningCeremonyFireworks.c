#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int numColor(struct TreeNode* root)
{
	int* hash = (int*)calloc(1001, sizeof(int));
	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1001);
	int rear = 0;
	int front = 0;
	queue[rear++] = root;
	while (front != rear)
	{
		struct TreeNode* node = queue[front++];
		hash[node->val]++;
		if (node->left != NULL)
		{
			queue[rear++] = node->left;
		}
		if (node->right != NULL)
		{
			queue[rear++] = node->right;
		}
	}
	int res = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (hash[i] != 0)
		{
			res++;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/