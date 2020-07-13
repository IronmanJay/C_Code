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

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	/*如果两棵树节点都为空说明，说明当前递归到底了，这次递归返回true*/
	if (p == NULL && q == NULL)
	{
		return true;
	}
	/*如果两棵树节点其中有一棵为空，说明两棵树当前节点不相等，这次递归返回false*/
	if (p == NULL || q == NULL)
	{
		return false;
	}
	/*如果两棵树节点值不相同，说明两棵树当前结点不相等，这次递归返回false*/
	if (p->val != q->val)
	{
		return false;
	}
	/*分别向左和向右递归，如果都返回true，说明两棵树相同*/
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(void)
{
	/*主函数省略*/
}
