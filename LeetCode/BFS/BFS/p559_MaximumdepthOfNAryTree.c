#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int val;
	int numChildren;
	struct Node** children;
};


int* maxDepth(struct Node* root)
{
	/*判空返回*/
	if (root == NULL)
	{
		return 0;
	}
	/*存放每一层节点值的队列*/
	struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 10000);
	/*队列头指针*/
	int head = 0;
	/*队列尾指针*/
	int tail = 0;
	/*树的深度（结果值）*/
	int depth = 0;
	/*当前层的节点个数*/
	int size = 0;
	/*首先将根节点入队列*/
	queue[tail++] = root;
	struct Node* node = NULL;
	while (head < tail)
	{
		/*当前层的节点个数*/
		size = (tail - head + 5000) % 5000;
		/*当前层有几个节点就遍历几次*/
		for (int i = 0; i < size; i++)
		{
			/*依次取出（弹出）这一层的每一个节点*/
			node = queue[head++];
			/*将下一层的所有节点入队列，因为此次遍历只会循环当前层的个数，所以对下一层没有影响，等待对下一层的遍历*/
			for (int j = 0; j < node->numChildren; j++)
			{
				queue[tail++] = node->children[j];
			}
		}
		/*当前层遍历完之后树的层数+1*/
		depth++;
	}
	/*返回结果*/
	return depth;
}

/*主函数省略*/
