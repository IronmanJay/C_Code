#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*定义树*/
struct Node
{
	int val;
	int numChildren;
	struct Node** children;
};

/*队列长度*/
#define MAXSIZE 5000
/*返回数组的行长度*/
#define MAXROW 1000
/*存放每一层节点的队列*/
struct Node* queue[MAXSIZE] = { 0 };

int** p429_NAryTreeLevelOrderTraversal_levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes)
{
	/*返回数组行指针*/
	*returnSize = 0;
	/*判空返回*/
	if (root == NULL)
	{
		*returnColumnSizes = NULL;
		return NULL;
	}
	/*结果数组*/
	int** res = (int**)malloc(sizeof(int*)*MAXROW);
	/*结果数组每行的列长度*/
	*returnColumnSizes = (int*)malloc(sizeof(int) * MAXSIZE);
	/*队列头指针*/
	int head = 0;
	/*队列尾指针*/
	int tail = 0;
	/*头结点入队列*/
	queue[tail++] = root;
	/*开始遍历*/
	while (head != tail)
	{
		/*当前这一层的节点个数，使用循环队列*/
		int size = (tail - head + MAXSIZE) % MAXSIZE;
		/*结果数组顺序开辟对应这一层节点个数的数组空间*/
		res[returnSize[0]] = (int *)malloc(sizeof(int)*size);
		/*结果数组上面对应行的对应列长度，也就是当前层的节点个数*/
		returnColumnSizes[0][returnSize[0]] = size;
		/*当前这一层有几个节点就循环几次，循环到每一个节点的同时将将节点值加入到临时数组中，另外将每一个节点的孩子节点入队列，因为只遍历队列中当前层的节点，所以对孩子（下一层）的节点不构成影响*/
		for (int i = 0; i < size; i++) {
			/*取出队列头结点*/
			struct Node* node = queue[head];
			/*循环队列，头指针+1*/
			head = (head + 1) % MAXSIZE;
			/*将结果存入结果数组当前行的数组*/
			res[returnSize[0]][i] = node->val;
			/*找出当前层每一个节点的孩子节点*/
			for (int j = 0; j < node->numChildren; j++)
			{
				/*如果存在*/
				if (node->children[j])
				{
					/*将所有的孩子节点入队列，等待对下一层的遍历*/
					queue[tail] = node->children[j];
					/*循环队列，尾指针+1*/
					tail = (tail + 1) % MAXSIZE;
				}
			}
		}
		/*当前层遍历完毕，开始遍历下一层，层数（行数）+1*/
		returnSize[0]++;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
