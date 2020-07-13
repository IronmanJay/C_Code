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

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	/*����������ڵ㶼Ϊ��˵����˵����ǰ�ݹ鵽���ˣ���εݹ鷵��true*/
	if (p == NULL && q == NULL)
	{
		return true;
	}
	/*����������ڵ�������һ��Ϊ�գ�˵����������ǰ�ڵ㲻��ȣ���εݹ鷵��false*/
	if (p == NULL || q == NULL)
	{
		return false;
	}
	/*����������ڵ�ֵ����ͬ��˵����������ǰ��㲻��ȣ���εݹ鷵��false*/
	if (p->val != q->val)
	{
		return false;
	}
	/*�ֱ���������ҵݹ飬���������true��˵����������ͬ*/
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(void)
{
	/*������ʡ��*/
}
