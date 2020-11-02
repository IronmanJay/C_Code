#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isCousins(struct TreeNode* root, int x, int y)
{
	/*判空和特殊情况返回false*/
	if (root == NULL || x == root->val || y == root->val)
	{
		return false;
	}
	/*和x值相等的节点*/
	struct TreeNode* xNode = NULL;
	/*和y值相等的节点*/
	struct TreeNode* yNode = NULL;
	/*和x值相等的节点的父节点*/
	struct TreeNode* xFatherNode = NULL;
	/*和y值相等的节点的父节点*/
	struct TreeNode* yFatherNode = NULL;
	/*层序遍历的队列*/
	struct TreeNode* queue[100];
	int head = 0;
	int tail = 0;
	/*头结点入队列*/
	queue[tail++] = root;
	/*开始层序遍历*/
	while (head != tail)
	{
		/*当前层的结点数量*/
		int size = tail - head;
		while (size > 0)
		{
			/*出队列*/
			struct TreeNode* tempNode = queue[head++];
			/*当前层的结点数量-1*/
			size--;
			/*先看左子树*/
			if (tempNode->left != NULL)
			{
				/*入队列*/
				queue[tail++] = tempNode->left;
				/*找目标结点和目标结点的父结点*/
				if (tempNode->left->val == x)
				{
					xNode = tempNode->left;
					xFatherNode = tempNode;
				}
				if (tempNode->left->val == y)
				{
					yNode = tempNode->left;
					yFatherNode = tempNode;
				}
			}
			/*再看右子树*/
			if (tempNode->right != NULL)
			{
				/*入队列*/
				queue[tail++] = tempNode->right;
				/*找目标节点和目标结点的父结点*/
				if (tempNode->right->val == x)
				{
					xNode = tempNode->right;
					xFatherNode = tempNode;
				}
				if (tempNode->right->val == y)
				{
					yNode = tempNode->right;
					yFatherNode = tempNode;
				}
			}
			/*如果两个目标结点此次遍历都没找到不操作，等待下一次遍历*/
			if (xNode == NULL && yNode == NULL)
			{

			}
			/*如果此次遍历两个节点都找到了，判断是不是堂兄弟结点*/
			else if (xNode != NULL && yNode != NULL)
			{
				/*在这个for循环里面遍历保证了在同一层，只要不是一个父结点就是堂兄弟结点*/
				return xFatherNode != yFatherNode;
			}
			/*如果这一层都遍历完了，还没找到两个目标结点，说明已经不满足堂兄弟结点在同一层（深度）的要求的，就算下面有目标结点也不满足题意了，返回false*/
			else if (size == 0)
			{
				return false;
			}
		}
	}
	/*遍历结束都没找到，返回false*/
	return false;
}
