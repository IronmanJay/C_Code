#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

/*���Ľṹ*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	/*�������������ջ*/
	struct TreeNode** stackTree = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*MAXSIZE);
	/*������Ž��ֵ��ջ�����ﱣ�水�պ��������˳��Ľ��ֵ��*/
	struct TreeNode** stackNum = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*MAXSIZE);
	/*��Ž������*/
	int* res = (int*)malloc(sizeof(int)*MAXSIZE);
	/*���ֱ���*/
	int topTree = -1;
	int topNum = -1;
	int count = 0;
	/*�ȰѸ��ڵ���ջ��������Ϊ��׼��ʼ����*/
	stackTree[++topTree] = root;
	/*�����������ջ���յ�ʱ��˵����û��������*/
	while (topTree != -1)
	{
		/*����һ��Ԫ�ص���*/
		struct TreeNode* temp = stackTree[topTree--];
		/*�������ص㣬ÿ�ζ��Ѹ��ڵ�����ջ�����Ը��ڵ�϶������±ߣ�����ӡ����*/
		/*��ÿ���������ջһ��Ҫ����������ң���Ϊ����ջ����ջ���൱��˳��ߵ���һ��*/
		/*����˳�������->��->��*/
		if (temp != NULL)
		{
			stackNum[++topNum] = temp;
			stackTree[++topTree] = temp->left;
			stackTree[++topTree] = temp->right;
		}
	}
	/*����ջ��Ԫ�ؼ���������*/
	while (topNum != -1)
	{
		res[count++] = stackNum[topNum--]->val;
	}
	/*���ؽ��*/
	*returnSize = count;
	return res;
}

/*������ʡ��*/