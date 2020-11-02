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

bool isCousins(struct TreeNode* root, int x, int y)
{
	/*�пպ������������false*/
	if (root == NULL || x == root->val || y == root->val)
	{
		return false;
	}
	/*��xֵ��ȵĽڵ�*/
	struct TreeNode* xNode = NULL;
	/*��yֵ��ȵĽڵ�*/
	struct TreeNode* yNode = NULL;
	/*��xֵ��ȵĽڵ�ĸ��ڵ�*/
	struct TreeNode* xFatherNode = NULL;
	/*��yֵ��ȵĽڵ�ĸ��ڵ�*/
	struct TreeNode* yFatherNode = NULL;
	/*��������Ķ���*/
	struct TreeNode* queue[100];
	int head = 0;
	int tail = 0;
	/*ͷ��������*/
	queue[tail++] = root;
	/*��ʼ�������*/
	while (head != tail)
	{
		/*��ǰ��Ľ������*/
		int size = tail - head;
		while (size > 0)
		{
			/*������*/
			struct TreeNode* tempNode = queue[head++];
			/*��ǰ��Ľ������-1*/
			size--;
			/*�ȿ�������*/
			if (tempNode->left != NULL)
			{
				/*�����*/
				queue[tail++] = tempNode->left;
				/*��Ŀ�����Ŀ����ĸ����*/
				if (tempNode->left->val == x)
				{
					xNode = tempNode->left;
					xFatherNode = tempNode;
				}
				if (tempNode->left->val == y)
				{
					yNode = tempNode->left;
					yFatherNode = tempNode;
				}
			}
			/*�ٿ�������*/
			if (tempNode->right != NULL)
			{
				/*�����*/
				queue[tail++] = tempNode->right;
				/*��Ŀ��ڵ��Ŀ����ĸ����*/
				if (tempNode->right->val == x)
				{
					xNode = tempNode->right;
					xFatherNode = tempNode;
				}
				if (tempNode->right->val == y)
				{
					yNode = tempNode->right;
					yFatherNode = tempNode;
				}
			}
			/*�������Ŀ����˴α�����û�ҵ����������ȴ���һ�α���*/
			if (xNode == NULL && yNode == NULL)
			{

			}
			/*����˴α��������ڵ㶼�ҵ��ˣ��ж��ǲ������ֵܽ��*/
			else if (xNode != NULL && yNode != NULL)
			{
				/*�����forѭ�����������֤����ͬһ�㣬ֻҪ����һ�������������ֵܽ��*/
				return xFatherNode != yFatherNode;
			}
			/*�����һ�㶼�������ˣ���û�ҵ�����Ŀ���㣬˵���Ѿ����������ֵܽ����ͬһ�㣨��ȣ���Ҫ��ģ�����������Ŀ����Ҳ�����������ˣ�����false*/
			else if (size == 0)
			{
				return false;
			}
		}
	}
	/*����������û�ҵ�������false*/
	return false;
}
