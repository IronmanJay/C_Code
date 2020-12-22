#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*树的结构体*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int p129_SumRootToLeafNumbers_getRes(struct TreeNode* root, int sum)
{
	/*空结点直接返回0*/
	if (root == NULL)
	{
		return 0;
	}
	/*如果是叶子结点那么就意味着找到了一条路径，将之前路径的状态值*10+当前结点值就是这条路径的值*/
	if (root->left == NULL && root->right == NULL)
	{
		return sum * 10 + root->val;
	}
	/*如果是非叶子结点继续向左右递归，传入当前路径的状态值，方便下一个结点递归相加计算新的路径的状态值，最后递归结束就是左子树和右子树的值，相加就是结果*/
	return p129_SumRootToLeafNumbers_getRes(root->left, sum * 10 + root->val) + p129_SumRootToLeafNumbers_getRes(root->right, sum * 10 + root->val);

}

int sumNumbers(struct TreeNode* root)
{
	return p129_SumRootToLeafNumbers_getRes(root, 0);
}

/*主函数省略*/
