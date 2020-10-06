#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int val;
	int numChildren;
	struct Node** children;
};


int* maxDepth(struct Node* root)
{
	/*�пշ���*/
	if (root == NULL)
	{
		return 0;
	}
	/*���ÿһ��ڵ�ֵ�Ķ���*/
	struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 10000);
	/*����ͷָ��*/
	int head = 0;
	/*����βָ��*/
	int tail = 0;
	/*������ȣ����ֵ��*/
	int depth = 0;
	/*��ǰ��Ľڵ����*/
	int size = 0;
	/*���Ƚ����ڵ������*/
	queue[tail++] = root;
	struct Node* node = NULL;
	while (head < tail)
	{
		/*��ǰ��Ľڵ����*/
		size = (tail - head + 5000) % 5000;
		/*��ǰ���м����ڵ�ͱ�������*/
		for (int i = 0; i < size; i++)
		{
			/*����ȡ������������һ���ÿһ���ڵ�*/
			node = queue[head++];
			/*����һ������нڵ�����У���Ϊ�˴α���ֻ��ѭ����ǰ��ĸ��������Զ���һ��û��Ӱ�죬�ȴ�����һ��ı���*/
			for (int j = 0; j < node->numChildren; j++)
			{
				queue[tail++] = node->children[j];
			}
		}
		/*��ǰ�������֮�����Ĳ���+1*/
		depth++;
	}
	/*���ؽ��*/
	return depth;
}

/*������ʡ��*/
