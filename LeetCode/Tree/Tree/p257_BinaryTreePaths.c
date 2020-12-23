#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void p257_BinaryTreePaths_getRes(struct TreeNode* root, char** res, int* returnSize, int* path, int pathIndex)
{
	/*空结点返回NULL*/
	if (root == NULL)
	{
		return NULL;
	}
	/*遇到叶子结点把这条路径放到结果数组中*/
	if (root->left == NULL && root->right == NULL)
	{
		char* temp = (char*)malloc(sizeof(char*) * 1001);
		int len = 0;
		for (int i = 0; i < pathIndex; i++)
		{
			len += sprintf(temp + len, "%d->", path[i]);
		}
		sprintf(temp + len, "%d", root->val);
		res[(*returnSize)++] = temp;
	}
	/*如果不是叶子节点加入到路经数组中*/
	else
	{
		path[pathIndex++] = root->val;
	}
	/*向左子树递归*/
	p257_BinaryTreePaths_getRes(root->left, res, returnSize, path, pathIndex);
	/*向右子树递归*/
	p257_BinaryTreePaths_getRes(root->right, res, returnSize, path, pathIndex);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
	/*结果数组*/
	char** res = (char**)malloc(sizeof(char*) * 1001);
	/*结果数组指针，也是返回的结果数组长度*/
	*returnSize = 0;
	/*存放路径数组*/
	int path[1001];
	/*路经数组指针*/
	int pathIndex = 0;
	/*开始递归*/
	p257_BinaryTreePaths_getRes(root, res, returnSize, path, pathIndex);
	/*返回结果*/
	return res;
}

/*主函数省略*/
