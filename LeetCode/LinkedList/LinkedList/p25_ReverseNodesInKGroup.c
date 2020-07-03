#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	/*定义指向头结点的指针*/
	struct ListNode newHead = { 0 };
	newHead.next = head;
	/*定义前驱结点，这个就是出栈时把结点插入的指针*/
	struct ListNode* pre = NULL;
	pre = &newHead;
	/*利用栈的后进先出特性实现反转*/
	struct ListNode** stack = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
	memset(stack, 0, sizeof(struct ListNode *) * k);
	/*开始循环遍历*/
	while (true)
	{
		/*用于计数剩下的元素是否够用*/
		int count = 0;
		/*临时结点，用于找到K个元素，找到之后为第K个元素的下一个结点，注意要从head开始，另外head后面会更新，否则就会一直从头遍历，更新之后的head就是现在的temp，所以第二次遍历时temp就会从上次的位置继续*/
		struct ListNode* temp = head;
		while (temp != NULL && count < k)
		{
			/*把符合位置的结点加入栈*/
			stack[count] = temp;
			temp = temp->next;
			count++;
		}
		/*如果剩下的结点不够了，那么直接结束，并且pre指向head，目的是链接剩下的结点*/
		if (count != k)
		{
			pre->next = head;
			break;
		}
		/*从栈中依次弹出元素，重新插入，pre就是插入的指针*/
		while (count > 0)
		{
			pre->next = stack[count - 1];
			pre = pre->next;
			count--;
		}
		/*当一部分反转完毕后，将反转之后的链表与temp链接，也就是和还没有反转的链表进行合并，这里的head很重要，每次都要更新到temp的位置，并且不会移动，只有在这里会移动一次，它不仅是每次满足条件K时temp的起始位置，也是不满足条件K时链接后面链表的指针*/
		pre->next = temp;
		head = temp;
	}
	/*返回结果*/
	return newHead.next;
}

/*主函数省略*/
