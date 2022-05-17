#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* fakeNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	fakeNode->val = -1;
	fakeNode->next = head;
	struct ListNode* p = fakeNode;
	while (p->next != NULL)
	{
		if (p->next->val == val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	return fakeNode->next;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/
