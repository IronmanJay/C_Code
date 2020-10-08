#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*���г���*/
#define MAXSIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	/*�пշ���*/
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	/*�������*/
	int** res = (int**)malloc(sizeof(int*)*MAXSIZE);
	*returnColumnSizes = (int*)malloc(sizeof(int)*MAXSIZE);
	/*���������������ָ��*/
	int index = 0;
	/*ͷָ��*/
	int head = 0;
	/*βָ��*/
	int tail = 0;
	/*��¼�ǵڼ���*/
	int level = 1;
	/*�����ʱ�ڵ�*/
	struct TreeNode* node;
	/*���ÿһ��Ķ���*/
	struct TreeNode* queue[MAXSIZE];
	/*�Ƚ����ڵ������*/
	queue[tail++] = root;
	/*��ά���������ָ��*/
	*returnSize = 0;
	/*��ʼѭ��*/
	while (head < tail)
	{
		/*����ÿһ��Ľڵ����*/
		int size = tail - head;
		(*returnColumnSizes)[*returnSize] = size;
		/*��ʱ���飬���ÿһ��Ľ��*/
		res[*returnSize] = (int*)malloc(sizeof(int)*size);
		/*��ǰ��һ���м����ڵ��ѭ�����Σ�ѭ����ÿһ���ڵ��ͬʱ�����ڵ�ֵ���뵽��ʱ�����У����⽫ÿһ���ڵ�ĺ��ӽڵ�����У���Ϊֻ���������е�ǰ��Ľڵ㣬���ԶԺ��ӣ���һ�㣩�Ľڵ㲻����Ӱ��*/
		for (int i = 0; i < size; i++)
		{
			node = queue[head++];
			/*ż���㵹����ӽڵ�ֵ��������������ӽڵ�ֵ*/
			index = (level % 2 == 0) ? size - i - 1 : i;
			res[*returnSize][index] = node->val;
			if (node->left != NULL)
			{
				queue[tail++] = node->left;
			}
			if (node->right != NULL)
			{
				queue[tail++] = node->right;
			}
		}
		/*����+1*/
		level++;
		/*��ά���������ָ��+1*/
		(*returnSize)++;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
