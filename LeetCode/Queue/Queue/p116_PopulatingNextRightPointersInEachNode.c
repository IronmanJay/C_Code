#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
	struct Node* next;
};

struct Node* connect(struct Node* root)
{
	/*判空返回*/
	if (root == NULL)
	{
		return root;
	}
	/*存放每层的结点的队列*/
	struct Node** queue = (struct Node*)malloc(sizeof(struct Node) * 10000);
	/*队列头指针*/
	int front = 0;
	/*队列尾指针*/
	int rear = 0;
	/*头结点入队列*/
	queue[rear++] = root;
	/*开始循环*/
	while (front != rear)
	{
		/*当前层的结点个数*/
		int size = (rear - front % 10000);
		/*遍历当前层*/
		while (size > 0)
		{
			/*当前层每一个结点*/
			struct Node* tempNode = queue[front++];
			/*如果到当前层的最后一个结点了，指向空，否则会指向下一层的结点*/
			if (size == 1)
			{
				tempNode->next = NULL;
			}
			/*如果没到当前层最后一个结点，从左指向右*/
			else
			{
				tempNode->next = queue[front];
			}
			/*左子结点不为空入队列*/
			if (tempNode->left != NULL)
			{
				queue[rear++] = tempNode->left;
			}
			/*右子结点不为空入队列*/
			if (tempNode->right != NULL)
			{
				queue[rear++] = tempNode->right;
			}
			/*当前层的结点个数-1*/
			size--;
		}
	}
	/*返回结果*/
	return root;
}

/*主函数省略*/
