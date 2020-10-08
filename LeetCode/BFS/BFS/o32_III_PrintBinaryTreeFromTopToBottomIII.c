#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*队列长度*/
#define MAXSIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	/*判空返回*/
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	/*结果数组*/
	int** res = (int**)malloc(sizeof(int*)*MAXSIZE);
	*returnColumnSizes = (int*)malloc(sizeof(int)*MAXSIZE);
	/*控制左右输出方向指针*/
	int index = 0;
	/*头指针*/
	int head = 0;
	/*尾指针*/
	int tail = 0;
	/*记录是第几层*/
	int level = 1;
	/*存放临时节点*/
	struct TreeNode* node;
	/*存放每一层的队列*/
	struct TreeNode* queue[MAXSIZE];
	/*先将根节点入队列*/
	queue[tail++] = root;
	/*二维数组的行数指针*/
	*returnSize = 0;
	/*开始循环*/
	while (head < tail)
	{
		/*遍历每一层的节点个数*/
		int size = tail - head;
		(*returnColumnSizes)[*returnSize] = size;
		/*临时数组，存放每一层的结果*/
		res[*returnSize] = (int*)malloc(sizeof(int)*size);
		/*当前这一层有几个节点就循环几次，循环到每一个节点的同时将将节点值加入到临时数组中，另外将每一个节点的孩子节点入队列，因为只遍历队列中当前层的节点，所以对孩子（下一层）的节点不构成影响*/
		for (int i = 0; i < size; i++)
		{
			node = queue[head++];
			/*偶数层倒序添加节点值，奇数层正常添加节点值*/
			index = (level % 2 == 0) ? size - i - 1 : i;
			res[*returnSize][index] = node->val;
			if (node->left != NULL)
			{
				queue[tail++] = node->left;
			}
			if (node->right != NULL)
			{
				queue[tail++] = node->right;
			}
		}
		/*层数+1*/
		level++;
		/*二维数组的行数指针+1*/
		(*returnSize)++;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
