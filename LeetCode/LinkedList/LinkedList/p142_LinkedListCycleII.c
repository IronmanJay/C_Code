#include<stdio.h>
#include<stdbool.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (true)
	{
		if (fast == NULL || fast->next == NULL)
		{
			return NULL;
		}
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			break;
		}
	}
	fast = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/