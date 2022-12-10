#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwo(struct ListNode* p, struct ListNode* q)
{
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->val = 0;
	dummy->next = NULL;
	struct ListNode* temp = dummy;
	while (p != NULL && q != NULL)
	{
		if (p->val < q->val)
		{
			temp->next = p;
			p = p->next;
		}
		else
		{
			temp->next = q;
			q = q->next;
		}
		temp = temp->next;
	}
	if (p != NULL)
	{

		temp->next = p;
	}
	if (q != NULL)
	{
		temp->next = q;
	}
	return dummy->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
	struct ListNode* res = NULL;
	for (int i = 0; i < listsSize; i++)
	{
		res = mergeTwo(res, lists[i]);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/