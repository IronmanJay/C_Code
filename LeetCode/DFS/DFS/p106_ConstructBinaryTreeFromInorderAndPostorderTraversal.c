#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/**
 * @inLeft 中序序列左右子树开始位置
 * @inRight 中序序列左右子树结束位置
 * @postLeft 后序序列左右子树开始位置，根据中序序列的左右子树长度判断
 * @postRight 后序序列左右子树结束位置，根据中序序列的左右子树长度判断
 * @inorder 中序序列
 * @postorder 后序序列
 */
struct TreeNode* getTree(int inLeft, int inRight, int postLeft, int postRight, int* inorder, int* postorder)
{
	/*判空返回，说明中序遍历的左右子树无法再构建一个新的树，跳出递归*/
	if (inLeft > inRight)
	{
		return NULL;
	}
	/*新建根节点，后序遍历的最后一个结点就是根节点*/
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = postorder[postRight];
	/*中序遍历找到根节点，左边索引到根节点位置就是左子树个数*/
	int inRoot = inLeft;
	while (inRoot <= inRight && inorder[inRoot] != root->val)
	{
		inRoot++;
	}
	int leftLen = inRoot - inLeft;
	/*向左划分并递归构建左子树*/
	root->left = getTree(inLeft, inRoot - 1, postLeft, postLeft + leftLen - 1, inorder, postorder);
	/*向右划分递归构建右子树*/
	root->right = getTree(inRoot + 1, inRight, postLeft + leftLen, postRight - 1, inorder, postorder);
	/*每次递归返回一个新的结点*/
	return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
	/*递归根据中序和后序遍历创建树*/
	return getTree(0, inorderSize - 1, 0, postorderSize - 1, inorder, postorder);
}

/*主函数省略*/
