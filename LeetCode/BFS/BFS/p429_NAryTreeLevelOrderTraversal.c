#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*������*/
struct Node
{
	int val;
	int numChildren;
	struct Node** children;
};

/*���г���*/
#define MAXSIZE 5000
/*����������г���*/
#define MAXROW 1000
/*���ÿһ��ڵ�Ķ���*/
struct Node* queue[MAXSIZE] = { 0 };

int** p429_NAryTreeLevelOrderTraversal_levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes)
{
	/*����������ָ��*/
	*returnSize = 0;
	/*�пշ���*/
	if (root == NULL)
	{
		*returnColumnSizes = NULL;
		return NULL;
	}
	/*�������*/
	int** res = (int**)malloc(sizeof(int*)*MAXROW);
	/*�������ÿ�е��г���*/
	*returnColumnSizes = (int*)malloc(sizeof(int) * MAXSIZE);
	/*����ͷָ��*/
	int head = 0;
	/*����βָ��*/
	int tail = 0;
	/*ͷ��������*/
	queue[tail++] = root;
	/*��ʼ����*/
	while (head != tail)
	{
		/*��ǰ��һ��Ľڵ������ʹ��ѭ������*/
		int size = (tail - head + MAXSIZE) % MAXSIZE;
		/*�������˳�򿪱ٶ�Ӧ��һ��ڵ����������ռ�*/
		res[returnSize[0]] = (int *)malloc(sizeof(int)*size);
		/*������������Ӧ�еĶ�Ӧ�г��ȣ�Ҳ���ǵ�ǰ��Ľڵ����*/
		returnColumnSizes[0][returnSize[0]] = size;
		/*��ǰ��һ���м����ڵ��ѭ�����Σ�ѭ����ÿһ���ڵ��ͬʱ�����ڵ�ֵ���뵽��ʱ�����У����⽫ÿһ���ڵ�ĺ��ӽڵ�����У���Ϊֻ���������е�ǰ��Ľڵ㣬���ԶԺ��ӣ���һ�㣩�Ľڵ㲻����Ӱ��*/
		for (int i = 0; i < size; i++) {
			/*ȡ������ͷ���*/
			struct Node* node = queue[head];
			/*ѭ�����У�ͷָ��+1*/
			head = (head + 1) % MAXSIZE;
			/*��������������鵱ǰ�е�����*/
			res[returnSize[0]][i] = node->val;
			/*�ҳ���ǰ��ÿһ���ڵ�ĺ��ӽڵ�*/
			for (int j = 0; j < node->numChildren; j++)
			{
				/*�������*/
				if (node->children[j])
				{
					/*�����еĺ��ӽڵ�����У��ȴ�����һ��ı���*/
					queue[tail] = node->children[j];
					/*ѭ�����У�βָ��+1*/
					tail = (tail + 1) % MAXSIZE;
				}
			}
		}
		/*��ǰ�������ϣ���ʼ������һ�㣬������������+1*/
		returnSize[0]++;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
