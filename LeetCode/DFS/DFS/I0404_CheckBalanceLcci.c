#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/*�����������е����ֵ*/
int I0404_CheckBalanceLcci_Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int getHeight(struct TreeNode* root)
{
	/*�пշ���0��ѭ����������*/
	if (root == NULL)
	{
		return 0;
	}
	/*�������߶�*/
	int leftHeight = getHeight(root->left);
	/*�������߶�*/
	int rightHeight = getHeight(root->right);
	/*������������߶Ȳ����1��������������һ��������Ҫ�󷵻�-1*/
	if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
	{
		return -1;
	}
	/*���ص�ǰ�����߶�*/
	else
	{
		return I0404_CheckBalanceLcci_Max(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(struct TreeNode* root)
{
	/*���ؽ��*/
	return getHeight(root) >= 0;
}

/*������ʡ��*/
