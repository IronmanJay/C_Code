#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*���Ľṹ��*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int p129_SumRootToLeafNumbers_getRes(struct TreeNode* root, int sum)
{
	/*�ս��ֱ�ӷ���0*/
	if (root == NULL)
	{
		return 0;
	}
	/*�����Ҷ�ӽ����ô����ζ���ҵ���һ��·������֮ǰ·����״ֵ̬*10+��ǰ���ֵ��������·����ֵ*/
	if (root->left == NULL && root->right == NULL)
	{
		return sum * 10 + root->val;
	}
	/*����Ƿ�Ҷ�ӽ����������ҵݹ飬���뵱ǰ·����״ֵ̬��������һ�����ݹ���Ӽ����µ�·����״ֵ̬�����ݹ������������������������ֵ����Ӿ��ǽ��*/
	return p129_SumRootToLeafNumbers_getRes(root->left, sum * 10 + root->val) + p129_SumRootToLeafNumbers_getRes(root->right, sum * 10 + root->val);

}

int sumNumbers(struct TreeNode* root)
{
	return p129_SumRootToLeafNumbers_getRes(root, 0);
}

/*������ʡ��*/
