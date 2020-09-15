#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*���Ľṹ��*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root)
{
	/*���ؽ��*/
	return recur(root) != -1;
}

/*�����ֵ*/
int MAX(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int recur(struct TreeNode* root)
{
	/*������Ҷ�ӽڵ�ֱ�ӷ���*/
	if (root == NULL)
	{
		return 0;
	}
	/*���������ݹ飬�����������߶�*/
	int left = recur(root->left);
	/*�������������ƽ���ֱ�ӷ���-1*/
	if (left == -1)
	{
		return -1;
	}
	/*���������ݹ飬�����������߶�*/
	int right = recur(root->right);
	/*�������������ƽ���ֱ�ӷ���-1*/
	if (right == -1)
	{
		return -1;
	}
	/*�����ǰ�ݹ��������������߶Ȳ����1��˵����ǰ�ݹ�������ƽ���������ֻ��Ҫ�ڵ�ǰ�ѵݹ������+1��˵���������߶�+1*/
	/*�����ǰ�ݹ��������������߶Ȳ��1��˵����ǰ�ݹ���������ƽ���������ֱ�ӷ���-1*/
	return abs(left - right) < 2 ? MAX(left, right) + 1 : -1;
}

/*������ʡ��*/
int main(void)
{

}
