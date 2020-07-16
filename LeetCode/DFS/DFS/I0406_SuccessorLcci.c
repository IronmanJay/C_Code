#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*定义树的结构体*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*定义结果的结构体*/
struct Result
{
	/*保存前一个结点，如果pre和当前值相等，说明node就是结果*/
	struct TreeNode* pre;
	/*保存返回结果*/
	struct TreeNode* res;
	/*/*标志位，如果为true就停止递归，返回结果*/
	bool found;
};

void inorderTraver(struct TreeNode* node, struct TreeNode* p, struct Result* res)
{
	/*如果当前节点为空说明遍历结束，或者found为true说明找到，都返回*/
	if (node == NULL || res->found)
	{
		return;
	}
	/*如果左子结点不空，向左子树递归*/
	if (node->left != NULL)
	{
		inorderTraver(node->left, p, res);
	}
	/*比较当前结点的前一个结点是否和p相等，如果相等，说明当前结点就是要找的结果，将标志位置为true，返回即可*/
	if (res->pre == p)
	{
		res->res = node;
		res->found = true;
	}
	/*更新pre，如果不符合把当前结点赋值给pre，成为下一个节点的前一个结点*/
	res->pre = node;
	/*如果右子树不空，向右子树递归*/
	if (node->right != NULL)
	{
		inorderTraver(node->right, p, res);
	}
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p)
{
	// 初始化结果结构体
	struct Result* res = (struct Result*)malloc(sizeof(struct Result));
	res->pre = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	res->res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	res->found = false;
	/*开始递归*/
	inorderTraver(root, p, res);
	/*如果标志位为false，没有找到，返回NULL*/
	if (!res->found)
	{
		return NULL;
	}
	/*如果找到返回结果*/
	return res->res;
}

/*主函数省略*/
