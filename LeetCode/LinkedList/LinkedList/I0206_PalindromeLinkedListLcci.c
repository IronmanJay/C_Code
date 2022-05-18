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
	/*�пշ���*/
	if (head == NULL)
	{
		return true;
	}
	/*��ָ��*/
	struct ListNode* slow = head;
	/*��ָ��*/
	struct ListNode* fast = head;
	/*ǰ�������ָ��*/
	struct ListNode* preNode = NULL;
	/*��ʱ�ڵ�*/
	struct ListNode* newNode = NULL;
	/*�ҵ��м�ڵ��ͬʱ����תǰ�������*/
	while (fast != NULL && fast->next != NULL)
	{
		newNode = slow;
		slow = slow->next;
		fast = fast->next->next;
		newNode->next = preNode;
		preNode = newNode;
	}
	/*���������Ϊ�������������м�ڵ㣬ֱ�ӴӺ��ο�ʼ*/
	if (fast != NULL)
	{
		slow = slow->next;
	}
	/*�Ƚ�ǰ��κͺ��Σ�����в�һ���ľͷ���false*/
	while (slow != NULL)
	{
		if (slow->val != preNode->val)
		{
			return false;
		}
		slow = slow->next;
		preNode = preNode->next;
	}
	/*�����һ������true*/
	return true;
}

/*������ʡ��*/
