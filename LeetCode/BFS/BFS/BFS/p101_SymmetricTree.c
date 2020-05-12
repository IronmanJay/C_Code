#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*ע��1Ϊtrue��0Ϊfalse*/
typedef int bool;

/*������*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	return fun(root->left, root->right);
}

bool fun(struct TreeNode* l_root, struct TreeNode* r_root)
{
	if (l_root == NULL && r_root == NULL)
	{
		return 1;
	}
	if (l_root == NULL || r_root == NULL)
	{
		return 0;
	}
	return (l_root->val == r_root->val) && fun(l_root->left, r_root->right) && fun(l_root->right, r_root->left);
}

/*����������ʡ�ԣ�������㷨�Ǻ���*/
