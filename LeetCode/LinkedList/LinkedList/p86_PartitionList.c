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
	/*存储比x的值小的链表*/
	struct ListNode* newHead1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	/*存储比x的值小的链表的指针*/
	struct ListNode* curNode1 = newHead1;
	/*存储比x的值大或者相等的链表*/
	struct ListNode* newHead2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	/*存储比x的值大或者相等的链表的指针*/
	struct ListNode* curNode2 = newHead2;
	/*开始遍历*/
	while (head != NULL)
	{
		/*如果当前值比x的值小，使用newHead1存储这些比x的值小的节点*/
		if (head->val < x)
		{
			curNode1->next = head;
			curNode1 = curNode1->next;
		}
		/*如果当前值比x的值小，使用newHead2存储这些比x的值大或者相等的节点*/
		else
		{
			curNode2->next = head;
			curNode2 = curNode2->next;
		}
		head = head->next;
	}
	/*将存储比x的值大或者相等的链表的最后一个元素的下一个位置置为空*/
	curNode2->next = NULL;
	/*将存储比x的值小的链表连接到存储比x的值大或者相等的链表*/
	curNode1->next = newHead2->next;
	/*返回结果*/
	return newHead1->next;
}

/*主函数省略*/
