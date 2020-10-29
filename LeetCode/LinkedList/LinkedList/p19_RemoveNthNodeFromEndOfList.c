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
	/*头节点前的节点*/
	struct ListNode* newHead = NULL;
	newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newHead->next = head;
	/*快指针，赋值为头节点，保证一直和慢指针相差n个节点*/
	struct ListNode* fast = head;
	/*慢指针，赋值为头节点前的节点，目的是当快指针指向尾节点之后的位置时，慢指针指向待删除节点的前一个节点*/
	struct ListNode* slow = newHead;
	/*找到快指针和慢指针相差n个节点的位置*/
	for (int i = 0; i < n; i++)
	{
		fast = fast->next;
	}
	/*当快指针指向尾节点之后的位置时，慢指针指向待删除节点的前一个节点*/
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	/*此时慢指针指向了待删除结点的前一个节点吗，那么删除待删除节点*/
	slow->next = slow->next->next;
	/*返回结果*/
	return newHead->next;
}

/*主函数省略*/
