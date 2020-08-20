#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*树的结构*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*定义栈和数组最大值*/
#define MAXSIZE 100

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	/*初始化栈*/
	struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAXSIZE);
	/*新建结果数组*/
	int* res = (int*)malloc(sizeof(int) * MAXSIZE);
	/*栈顶指针*/
	int top = -1;
	/*结果数组指针*/
	*returnSize = 0;
	/*判空返回*/
	if (root == NULL)
	{
		return res;
	}
	/*将头节点入栈，方便后续遍历*/
	stack[++top] = root;
	/*开始遍历*/
	while (top != -1)
	{
		/*取出栈首元素，每次遍历的新节点都相当于root节点，就相当于前序遍历的“根”*/
		root = stack[top--];
		/*将栈首元素值加入结果数组*/
		res[(*returnSize)++] = root->val;
		/*说明：这里虽然加入顺序是“右”->“左”，但弹出遍历是“左”->“右”，符合“根”->“左”->“右”的前序遍历*/
		/*先加入右节点，在栈尾，所以每次后遍历这个节点值，就相当于前序遍历的“右”*/
		if (root->right != NULL)
		{
			stack[++top] = root->right;
		}
		/*后加入左节点，在栈顶，所以每次先遍历这个节点值，就相当于前序遍历的“左”*/
		if (root->left != NULL)
		{
			stack[++top] = root->left;
		}
	}
	/*直接返回结果数组*/
	return res;
}

/*主函数省略*/
