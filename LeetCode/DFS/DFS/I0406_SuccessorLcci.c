#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*�������Ľṹ��*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*�������Ľṹ��*/
struct Result
{
	/*����ǰһ����㣬���pre�͵�ǰֵ��ȣ�˵��node���ǽ��*/
	struct TreeNode* pre;
	/*���淵�ؽ��*/
	struct TreeNode* res;
	/*/*��־λ�����Ϊtrue��ֹͣ�ݹ飬���ؽ��*/
	bool found;
};

void inorderTraver(struct TreeNode* node, struct TreeNode* p, struct Result* res)
{
	/*�����ǰ�ڵ�Ϊ��˵����������������foundΪtrue˵���ҵ���������*/
	if (node == NULL || res->found)
	{
		return;
	}
	/*������ӽ�㲻�գ����������ݹ�*/
	if (node->left != NULL)
	{
		inorderTraver(node->left, p, res);
	}
	/*�Ƚϵ�ǰ����ǰһ������Ƿ��p��ȣ������ȣ�˵����ǰ������Ҫ�ҵĽ��������־λ��Ϊtrue�����ؼ���*/
	if (res->pre == p)
	{
		res->res = node;
		res->found = true;
	}
	/*����pre����������ϰѵ�ǰ��㸳ֵ��pre����Ϊ��һ���ڵ��ǰһ�����*/
	res->pre = node;
	/*������������գ����������ݹ�*/
	if (node->right != NULL)
	{
		inorderTraver(node->right, p, res);
	}
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p)
{
	// ��ʼ������ṹ��
	struct Result* res = (struct Result*)malloc(sizeof(struct Result));
	res->pre = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	res->res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	res->found = false;
	/*��ʼ�ݹ�*/
	inorderTraver(root, p, res);
	/*�����־λΪfalse��û���ҵ�������NULL*/
	if (!res->found)
	{
		return NULL;
	}
	/*����ҵ����ؽ��*/
	return res->res;
}

/*������ʡ��*/
