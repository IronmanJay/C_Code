#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*定义树*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAX_LEN 1000

int* rightSideView(struct TreeNode* root, int* returnSize)
{
	*returnSize = 0;
	if (root == NULL) 
	{
		return NULL;
	}
	int *res = (int *)malloc(MAX_LEN * sizeof(int));

	struct TreeNode **queue = (struct TreeNode **)malloc(MAX_LEN * sizeof(struct TreeNode *));
	int head = 0;
	int tail = 0;

	queue[tail++] = root;

	while (head < tail)
	{
		int size = tail - head;
		for (int i = 0; i < size; i++) 
		{
			struct TreeNode *node = queue[head++];
			if (node->left)
			{
				queue[tail++] = node->left;
			}
			if (node->right)
			{
				queue[tail++] = node->right;
			}
			if (i == size - 1) 
			{
				res[(*returnSize)++] = node->val;
			}
		}
	}
	return res;
}

/*主函数内容省略，上面的算法是核心*/
