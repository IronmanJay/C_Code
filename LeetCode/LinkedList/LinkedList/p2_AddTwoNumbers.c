#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *fakeNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	fakeNode->val = -1;
	fakeNode->next = NULL;
	struct ListNode *curNode = fakeNode;
	int carry = 0;
	while (l1 != NULL || l2 != NULL)
	{
		int x = (l1 == NULL) ? 0 : l1->val;
		int y = (l2 == NULL) ? 0 : l2->val;
		int sum = x + y + carry;
		carry = sum / 10;
		sum %= 10;
		struct ListNode *tempNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		tempNode->val = sum;
		tempNode->next = NULL;
		curNode->next = tempNode;
		curNode = curNode->next;
		if (l1 != NULL)
		{
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			l2 = l2->next;
		}
	}
	if (carry > 0)
	{
		struct ListNode *tempNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		tempNode->val = carry;
		tempNode->next = NULL;
		curNode->next = tempNode;
		curNode = curNode->next;
	}
	return fakeNode->next;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/
