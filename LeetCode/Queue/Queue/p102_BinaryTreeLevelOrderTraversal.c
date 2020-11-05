#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/*定义队列大小和结点个数最大值*/
#define MAXSIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	/*判空返回*/
	if (root == NULL)
	{
		*returnSize = 0;
		return;
	}
	/*结果数组*/
	int** res = (int**)malloc(sizeof(int*)*MAXSIZE);
	/*结果数组每行的个数*/
	*returnColumnSizes = (int*)malloc(sizeof(int)*MAXSIZE);
	/*保存每一层结点的队列*/
	struct TreeNode* queue[10000];
	/*队列头指针*/
	int front = 0;
	/*队列尾指针*/
	int rear = 0;
	/*头结点入队列*/
	queue[rear++] = root;
	/*树的层数，也是返回结果数组的行数*/
	int level = 0;
	/*开始遍历*/
	while (front != rear)
	{
		/*当前层的结点个数*/
		int size = (rear - front % MAXSIZE);
		/*当前行的个数*/
		(*returnColumnSizes)[level] = size;
		/*存放当前层结点的数组*/
		int* tempList = (int*)malloc(sizeof(int)*size);
		/*遍历当前层，将当前层的每一个结点值遍历存入这一行的结果数组，并将下一层的结点存入队列，因为只遍历当前层的个数，所以不影响下一层的遍历*/
		for (int i = 0; i < size; i++)
		{
			struct TreeNode* tempNode = queue[front++];
			tempList[i] = tempNode->val;
			if (tempNode->left != NULL)
			{
				queue[rear++] = tempNode->left;
			}
			if (tempNode->right != NULL)
			{
				queue[rear++] = tempNode->right;
			}
		}
		/*将当前层的结点加入到结果数组，并准备遍历下一层*/
		res[level++] = tempList;
	}
	/*返回结果数组的行数*/
	*returnSize = level;
	/*返回结果*/
	return res;
}

/*主函数省略*/
