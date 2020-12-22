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

/*�������������һ��Ҫд��ȫ�ֱ�������Ϊ�ݹ�ʱ����������ܻ��ݣ�Ҫһֱ��ǰ��*/
int resIndex;

void getRes(struct TreeNode* root, int sum, int** res, int* path, int pathIndex, int* returnColumn)
{

	/*�ݹ���������������Ҷ�ӽڵ㻹û������������ֱ�ӷ���*/
	if (root == NULL)
	{
		return;
	}
	/*ÿ��·�����ȼ���*/
	path[pathIndex++] = root->val;
	/*ĳ������ֵ���ڴ�Ҷ�ӽ���ֵ�����ҵ���һ��·��*/
	if (sum - root->val == 0 && root->left == NULL && root->right == NULL)
	{
		/*ע������Ҫ�����ڴ��ַ������ֱ�Ӱѵ�ַ���ü��뵽res��*/
		int* temp = (int*)malloc(sizeof(int)*pathIndex);
		memcpy(temp, path, sizeof(int)*pathIndex);
		res[resIndex] = temp;
		returnColumn[resIndex] = pathIndex;
		resIndex++;
	}
	/*���������ݹ�*/
	getRes(root->left, sum - root->val, res, path, pathIndex, returnColumn);
	/*���������ݹ�*/
	getRes(root->right, sum - root->val, res, path, pathIndex, returnColumn);
	/*���ݣ��򸸽�����һ���������ݹ�*/
	pathIndex--;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
	/*�������*/
	int** res = (int**)malloc(sizeof(int*) * 2001);
	/*�������������ʼ��*/
	resIndex = 0;
	/*·������*/
	int* path = (int*)malloc(sizeof(int) * 2001);
	/*·����������*/
	int pathIndex = 0;
	/*�������ÿһ������*/
	int* returnColumn = (int*)malloc(sizeof(int) * 2001);
	/*��ʼ�ݹ�*/
	getRes(root, sum, res, path, pathIndex, returnColumn);
	/*�������ÿһ�еĳ���*/
	*returnColumnSizes = returnColumn;
	/*�������ĳ���*/
	*returnSize = resIndex;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
