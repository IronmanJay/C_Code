#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head)
{
	/*���Ϊ��ֱ�ӷ���*/
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	/*���ȶ���ָ��ͷ����ָ��*/
	struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newHead->next = head;
	struct ListNode* cur = head->next;
	struct ListNode* pre = newHead->next;
	/*����ÿһ�����*/
	while (cur != NULL)
	{
		/*���������ֵС�ڻ�׼ֵ����ô������Ҳ���λ�ò������Ĵ���*/
		if (cur->val < pre->val)
		{
			/*���ȶ����µ�ͷ�ڵ㣬������Ǵ�ͳ���ʼ�Ľ�㣬���ǲ�����Ǹ�ͷ���*/
			struct ListNode* newIndex = newHead->next;
			/*�����µ�ǰ����㣬���newPre����Ǵ��������ǰ����ǰ�������������޸�*/
			struct ListNode* newPre = newHead;
			/*�ⲽ����Ҫ�����newIndex==pre��˵���ҵ��˴������㣬������Ҫ���²��Ҳ���λ�ã��������newIndex.val<cur.val��˵�������㲻�ܱ�����������룬��Ҫ���²����ҵ����Բ����λ��*/
			while (newIndex != pre && newIndex->val < cur->val)
			{
				newIndex = newIndex->next;
				newPre = newPre->next;
			}
			/*�Ѿ��ҵ�������λ�ã����Ƚ�preָ��cur����һ�����Ͽ�pre��cur������*/
			pre->next = cur->next;
			/*Ȼ��curָ�����λ�ã��½�����*/
			cur->next = newIndex;
			/*�޸�cur��ǰ������newPreָ��cur��Ҳ�����޸�֮ǰ�Ĵ��������ǰ����ǰ������ָ��pre������ָ��cur����Ϊcur��pre������λ��*/
			newPre->next = cur;
			/*��Ϊ����Ҫ������������cur�������£���ʱcurΪpre����һ����Ҳ����֮ǰcur����һ��*/
			cur = pre->next;
		}
		/*��������ָ��������±Ƚ�*/
		else
		{
			cur = cur->next;
			pre = pre->next;
		}
	}
	/*��󷵻�ͷ���*/
	return newHead->next;
}