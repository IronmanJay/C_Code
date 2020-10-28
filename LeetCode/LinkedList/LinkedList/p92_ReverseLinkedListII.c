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
	/*指向头结点的节点*/
	struct ListNode* newHead = NULL;
	newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newHead->next = head;
	/*待反转部分首位的前驱节点，一直指向待反转的部分的首位*/
	struct ListNode* pre = newHead;
	/*找到待反转部分首位的前驱位置*/
	for (int i = 1; i < m; i++)
	{
		pre = pre->next;
	}
	/*待反转部分的起始节点，也是待反转部分的指针，一直向后移动*/
	struct ListNode* start = pre->next;
	/*遍历待反转部分*/
	for (int i = m; i < n; i++)
	{
		/*每次遍历都找到start的下一个节点，也就是要插入到前面（头部）的节点*/
		struct ListNode* curNext = start->next;
		/*重新指向start的下一个节点为要插入到前面（头部）的节点的下一个节点，此时要插入到前面（头部）的节点已经分离*/
		start->next = curNext->next;
		/*开始插入到前面（头部）*/
		curNext->next = pre->next;
		/*待反转部分首位的前驱节点一直指向待反转的部分的首位*/
		pre->next = curNext;
	}
	/*返回整个链表的头结点*/
	return newHead->next;
}

/*主函数省略*/
