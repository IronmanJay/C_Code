#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

/*树的结构*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	/*创建存放树结点的栈*/
	struct TreeNode** stackTree = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*MAXSIZE);
	/*创建存放结点值的栈（这里保存按照后序遍历的顺序的结点值）*/
	struct TreeNode** stackNum = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*MAXSIZE);
	/*存放结果数组*/
	int* res = (int*)malloc(sizeof(int)*MAXSIZE);
	/*各种变量*/
	int topTree = -1;
	int topNum = -1;
	int count = 0;
	/*先把根节点入栈，以树根为基准开始遍历*/
	stackTree[++topTree] = root;
	/*当存放树结点的栈不空的时候说明还没遍历结束*/
	while (topTree != -1)
	{
		/*将第一个元素弹出*/
		struct TreeNode* temp = stackTree[topTree--];
		/*这里是重点，每次都把根节点入数栈，所以根节点肯定是最下边，最后打印输入*/
		/*而每次入树结点栈一定要按照先左后右，因为出树栈入数栈，相当于顺序颠倒了一下*/
		/*最后的顺序就是左->右->根*/
		if (temp != NULL)
		{
			stackNum[++topNum] = temp;
			stackTree[++topTree] = temp->left;
			stackTree[++topTree] = temp->right;
		}
	}
	/*将数栈中元素加入结果数组*/
	while (topNum != -1)
	{
		res[count++] = stackNum[topNum--]->val;
	}
	/*返回结果*/
	*returnSize = count;
	return res;
}

/*主函数省略*/