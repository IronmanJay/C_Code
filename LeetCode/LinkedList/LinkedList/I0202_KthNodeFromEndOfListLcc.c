#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

int kthToLast(struct ListNode* head, int k)
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (k > 0)
	{
		fast = fast->next;
		k--;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->val;
}

int main(void)
{
	/*Ö÷º¯ÊıÊ¡ÂÔ*/
}
