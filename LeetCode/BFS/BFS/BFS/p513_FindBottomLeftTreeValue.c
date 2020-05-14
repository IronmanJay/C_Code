#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int findBottomLeftValue(struct TreeNode* root)
{
	struct TreeNode *Queue[10000];
	struct TreeNode *first = NULL;
	int front, rear, last;
	front = rear = last = 0;
	Queue[root ? rear++ : rear] = root;
	last = rear;
	first = root;

	struct TreeNode *p = NULL;
	while (front < rear)
	{
		p = Queue[front];
		if (front++ == last)
		{
			last = rear;
			first = p;
		}
		if (p->left)
		{
			Queue[rear++] = p->left;
		}
		if (p->right)
		{
			Queue[rear++] = p->right;
		}
	}
	return first ? first->val : 0;
}

/*主函数内容省略，上面的算法是核心*/
