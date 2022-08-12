#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int stack1[101] = { 0 };
	int stack2[101] = { 0 };
	int top1 = 0;
	int top2 = 0;
	int carry = 0;
	struct ListNode* temp = NULL;
	struct ListNode* head = NULL;
	while (l1 != NULL)
	{
		stack1[top1++] = l1->val;
		l1 = l1->next;
	}
	while (l2 != NULL)
	{
		stack2[top2++] = l2->val;
		l2 = l2->next;
	}
	while (top1 != 0 || top2 != 0 || carry != 0)
	{
		int x = top1 > 0 ? stack1[--top1] : 0;
		int y = top2 > 0 ? stack2[--top2] : 0;
		int sum = x + y + carry;
		carry = sum / 10;
		head = (struct ListNode*)malloc(sizeof(struct ListNode));
		head->val = sum % 10;
		head->next = temp;
		temp = head;
	}
	return head;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/