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

bool hasPathSum(struct TreeNode* root, int sum)
{
	/*判空返回，也是递归的返回条件，要写在上面，如果写在下面可能有空指针异常，因为下面的判断直接使用了，并没判断是否存在*/
	if (root == NULL)
	{
		return false;
	}
	/*当前剩余值和结点值相等且当前结点为根结点说明找到了一条路径*/
	if (sum - root->val == 0 && root->left == NULL && root->right == NULL)
	{
		return true;
	}
	/*分别向左右子树递归，找到一条路径即可*/
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
