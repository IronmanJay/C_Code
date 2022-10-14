#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverse_p143_ReorderList(struct ListNode* head)
{
	struct ListNode* dummyHead = NULL;
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		struct ListNode* temp = cur->next;
		cur->next = dummyHead;
		dummyHead = cur;
		cur = temp;
	}
	return dummyHead;
}

void merge(struct ListNode* h1, struct ListNode* h2)
{
	struct ListNode* temp1;
	struct ListNode* temp2;
	while (h1 != NULL && h2 != NULL)
	{
		temp1 = h1->next;
		temp2 = h2->next;
		h1->next = h2;
		h1 = temp1;
		h2->next = h1;
		h2 = temp2;
	}
}

void reorderList(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	struct ListNode* l1 = head;
	struct ListNode* l2 = slow->next;
	slow->next = NULL;
	l2 = reverse_p143_ReorderList(l2);
	merge(l1, l2);
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/