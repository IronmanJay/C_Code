#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	/*��Ϊ���򣬰��н��ʣ���ȫ�����أ����ǵݹ��������*/
	if (l1 == NULL || l2 == NULL)
	{
		return l1 == NULL ? l2 : l1;
	}
	/*��ʼ�ݹ飬˭С˭��ͷ��㣬��һ��if�жϵ�ʱ������ĸ��ĸ��������շ��ص�ͷ���*/
	if (l1->val <= l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

/*������ʡ��*/
