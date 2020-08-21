#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXSIZE 256

/*���Ľṹ*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*�Զ���ջ��������ڵ�*/
typedef struct
{
	struct TreeNode* stack[MAXSIZE];
	int top;
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root)
{
	/*��ʼ����ʱ���ȰѸ��ڵ���������ӽڵ���ջ����ջ�׵�ջ���ɴ�С���У����ȾͿ��Է������������Сֵ*/
	BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
	obj->top = 0;
	/*�ѵ�ǰ�ڵ��ÿһ�����ӽڵ㶼��ջ*/
	while (root)
	{
		/*��ջ*/
		obj->stack[obj->top++] = root;
		/*��������һ�����ӽڵ����*/
		root = root->left;
	}
	/*���س�ʼ������*/
	return obj;
}

int bSTIteratorNext(BSTIterator* obj)
{
	/*�ȳ�ջ����ջ������ڵ�϶��ǵ�ǰ����С�Ľڵ�*/
	struct TreeNode* node = obj->stack[--obj->top];
	/*
		�ȿ�����������ڵ��Ƿ������ӽڵ㣬����о���ջ����Ϊ���ӽڵ㶼�Ѿ������ˣ���������ӽڵ㣬˵����ǰ����ڵ�
		�������ӽڵ��������ӽڵ㣬����BST�Ĺ��򣬴�С˳������->��->�ң���Ϊǰ�涼�Ѿ���˳�򵯳������Խ����ӽڵ���ջ��
		���ӽڵ������ӽڵ���ô����ջ�ף���Ϊ������С���������Ϊ��ǰ�����ӽڵ���push�Ĺ������Ѿ�����˵�ǰ���������
		���ڵ㣬Ȼ�����Զ�������������
	*/
	int val = node->val;
	node = node->right;
	/*�ѵ�ǰ�ڵ��ÿһ�����ӽڵ㶼��ջ*/
	while (node)
	{
		/*��ջ*/
		obj->stack[obj->top++] = node;
		/*��������һ�����ӽڵ����*/
		node = node->left;
	}
	return val;
}

bool bSTIteratorHasNext(BSTIterator* obj)
{
	/*ֻҪջ���վ�˵������һ������Ϊ����next()������ʱ���������һ���ڵ����ջ��*/
	return obj->top > 0;
}

/*�ͷ���Դ*/
void bSTIteratorFree(BSTIterator* obj)
{
	free(obj);
}

