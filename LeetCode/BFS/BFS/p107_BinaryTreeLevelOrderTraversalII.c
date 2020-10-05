#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAXSIZE 10000

/*返回二叉树的深度*/
int getDepth(struct TreeNode* root)
{
	int leftHeight;
	int rightHeight;
	if (root == NULL)
	{
		return 0;
	}
	leftHeight = getDepth(root->left);
	rightHeight = getDepth(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	/*数的深度就是返回数组的行数*/
	*returnSize = getDepth(root);
	/*结果数组*/
	int** res = (int**)malloc(sizeof(int*)*(*returnSize));
	*returnColumnSizes = (int*)malloc(sizeof(int) *(*returnSize));
	/*判空返回*/
	if (root == NULL)
	{
		return res;
	}
	/*结果数组下标*/
	int index = (*returnSize);
	/*存放每一层的队列*/
	struct TreeNode* queue[MAXSIZE];
	int head = 0;
	int tail = 0;
	int size;
	struct TreeNode* node;
	/*先将根节点入队列*/
	queue[tail++] = root;
	/*开始循环*/
	while (head < tail)
	{
		size = (tail - head + MAXSIZE) % MAXSIZE;
		(*returnColumnSizes)[--index] = size;
		/*直接倒序插入*/
		res[index] = (int*)malloc(sizeof(int)*size);
		/*遍历这一层的每一个节点并将其值加入到结果数组，并且将下一层的节点加入队列中等待下一次遍历*/
		for (int i = 0; i < size; i++)
		{
			node = queue[head++];
			res[index][i] = node->val;
			if (node->left)
			{
				queue[tail++] = node->left;
			}
			if (node->right)
			{
				queue[tail++] = node->right;
			}
		}
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
