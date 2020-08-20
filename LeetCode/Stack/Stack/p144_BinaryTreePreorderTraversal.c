#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*���Ľṹ*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*����ջ���������ֵ*/
#define MAXSIZE 100

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	/*��ʼ��ջ*/
	struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAXSIZE);
	/*�½��������*/
	int* res = (int*)malloc(sizeof(int) * MAXSIZE);
	/*ջ��ָ��*/
	int top = -1;
	/*�������ָ��*/
	*returnSize = 0;
	/*�пշ���*/
	if (root == NULL)
	{
		return res;
	}
	/*��ͷ�ڵ���ջ�������������*/
	stack[++top] = root;
	/*��ʼ����*/
	while (top != -1)
	{
		/*ȡ��ջ��Ԫ�أ�ÿ�α������½ڵ㶼�൱��root�ڵ㣬���൱��ǰ������ġ�����*/
		root = stack[top--];
		/*��ջ��Ԫ��ֵ����������*/
		res[(*returnSize)++] = root->val;
		/*˵����������Ȼ����˳���ǡ��ҡ�->���󡱣������������ǡ���->���ҡ������ϡ�����->����->���ҡ���ǰ�����*/
		/*�ȼ����ҽڵ㣬��ջβ������ÿ�κ��������ڵ�ֵ�����൱��ǰ������ġ��ҡ�*/
		if (root->right != NULL)
		{
			stack[++top] = root->right;
		}
		/*�������ڵ㣬��ջ��������ÿ���ȱ�������ڵ�ֵ�����൱��ǰ������ġ���*/
		if (root->left != NULL)
		{
			stack[++top] = root->left;
		}
	}
	/*ֱ�ӷ��ؽ������*/
	return res;
}

/*������ʡ��*/
