#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	/*���س���*/
	*returnSize = 0;
	/*�������*/
	int* res = (int*)malloc(sizeof(int) * 501);
	/*ջ��Ž��*/
	struct TreeNode** stack = (struct TreeNode*)malloc(sizeof(struct TreeNode*) * 501);
	/*ջָ��*/
	int top = -1;
	/*��һ���ж�������Ϊ�˽�ͷ�����ջ���һ��ж�ÿ�θ���rootΪ���ӽ��Ϊ��ʱ�����м��㣬�ڶ����ж�������Ϊ�˱���������*/
	while (root != NULL || top != -1)
	{
		/*��ĳ������ȫ������������ڵ�ȫ����ջ����Ϊ�����������->��->��*/
		while (root != NULL)
		{
			stack[++top] = root;
			root = root->left;
		}
		/*��ʱ��ʼ�����������ľ��Ǵ�ʱ������������ӽ��*/
		root = stack[top--];
		/*��ֵ���뵽�������*/
		res[(*returnSize)++] = root->val;
		/*Ȼ�����rootΪ���ӽ�㣬��Ϊ�м����Ѿ���ջ���ˣ��������������ӽ�㣬�γ�����->��->�ҵ�˳�򣬸��º�����ӽ��ͬ�������Ƚ����ӽ���ȫ������������ڵ�ȫ����ջ*/
		root = root->right;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
