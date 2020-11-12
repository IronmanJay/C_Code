#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void flatten(struct TreeNode* root)
{
	/*递归跳出条件，找到叶子节点开始操作*/
	if (root == NULL)
	{
		return;
	}
	/*因为右子树还没修改的情况下不能修改根节点指向右子树的指针，所以使用后序遍历（后序遍历：左->右->根，最后修改根节点的指针）*/
	flatten(root->left);
	flatten(root->right);
	/*首先将当前节点的右子树保存*/
	struct TreeNode* tempNode = root->right;
	/*再将当前节点的右子树更新为左子树*/
	root->right = root->left;
	/*然后将当前节点的左子树置空*/
	root->left = NULL;
	/*最后将当前节点更新后的右子树与之前保存的右子树拼接*/
	while (root->right != NULL)
	{
		root = root->right;
	}
	root->right = tempNode;
	/*结束当前操作*/
	return;
}

/*主函数省略*/
