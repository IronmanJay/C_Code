#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*定义树*/
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void BFS(struct TreeNode **queueArr, int start, int end, int* returnSize, int** returnColumnSizes, int **retArr)
{
	int i;
	int flagStart = start;
	int flagEnd = end;
	int levelNum = end - start;
	/*如果队列为空，则返回*/
	if (levelNum == 0) {
		return;
	}
	/*记录本层元素数量*/
	(*returnColumnSizes)[*returnSize] = levelNum;
	/*为本层返回数组申请内存*/
	retArr[*returnSize] = (int *)malloc(sizeof(int) * levelNum);
	/*填充该层返回数组内容*/
	for (i = 0; i < levelNum; i++) {
		retArr[*returnSize][i] = queueArr[start + i]->val;
	}
	/*层数++*/
	(*returnSize)++;
	/*将该层节点的子节点装入队列，注意判断子节点是否存在，该步也是广度优先遍历的重点*/
	for (i = flagStart; i < flagEnd; i++) {
		if (queueArr[start]->left != NULL) {
			queueArr[end++] = queueArr[start]->left;

		} if (queueArr[start]->right != NULL) {
			queueArr[end++] = queueArr[start]->right;
		}
		start++;
	}
	/*继续遍历队列中的节点*/
	BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);

	return;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	if (root == NULL) {
		return NULL;
	}
	/*为返回数组申请内存*/
	int **retArr = (int **)malloc(sizeof(int *) * 10000);
	memset(retArr, 0, sizeof(int *) * 10000);
	/*为模拟队列的数组申请内存，要稍微大一点*/
	struct TreeNode *queueArr[10000] = { { 0 } };
	/*为储存返回组每一列大小的数组申请内存*/
	*returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
	/*将根节点放入队列*/
	queueArr[0] = root;
	/*用start和end下标模拟进队出队*/
	int start = 0;
	int end = 1;
	/*广度优先遍历*/
	BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);
	/*返回结果*/
	return retArr;
}

/*主函数*/
int main(void)
{
	/*主函数内容省略，上面的算法是核心*/
}
