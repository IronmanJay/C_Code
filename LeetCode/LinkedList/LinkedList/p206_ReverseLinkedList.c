#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* p = head;
	struct ListNode* q = head->next;
	struct ListNode* temp;
	p->next = NULL;
	while (q != NULL)
	{
		temp = q->next;
		q->next = p;
		p = q;
		q = temp;
	}
	return p;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/
