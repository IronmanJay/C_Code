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
	/*递归跳出条件，已经无法建立二叉搜索树的头结点*/
	if (left > right)
	{
		return NULL;
	}
	/*得到中间值*/
	int mid = left + (right - left) / 2;
	/*新建二叉搜索树的头结点*/
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = nums[mid];
	/*向左递归遍历*/
	root->left = p108_ConvertSortedArrayToBinarySearchTree_getTree(nums, left, mid - 1);
	/*向右递归遍历*/
	root->right = p108_ConvertSortedArrayToBinarySearchTree_getTree(nums, mid + 1, right);
	/*返回二叉搜索树的头结点*/
	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	/*判空返回*/
	if (numsSize == 0)
	{
		return NULL;
	}
	/*因为二叉搜索树根节点为数组（已排序）中间值，所以分别向左向右递归得到左右子树即可*/
	return p108_ConvertSortedArrayToBinarySearchTree_getTree(nums, 0, numsSize - 1);
}

/*主函数省略*/
