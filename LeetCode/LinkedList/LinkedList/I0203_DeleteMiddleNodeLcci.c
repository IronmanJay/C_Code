#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
	/*����ǰ��ɾ���ڵ��ֵ��Ϊ��һ���ڵ��ֵ*/
	node->val = node->next->val;
	/*����ǰ��ɾ���ڵ����һ��ָ��ָ��Ϊ��һ������һ�����ܽ�����Լ�����˱��ˣ�����������һ���ģ�ȥ�ؼ���*/
	node->next = node->next->next;
}

/*������ʡ��*/
