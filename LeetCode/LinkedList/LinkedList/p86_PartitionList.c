#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* p86_PartitionList_partition(struct ListNode* head, int x)
{
	/*�洢��x��ֵС������*/
	struct ListNode* newHead1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	/*�洢��x��ֵС�������ָ��*/
	struct ListNode* curNode1 = newHead1;
	/*�洢��x��ֵ�������ȵ�����*/
	struct ListNode* newHead2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	/*�洢��x��ֵ�������ȵ������ָ��*/
	struct ListNode* curNode2 = newHead2;
	/*��ʼ����*/
	while (head != NULL)
	{
		/*�����ǰֵ��x��ֵС��ʹ��newHead1�洢��Щ��x��ֵС�Ľڵ�*/
		if (head->val < x)
		{
			curNode1->next = head;
			curNode1 = curNode1->next;
		}
		/*�����ǰֵ��x��ֵС��ʹ��newHead2�洢��Щ��x��ֵ�������ȵĽڵ�*/
		else
		{
			curNode2->next = head;
			curNode2 = curNode2->next;
		}
		head = head->next;
	}
	/*���洢��x��ֵ�������ȵ���������һ��Ԫ�ص���һ��λ����Ϊ��*/
	curNode2->next = NULL;
	/*���洢��x��ֵС���������ӵ��洢��x��ֵ�������ȵ�����*/
	curNode1->next = newHead2->next;
	/*���ؽ��*/
	return newHead1->next;
}

/*������ʡ��*/
