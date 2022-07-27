#include<stdio.h>
#include<stdbool.h>

/*树的结构体*/
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void preOrder(struct TreeNode* root, int* nums, int* count)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->left == NULL && root->right == NULL)
	{
		nums[*count] = root->val;
		*count = *count + 1;
	}
	preOrder(root->left, nums, count);
	preOrder(root->right, nums, count);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
	int nums1[201];
	int nums2[201];
	int count1 = 0;
	int count2 = 0;
	preOrder(root1, nums1, &count1);
	preOrder(root2, nums2, &count2);
	if (count1 != count2)
	{
		return false;
	}
	for (int i = 0; i < count1; i++)
	{
		if (nums1[i] != nums2[i])
		{
			return false;
		}
	}
	return true;
}

/*主函数省略*/
