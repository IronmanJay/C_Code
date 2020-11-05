#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/*������д�С�ͽ��������ֵ*/
#define MAXSIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	/*�пշ���*/
	if (root == NULL)
	{
		*returnSize = 0;
		return;
	}
	/*�������*/
	int** res = (int**)malloc(sizeof(int*)*MAXSIZE);
	/*�������ÿ�еĸ���*/
	*returnColumnSizes = (int*)malloc(sizeof(int)*MAXSIZE);
	/*����ÿһ����Ķ���*/
	struct TreeNode* queue[10000];
	/*����ͷָ��*/
	int front = 0;
	/*����βָ��*/
	int rear = 0;
	/*ͷ��������*/
	queue[rear++] = root;
	/*���Ĳ�����Ҳ�Ƿ��ؽ�����������*/
	int level = 0;
	/*��ʼ����*/
	while (front != rear)
	{
		/*��ǰ��Ľ�����*/
		int size = (rear - front % MAXSIZE);
		/*��ǰ�еĸ���*/
		(*returnColumnSizes)[level] = size;
		/*��ŵ�ǰ���������*/
		int* tempList = (int*)malloc(sizeof(int)*size);
		/*������ǰ�㣬����ǰ���ÿһ�����ֵ����������һ�еĽ�����飬������һ��Ľ�������У���Ϊֻ������ǰ��ĸ��������Բ�Ӱ����һ��ı���*/
		for (int i = 0; i < size; i++)
		{
			struct TreeNode* tempNode = queue[front++];
			tempList[i] = tempNode->val;
			if (tempNode->left != NULL)
			{
				queue[rear++] = tempNode->left;
			}
			if (tempNode->right != NULL)
			{
				queue[rear++] = tempNode->right;
			}
		}
		/*����ǰ��Ľ����뵽������飬��׼��������һ��*/
		res[level++] = tempList;
	}
	/*���ؽ�����������*/
	*returnSize = level;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
