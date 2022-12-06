#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

int getDecimalValue(struct ListNode* head)
{
	struct ListNode* p = head;
	int res = 0;
	while (p != NULL)
	{
		res = res * 2 + p->val;
		p = p->next;
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/