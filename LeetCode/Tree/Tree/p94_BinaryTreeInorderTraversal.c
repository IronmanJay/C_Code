#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	/*返回长度*/
	*returnSize = 0;
	/*结果数组*/
	int* res = (int*)malloc(sizeof(int) * 501);
	/*栈存放结点*/
	struct TreeNode** stack = (struct TreeNode*)malloc(sizeof(struct TreeNode*) * 501);
	/*栈指针*/
	int top = -1;
	/*第一个判断条件是为了将头结点入栈而且还判断每次更新root为右子结点为空时遍历中间结点，第二个判断条件是为了遍历整个树*/
	while (root != NULL || top != -1)
	{
		/*将某个结点的全部左子树的左节点全部入栈，因为中序遍历是左->中->右*/
		while (root != NULL)
		{
			stack[++top] = root;
			root = root->left;
		}
		/*此时开始弹出，弹出的就是此时这个子树的左子结点*/
		root = stack[top--];
		/*将值加入到结果数组*/
		res[(*returnSize)++] = root->val;
		/*然后更新root为右子结点，因为中间结点已经在栈中了，所以最后放入右子结点，形成了左->中->右的顺序，更新后的右子结点同样按照先将右子结点的全部左子树的左节点全部入栈*/
		root = root->right;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
