#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
	// �����Ҷ�ӽ��ֱ�ӷ���
	if (root == NULL)
	{
		return 0;
	}
	// ����ݹ飬���ص�ǰ����������߶ȣ��ݹ�һ�ξ�˵���߶�+1
	int left = maxDepth(root->left) + 1;
	// ���ҵݹ飬���ص�ǰ����������߶ȣ��ݹ�һ�ξ�˵���߶�+1
	int right = maxDepth(root->right) + 1;
	// �����е����ֵ�������ĸ߶�
	return left > right ? left : right;
}

/*������ʡ��*/
