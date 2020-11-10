#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/*��Ϊ����������һ��ֵ̫�����ˣ�������long����*/
long min = LONG_MIN;

/*��ΪLeetCode����Ļ��ƣ�ȫ�ֱ��������ã���������ݹ��ǳ������岿��*/
bool isValidDFS(struct TreeNode* root)
{
	/*�пշ��أ�Ҳ�ǵݹ����ֹ��������Ϊ����Ҳ����������������Է���true*/
	if (root == NULL)
	{
		return true;
	}
	/*�ݹ鵽������������һ���ڵ㣬�������Ϊ��������ĵ�һ��������С�ģ�������֤�˿����������Ƿ����򼴿�*/
	if (isValidDFS(root->left))
	{
		/*�жϵ�ǰ����Ƿ�Ϊ��ǰ״̬��С�ģ���Ϊ������������֤���ڵ�������ӽڵ㣬ͬʱС�����ӽ�㣬��������ݹ飬����Ӧ���ж��Ƿ�С��*/
		if (min < root->val)
		{
			/*�����������������˵����ǰ�������ϸ񣬸��µ�ǰ��Сֵ����ʵmin���Ƕ������������ڵ��ǰһ����㣬Ҳ�Ƕ�Ӧ�������鵱ǰ���ֵ�ǰһ�����֣���Ȼ����Ϊ��ǰֵΪ��С*/
			min = root->val;
			/*��ʼ�ɴ˸��ڵ����ҵݹ飬��������*/
			return isValidDFS(root->right);
		}
	}
	/*������ϸ񷵻�false*/
	return false;
}

bool isValidBST(struct TreeNode* root)
{
	/*��ΪLeetCode����Ļ��ƣ�ȫ�ֱ��������ã�������������������һ��*/
	min = LONG_MIN;
	/*���ؽ��*/
	return isValidDFS(root);
}

/*������ʡ��*/
