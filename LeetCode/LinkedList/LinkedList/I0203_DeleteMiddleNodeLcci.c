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
	/*将当前待删除节点的值变为下一个节点的值*/
	node->val = node->next->val;
	/*将当前待删除节点的下一个指向指向为下一个的下一个，总结就是自己变成了别人，就有了两个一样的，去重即可*/
	node->next = node->next->next;
}

/*主函数省略*/
