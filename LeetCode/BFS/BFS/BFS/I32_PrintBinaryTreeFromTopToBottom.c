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


int main(void)
{
	/*�˴��������ʾ��*/
	struct TreeNode* root;
	root->val = 3;
	struct TreeNode* left1;
	left1->val = 9;
	struct TreeNode* right1;
	right1->val = 20;
	struct TreeNode* right2;
	right2->val = 15;
	struct TreeNode* right3;
	right3->val = 8;
	root->left = left1;
	root->right = right1;
	right1->left = right2;
	right1->right = right3;
	int* returnSize = 0;
	int** retrunCoumnSizes = 0;
	int** res = levelOrder(root, returnSize, retrunCoumnSizes);
	printf(res);
	getchar();

}
