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

bool hasPathSum(struct TreeNode* root, int sum)
{
	/*�пշ��أ�Ҳ�ǵݹ�ķ���������Ҫд�����棬���д����������п�ָ���쳣����Ϊ������ж�ֱ��ʹ���ˣ���û�ж��Ƿ����*/
	if (root == NULL)
	{
		return false;
	}
	/*��ǰʣ��ֵ�ͽ��ֵ����ҵ�ǰ���Ϊ�����˵���ҵ���һ��·��*/
	if (sum - root->val == 0 && root->left == NULL && root->right == NULL)
	{
		return true;
	}
	/*�ֱ������������ݹ飬�ҵ�һ��·������*/
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
