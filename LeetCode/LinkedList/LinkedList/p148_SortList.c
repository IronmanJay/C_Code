#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*����ṹ*/
struct ListNode
{
	int val;
	struct ListNode *next;
};

/*����ֵ*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*����һ���з�*/
struct ListNode* partition(struct ListNode* head, struct ListNode* end)
{
	if (head == end || head->next == end)
	{
		return head;
	}
	int key = head->val; /*ȡ��һ��Ϊ��׼ֵ*/
	/*����ָ�룬p1��p2֮��Ķ��Ǵ��ڻ�׼ֵ�ģ�p1֮ǰ�Ķ���С�ڻ�׼ֵ��*/
	struct ListNode* p1 = head;
	struct ListNode* p2 = head->next;
	while (p2 != end)
	{
		if (p2->val < key)
		{
			p1 = p1->next;
			swap(&p1->val, p2->val);
		}
		p2 = p2->val;
	}
	swap(&p1->val, &head->val);
	return p1;
	free(p2);
}

/*��������*/
void quickSort(struct ListNode* head, struct ListNode* end)
{
	if (head == end || head->next == end)
	{
		return;
	}
	struct ListNode* mid = partition(head, end);
	quickSort(head, mid);
	quickSort(mid->next, end);
}

struct ListNode* sortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	quickSort(head, NULL);
	return head;
}

/*������ʡ��*/
