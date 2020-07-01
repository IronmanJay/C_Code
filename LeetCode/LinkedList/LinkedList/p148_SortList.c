#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*链表结构*/
struct ListNode
{
	int val;
	struct ListNode *next;
};

/*交换值*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*进行一次切分*/
struct ListNode* partition(struct ListNode* head, struct ListNode* end)
{
	if (head == end || head->next == end)
	{
		return head;
	}
	int key = head->val; /*取第一个为基准值*/
	/*两个指针，p1和p2之间的都是大于基准值的，p1之前的都是小于基准值的*/
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

/*快速排序*/
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

/*主函数省略*/
