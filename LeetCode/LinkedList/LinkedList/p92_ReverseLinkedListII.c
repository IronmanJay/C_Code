#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
	/*ָ��ͷ���Ľڵ�*/
	struct ListNode* newHead = NULL;
	newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newHead->next = head;
	/*����ת������λ��ǰ���ڵ㣬һֱָ�����ת�Ĳ��ֵ���λ*/
	struct ListNode* pre = newHead;
	/*�ҵ�����ת������λ��ǰ��λ��*/
	for (int i = 1; i < m; i++)
	{
		pre = pre->next;
	}
	/*����ת���ֵ���ʼ�ڵ㣬Ҳ�Ǵ���ת���ֵ�ָ�룬һֱ����ƶ�*/
	struct ListNode* start = pre->next;
	/*��������ת����*/
	for (int i = m; i < n; i++)
	{
		/*ÿ�α������ҵ�start����һ���ڵ㣬Ҳ����Ҫ���뵽ǰ�棨ͷ�����Ľڵ�*/
		struct ListNode* curNext = start->next;
		/*����ָ��start����һ���ڵ�ΪҪ���뵽ǰ�棨ͷ�����Ľڵ����һ���ڵ㣬��ʱҪ���뵽ǰ�棨ͷ�����Ľڵ��Ѿ�����*/
		start->next = curNext->next;
		/*��ʼ���뵽ǰ�棨ͷ����*/
		curNext->next = pre->next;
		/*����ת������λ��ǰ���ڵ�һֱָ�����ת�Ĳ��ֵ���λ*/
		pre->next = curNext;
	}
	/*�������������ͷ���*/
	return newHead->next;
}

/*������ʡ��*/
