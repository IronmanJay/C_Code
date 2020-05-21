#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*������*/
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
	/*�������Ϊ�գ��򷵻�*/
	if (levelNum == 0) {
		return;
	}
	/*��¼����Ԫ������*/
	(*returnColumnSizes)[*returnSize] = levelNum;
	/*Ϊ���㷵�����������ڴ�*/
	retArr[*returnSize] = (int *)malloc(sizeof(int) * levelNum);
	/*���ò㷵����������*/
	for (i = 0; i < levelNum; i++) {
		retArr[*returnSize][i] = queueArr[start + i]->val;
	}
	/*����++*/
	(*returnSize)++;
	/*���ò�ڵ���ӽڵ�װ����У�ע���ж��ӽڵ��Ƿ���ڣ��ò�Ҳ�ǹ�����ȱ������ص�*/
	for (i = flagStart; i < flagEnd; i++) {
		if (queueArr[start]->left != NULL) {
			queueArr[end++] = queueArr[start]->left;

		} if (queueArr[start]->right != NULL) {
			queueArr[end++] = queueArr[start]->right;
		}
		start++;
	}
	/*�������������еĽڵ�*/
	BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);

	return;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	if (root == NULL) {
		return NULL;
	}
	/*Ϊ�������������ڴ�*/
	int **retArr = (int **)malloc(sizeof(int *) * 10000);
	memset(retArr, 0, sizeof(int *) * 10000);
	/*Ϊģ����е����������ڴ棬Ҫ��΢��һ��*/
	struct TreeNode *queueArr[10000] = { { 0 } };
	/*Ϊ���淵����ÿһ�д�С�����������ڴ�*/
	*returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
	/*�����ڵ�������*/
	queueArr[0] = root;
	/*��start��end�±�ģ����ӳ���*/
	int start = 0;
	int end = 1;
	/*������ȱ���*/
	BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);
	/*���ؽ��*/
	return retArr;
}

/*������*/
int main(void)
{
	/*����������ʡ�ԣ�������㷨�Ǻ���*/
}
