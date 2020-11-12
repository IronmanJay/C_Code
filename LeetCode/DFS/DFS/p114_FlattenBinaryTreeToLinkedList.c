#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void flatten(struct TreeNode* root)
{
	/*�ݹ������������ҵ�Ҷ�ӽڵ㿪ʼ����*/
	if (root == NULL)
	{
		return;
	}
	/*��Ϊ��������û�޸ĵ�����²����޸ĸ��ڵ�ָ����������ָ�룬����ʹ�ú�������������������->��->��������޸ĸ��ڵ��ָ�룩*/
	flatten(root->left);
	flatten(root->right);
	/*���Ƚ���ǰ�ڵ������������*/
	struct TreeNode* tempNode = root->right;
	/*�ٽ���ǰ�ڵ������������Ϊ������*/
	root->right = root->left;
	/*Ȼ�󽫵�ǰ�ڵ���������ÿ�*/
	root->left = NULL;
	/*��󽫵�ǰ�ڵ���º����������֮ǰ�����������ƴ��*/
	while (root->right != NULL)
	{
		root = root->right;
	}
	root->right = tempNode;
	/*������ǰ����*/
	return;
}

/*������ʡ��*/
