#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*���Ľṹ��*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*ȫ�ֱ�����arrIndex����ָ��ǰ�ڵ��������е���һ��λ��*/
int arrIndex;

struct TreeNode* getTree(char *S, int depth)
{
	/*�Ȼ�ȡ�ϴε���������ֵ�������￪ʼ*/
	int begin = arrIndex;
	/*level��ʾ�������*/
	int level = 0;
	/*��ȡ��ǰ�ڵ����ȣ�����Ҫ��begin��ʼ����ʾ����һ���ڵ����һ��λ�ÿ�ʼ��*/
	while (begin < strlen(S) && S[begin] == '-')
	{
		level++;
		begin++;
	}
	/*����õ�����Ⱥʹ������Ȳ�ͬ��ֱ�ӷ��أ�����������ǵ�ĳһ��Ҷ�ӽڵ���*/
	if (level != depth)
	{
		return NULL;
	}
	/*����arrIndex��ֵΪ��ǰ�ڵ��������е�λ�ã������´α���*/
	arrIndex = begin;
	/*�õ���ǰ�ڵ��ֵ*/
	int curValue = 0;
	while (arrIndex < strlen(S))
	{
		/*�����ǰ�ڵ�ֵ����һ��λ��Ϊ��-������ֹѭ��*/
		if (!isdigit(S[arrIndex]))
		{
			break;
		}
		curValue = curValue * 10 + S[arrIndex] - '0';
		arrIndex++;
	}
	/*�����½ڵ�*/
	struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = curValue;
	/*��Ϊ��ĿҪ�����������ӽڵ㣬�����ȵݹ����ӽڵ㣬ͬʱ���+1*/
	root->left = getTree(S, depth + 1);
	/*������ӽڵ�Ϊ�գ���ô���ӽڵ�Ҳ�϶�Ϊ�գ�˵������Ҷ�ӽڵ�*/
	if (root->left == NULL)
	{
		root->right = NULL;
	}
	/*������ӽڵ㲻Ϊ�գ���ô�����ݹ����ӽڵ㣬ͬʱ���+1*/
	else
	{
		root->right = getTree(S, depth + 1);
	}
	/*���ظ��ڵ㼴��*/
	return root;
}

struct TreeNode* recoverFromPreorder(char *S)
{
	/*��ʼ��arrIndex��ֵ*/
	arrIndex = 0;
	/*�����Ϊ0��ʼ����*/
	return getTree(S, 0);
}

/*������ʡ��*/
