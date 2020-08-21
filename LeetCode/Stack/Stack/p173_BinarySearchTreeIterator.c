#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXSIZE 256

/*树的结构*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*自定义栈，存放树节点*/
typedef struct
{
	struct TreeNode* stack[MAXSIZE];
	int top;
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root)
{
	/*初始化的时候先把根节点的所有左子节点入栈，从栈底到栈顶由大到小排列，首先就可以返回这个树的最小值*/
	BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
	obj->top = 0;
	/*把当前节点的每一个左子节点都入栈*/
	while (root)
	{
		/*入栈*/
		obj->stack[obj->top++] = root;
		/*继续向下一个左子节点遍历*/
		root = root->left;
	}
	/*返回初始化对象*/
	return obj;
}

int bSTIteratorNext(BSTIterator* obj)
{
	/*先出栈，出栈的这个节点肯定是当前树最小的节点*/
	struct TreeNode* node = obj->stack[--obj->top];
	/*
		先看弹出的这个节点是否有右子节点，如果有就入栈，因为左子节点都已经弹出了，如果有右子节点，说明当前这个节点
		既有左子节点又有右子节点，按照BST的规则，大小顺序是左->中->右，因为前面都已经按顺序弹出，所以将右子节点入栈，
		右子节点有左子节点那么它在栈底，因为左面最小，可以理解为当前的右子节点在push的过程中已经变成了当前这个子树的
		根节点，然后按照自定义规则继续调用
	*/
	int val = node->val;
	node = node->right;
	/*把当前节点的每一个左子节点都入栈*/
	while (node)
	{
		/*入栈*/
		obj->stack[obj->top++] = node;
		/*继续向下一个左子节点遍历*/
		node = node->left;
	}
	return val;
}

bool bSTIteratorHasNext(BSTIterator* obj)
{
	/*只要栈不空就说明有下一个，因为调用next()方法的时候，如果有下一个节点就入栈了*/
	return obj->top > 0;
}

/*释放资源*/
void bSTIteratorFree(BSTIterator* obj)
{
	free(obj);
}

