#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*树的结构体*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*全局变量，arrIndex总是指向当前节点在数组中的下一个位置*/
int arrIndex;

struct TreeNode* getTree(char *S, int depth)
{
	/*先获取上次的数组索引值，从这里开始*/
	int begin = arrIndex;
	/*level表示树的深度*/
	int level = 0;
	/*获取当前节点的深度，这里要从begin开始，表示从上一个节点的下一个位置开始找*/
	while (begin < strlen(S) && S[begin] == '-')
	{
		level++;
		begin++;
	}
	/*如果得到的深度和传入的深度不同，直接返回，这种情况就是到某一个叶子节点了*/
	if (level != depth)
	{
		return NULL;
	}
	/*更新arrIndex的值为当前节点在数组中的位置，方便下次遍历*/
	arrIndex = begin;
	/*得到当前节点的值*/
	int curValue = 0;
	while (arrIndex < strlen(S))
	{
		/*如果当前节点值的下一个位置为‘-’，终止循环*/
		if (!isdigit(S[arrIndex]))
		{
			break;
		}
		curValue = curValue * 10 + S[arrIndex] - '0';
		arrIndex++;
	}
	/*创建新节点*/
	struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = curValue;
	/*因为题目要求尽量生成左子节点，所以先递归左子节点，同时深度+1*/
	root->left = getTree(S, depth + 1);
	/*如果左子节点为空，那么右子节点也肯定为空，说明到了叶子节点*/
	if (root->left == NULL)
	{
		root->right = NULL;
	}
	/*如果左子节点不为空，那么继续递归右子节点，同时深度+1*/
	else
	{
		root->right = getTree(S, depth + 1);
	}
	/*返回根节点即可*/
	return root;
}

struct TreeNode* recoverFromPreorder(char *S)
{
	/*初始化arrIndex的值*/
	arrIndex = 0;
	/*从深度为0开始遍历*/
	return getTree(S, 0);
}

/*主函数省略*/
