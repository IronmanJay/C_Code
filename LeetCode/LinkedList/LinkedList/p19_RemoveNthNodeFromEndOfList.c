#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	/*ͷ�ڵ�ǰ�Ľڵ�*/
	struct ListNode* newHead = NULL;
	newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newHead->next = head;
	/*��ָ�룬��ֵΪͷ�ڵ㣬��֤һֱ����ָ�����n���ڵ�*/
	struct ListNode* fast = head;
	/*��ָ�룬��ֵΪͷ�ڵ�ǰ�Ľڵ㣬Ŀ���ǵ���ָ��ָ��β�ڵ�֮���λ��ʱ����ָ��ָ���ɾ���ڵ��ǰһ���ڵ�*/
	struct ListNode* slow = newHead;
	/*�ҵ���ָ�����ָ�����n���ڵ��λ��*/
	for (int i = 0; i < n; i++)
	{
		fast = fast->next;
	}
	/*����ָ��ָ��β�ڵ�֮���λ��ʱ����ָ��ָ���ɾ���ڵ��ǰһ���ڵ�*/
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	/*��ʱ��ָ��ָ���˴�ɾ������ǰһ���ڵ�����ôɾ����ɾ���ڵ�*/
	slow->next = slow->next->next;
	/*���ؽ��*/
	return newHead->next;
}

/*������ʡ��*/
