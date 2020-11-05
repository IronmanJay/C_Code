#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
	struct Node* next;
};

struct Node* connect(struct Node* root)
{
	/*�пշ���*/
	if (root == NULL)
	{
		return root;
	}
	/*���ÿ��Ľ��Ķ���*/
	struct Node** queue = (struct Node*)malloc(sizeof(struct Node) * 10000);
	/*����ͷָ��*/
	int front = 0;
	/*����βָ��*/
	int rear = 0;
	/*ͷ��������*/
	queue[rear++] = root;
	/*��ʼѭ��*/
	while (front != rear)
	{
		/*��ǰ��Ľ�����*/
		int size = (rear - front % 10000);
		/*������ǰ��*/
		while (size > 0)
		{
			/*��ǰ��ÿһ�����*/
			struct Node* tempNode = queue[front++];
			/*�������ǰ������һ������ˣ�ָ��գ������ָ����һ��Ľ��*/
			if (size == 1)
			{
				tempNode->next = NULL;
			}
			/*���û����ǰ�����һ����㣬����ָ����*/
			else
			{
				tempNode->next = queue[front];
			}
			/*���ӽ�㲻Ϊ�������*/
			if (tempNode->left != NULL)
			{
				queue[rear++] = tempNode->left;
			}
			/*���ӽ�㲻Ϊ�������*/
			if (tempNode->right != NULL)
			{
				queue[rear++] = tempNode->right;
			}
			/*��ǰ��Ľ�����-1*/
			size--;
		}
	}
	/*���ؽ��*/
	return root;
}

/*������ʡ��*/
