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

/*结果数组索引，一定要写成全局变量，因为递归时这个索引不能回溯，要一直往前走*/
int resIndex;

void getRes(struct TreeNode* root, int sum, int** res, int* path, int pathIndex, int* returnColumn)
{

	/*递归跳出条件，到了叶子节点还没有满足条件的直接返回*/
	if (root == NULL)
	{
		return;
	}
	/*每个路径都先加入*/
	path[pathIndex++] = root->val;
	/*某个结点的值等于此叶子结点的值，就找到了一条路径*/
	if (sum - root->val == 0 && root->left == NULL && root->right == NULL)
	{
		/*注意这里要拷贝内存地址，不能直接把地址引用加入到res中*/
		int* temp = (int*)malloc(sizeof(int)*pathIndex);
		memcpy(temp, path, sizeof(int)*pathIndex);
		res[resIndex] = temp;
		returnColumn[resIndex] = pathIndex;
		resIndex++;
	}
	/*向左子树递归*/
	getRes(root->left, sum - root->val, res, path, pathIndex, returnColumn);
	/*向右子树递归*/
	getRes(root->right, sum - root->val, res, path, pathIndex, returnColumn);
	/*回溯，向父结点的下一个结点继续递归*/
	pathIndex--;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
	/*结果数组*/
	int** res = (int**)malloc(sizeof(int*) * 2001);
	/*结果数组索引初始化*/
	resIndex = 0;
	/*路经数组*/
	int* path = (int*)malloc(sizeof(int) * 2001);
	/*路经数组索引*/
	int pathIndex = 0;
	/*结果数组每一行索引*/
	int* returnColumn = (int*)malloc(sizeof(int) * 2001);
	/*开始递归*/
	getRes(root, sum, res, path, pathIndex, returnColumn);
	/*结果数组每一行的长度*/
	*returnColumnSizes = returnColumn;
	/*结果数组的长度*/
	*returnSize = resIndex;
	/*返回结果*/
	return res;
}

/*主函数省略*/
