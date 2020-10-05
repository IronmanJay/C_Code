#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAXSIZE 10000

/*���ض����������*/
int getDepth(struct TreeNode* root)
{
	int leftHeight;
	int rightHeight;
	if (root == NULL)
	{
		return 0;
	}
	leftHeight = getDepth(root->left);
	rightHeight = getDepth(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	/*������Ⱦ��Ƿ������������*/
	*returnSize = getDepth(root);
	/*�������*/
	int** res = (int**)malloc(sizeof(int*)*(*returnSize));
	*returnColumnSizes = (int*)malloc(sizeof(int) *(*returnSize));
	/*�пշ���*/
	if (root == NULL)
	{
		return res;
	}
	/*��������±�*/
	int index = (*returnSize);
	/*���ÿһ��Ķ���*/
	struct TreeNode* queue[MAXSIZE];
	int head = 0;
	int tail = 0;
	int size;
	struct TreeNode* node;
	/*�Ƚ����ڵ������*/
	queue[tail++] = root;
	/*��ʼѭ��*/
	while (head < tail)
	{
		size = (tail - head + MAXSIZE) % MAXSIZE;
		(*returnColumnSizes)[--index] = size;
		/*ֱ�ӵ������*/
		res[index] = (int*)malloc(sizeof(int)*size);
		/*������һ���ÿһ���ڵ㲢����ֵ���뵽������飬���ҽ���һ��Ľڵ��������еȴ���һ�α���*/
		for (int i = 0; i < size; i++)
		{
			node = queue[head++];
			res[index][i] = node->val;
			if (node->left)
			{
				queue[tail++] = node->left;
			}
			if (node->right)
			{
				queue[tail++] = node->right;
			}
		}
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
