#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

bool I0206_PalindromeLinkedListLcci_isPalindrome(struct ListNode* head)
{
	/*判空返回*/
	if (head == NULL)
	{
		return true;
	}
	/*慢指针*/
	struct ListNode* slow = head;
	/*快指针*/
	struct ListNode* fast = head;
	/*前半段链表指针*/
	struct ListNode* preNode = NULL;
	/*临时节点*/
	struct ListNode* newNode = NULL;
	/*找到中间节点的同时并反转前半段链表*/
	while (fast != NULL && fast->next != NULL)
	{
		newNode = slow;
		slow = slow->next;
		fast = fast->next->next;
		newNode->next = preNode;
		preNode = newNode;
	}
	/*如果链表长度为奇数，不考虑中间节点，直接从后半段开始*/
	if (fast != NULL)
	{
		slow = slow->next;
	}
	/*比较前半段和后半段，如果有不一样的就返回false*/
	while (slow != NULL)
	{
		if (slow->val != preNode->val)
		{
			return false;
		}
		slow = slow->next;
		preNode = preNode->next;
	}
	/*如果都一样返回true*/
	return true;
}

/*主函数省略*/
