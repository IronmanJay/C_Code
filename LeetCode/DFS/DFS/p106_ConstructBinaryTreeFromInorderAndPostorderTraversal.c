#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/**
 * @inLeft ������������������ʼλ��
 * @inRight ��������������������λ��
 * @postLeft ������������������ʼλ�ã������������е��������������ж�
 * @postRight ��������������������λ�ã������������е��������������ж�
 * @inorder ��������
 * @postorder ��������
 */
struct TreeNode* getTree(int inLeft, int inRight, int postLeft, int postRight, int* inorder, int* postorder)
{
	/*�пշ��أ�˵��������������������޷��ٹ���һ���µ����������ݹ�*/
	if (inLeft > inRight)
	{
		return NULL;
	}
	/*�½����ڵ㣬������������һ�������Ǹ��ڵ�*/
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = postorder[postRight];
	/*��������ҵ����ڵ㣬������������ڵ�λ�þ�������������*/
	int inRoot = inLeft;
	while (inRoot <= inRight && inorder[inRoot] != root->val)
	{
		inRoot++;
	}
	int leftLen = inRoot - inLeft;
	/*���󻮷ֲ��ݹ鹹��������*/
	root->left = getTree(inLeft, inRoot - 1, postLeft, postLeft + leftLen - 1, inorder, postorder);
	/*���һ��ֵݹ鹹��������*/
	root->right = getTree(inRoot + 1, inRight, postLeft + leftLen, postRight - 1, inorder, postorder);
	/*ÿ�εݹ鷵��һ���µĽ��*/
	return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
	/*�ݹ��������ͺ������������*/
	return getTree(0, inorderSize - 1, 0, postorderSize - 1, inorder, postorder);
}

/*������ʡ��*/
