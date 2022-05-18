#include<stdio.h>
#include<stdbool.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

bool p234_PalindromicLinkedList_isPalindrome(struct ListNode* head)
{
	struct ListNode *slow = head, *fast = head, *pre = NULL, *temp = NULL;
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next ? fast->next->next : fast->next;
	}
	while (slow != NULL)
	{
		temp = slow->next;
		slow->next = pre;
		pre = slow;
		slow = temp;
	}
	while (head != NULL && pre != NULL)
	{
		if (head->val != pre->val)
		{
			return false;
		}
		head = head->next;
		pre = pre->next;
	}
	return true;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/