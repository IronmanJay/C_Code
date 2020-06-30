#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* resHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* res = resHead;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			res->next = l1;
			l1 = l1->next;
		}
		else
		{
			res->next = l2;
			l2 = l2->next;
		}
		res = res->next;
	}
	res->next = l1 == NULL ? l2 : l1;
	return resHead->next;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/
