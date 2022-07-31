#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	int** res = (int**)malloc(sizeof(int*) * 2001);
	*returnColumnSizes = (int*)malloc(sizeof(int) * 2001);
	*returnSize = 0;
	struct TreeNode* queue[2001];
	int front = 0;
	int rear = 0;
	bool flag = true;
	if (root == NULL)
	{
		(*returnColumnSizes)[*returnSize] = 0;
		return res;
	}
	queue[rear++] = root;
	while (front != rear)
	{
		res[*returnSize] = (int*)malloc(sizeof(int) * 2001);
		(*returnColumnSizes)[*returnSize] = 0;
		int size = (rear - front + 2001) % 2001;
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			struct TreeNode* temp = queue[front++];
			if (flag)
			{
				res[*returnSize][count] = temp->val;
			}
			else
			{
				res[*returnSize][size - count - 1] = temp->val;
			}
			if (temp->left != NULL)
			{
				queue[rear++] = temp->left;
			}
			if (temp->right != NULL)
			{
				queue[rear++] = temp->right;
			}
			count++;
		}
		(*returnColumnSizes)[*returnSize] = count;
		*returnSize = *returnSize + 1;
		if (flag)
		{
			flag = false;
		}
		else
		{
			flag = true;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/
