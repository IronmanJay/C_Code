#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b)) /*判断大小*/
#define LEN 1000 /*定义数组长度*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void getMaxValue(struct TreeNode* root, int* res, int level, int* returnSize)
{
	/*如果当前节点为空直接返回*/
	if (root == NULL)
	{
		return;
	}
	/*如果来到了下一个节点，直接加入，这里判断条件是层数和数组元素个数，如果两者相等，说明层数已经+1了，那么把当前节点加入即可，另外，数组长度相应+1*/
	if (*returnSize == level)
	{
		res[level] = root->val;
		*returnSize += 1;
	}
	/*如果进入这里，说明来到了兄弟节点，那么就要比较两个兄弟节点谁大，把大的放到结果数组，level就是结果数组的位置索引，代表每一层的最大值*/
	else
	{
		res[level] = MAX(res[level], root->val);
	}
	/*分別向左右递归，每次递归层数+1，说明递归的是下一层*/
	getMaxValue(root->left, res, level + 1, returnSize);
	getMaxValue(root->right, res, level + 1, returnSize);
}

int* largestValues(struct TreeNode* root, int* returnSize)
{
	/*数组长度初始化为0*/
	*returnSize = 0;
	/*开辟数组*/
	int* res = (int *)malloc(LEN * sizeof(int));
	/*如果为空直接返回空*/
	if (root == NULL)
	{
		return NULL;
	}
	/*调用函数开始递归，这里level代表层数，从0层开始和数组开始位置一样，注意，每一层只留一个元素*/
	getMaxValue(root, res, 0, returnSize);
	/*返回结果*/
	return res;
}

/*主函数省略*/
