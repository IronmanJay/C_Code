#include<stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
	double* res = (double*)malloc(sizeof(double) * 10001);
	int index = 0;
	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10001);
	int front = 0;
	int rear = 0;
	queue[rear++] = root;
	while (front != rear)
	{
		double sum = 0;
		int size = (rear - front + 10001) % 10001;
		for (int i = 0; i < size; i++)
		{
			struct TreeNode* temp = queue[front++];
			sum += temp->val;
			if (temp->left != NULL)
			{
				queue[rear++] = temp->left;
			}
			if (temp->right != NULL)
			{
				queue[rear++] = temp->right;
			}
		}
		res[index++] = sum / size;
	}
	*returnSize = index;
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/