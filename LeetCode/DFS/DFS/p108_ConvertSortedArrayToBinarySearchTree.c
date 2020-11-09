#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* p108_ConvertSortedArrayToBinarySearchTree_getTree(int* nums, int left, int right)
{
	/*�ݹ������������Ѿ��޷�����������������ͷ���*/
	if (left > right)
	{
		return NULL;
	}
	/*�õ��м�ֵ*/
	int mid = left + (right - left) / 2;
	/*�½�������������ͷ���*/
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = nums[mid];
	/*����ݹ����*/
	root->left = p108_ConvertSortedArrayToBinarySearchTree_getTree(nums, left, mid - 1);
	/*���ҵݹ����*/
	root->right = p108_ConvertSortedArrayToBinarySearchTree_getTree(nums, mid + 1, right);
	/*���ض�����������ͷ���*/
	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	/*�пշ���*/
	if (numsSize == 0)
	{
		return NULL;
	}
	/*��Ϊ�������������ڵ�Ϊ���飨�������м�ֵ�����Էֱ��������ҵݹ�õ�������������*/
	return p108_ConvertSortedArrayToBinarySearchTree_getTree(nums, 0, numsSize - 1);
}

/*������ʡ��*/
