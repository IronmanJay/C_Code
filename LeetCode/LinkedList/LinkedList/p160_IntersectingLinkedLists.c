#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode *p = headA, *q = headB;
	int lenA = 0, lenB = 0, sub;
	while (p != NULL)
	{
		lenA++;
		p = p->next;
	}
	while (q != NULL)
	{
		lenB++;
		q = q->next;
	}
	p = headA;
	q = headB;
	sub = (lenA - lenB) >= 0 ? lenA - lenB : lenB - lenA;
	if (lenA > lenB)
	{
		while (sub != 0)
		{
			p = p->next;
			sub--;
		}
	}
	else
	{
		while (sub != 0)
		{
			q = q->next;
			sub--;
		}
	}
	while (q != NULL && p != NULL)
	{
		if (p == q)
		{
			return p;
		}
		p = p->next;
		q = q->next;
	}
	return NULL;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/