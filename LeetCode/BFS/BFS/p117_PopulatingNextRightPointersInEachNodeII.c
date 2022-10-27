#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	struct Node *left;
	struct Node *right;
	struct Node *next;
};

struct Node* connect(struct Node* root)
{
	if (root == NULL)
	{
		return root;
	}
	struct Node* cur = root;
	while (cur != NULL)
	{
		struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
		dummy->next = NULL;
		struct Node* pre = dummy;
		while (cur != NULL)
		{
			if (cur->left != NULL)
			{
				pre->next = cur->left;
				pre = pre->next;
			}
			if (cur->right != NULL)
			{
				pre->next = cur->right;
				pre = pre->next;
			}
			cur = cur->next;
		}
		cur = dummy->next;
	}
	return root;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/