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
	/*因为有序，把有结点剩余的全部返回，这是递归结束条件*/
	if (l1 == NULL || l2 == NULL)
	{
		return l1 == NULL ? l2 : l1;
	}
	/*开始递归，谁小谁做头结点，第一次if判断的时候进入哪个哪个就是最终返回的头结点*/
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

/*主函数省略*/
