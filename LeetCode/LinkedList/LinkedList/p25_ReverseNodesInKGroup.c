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
	/*����ָ��ͷ����ָ��*/
	struct ListNode newHead = { 0 };
	newHead.next = head;
	/*����ǰ����㣬������ǳ�ջʱ�ѽ������ָ��*/
	struct ListNode* pre = NULL;
	pre = &newHead;
	/*����ջ�ĺ���ȳ�����ʵ�ַ�ת*/
	struct ListNode** stack = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
	memset(stack, 0, sizeof(struct ListNode *) * k);
	/*��ʼѭ������*/
	while (true)
	{
		/*���ڼ���ʣ�µ�Ԫ���Ƿ���*/
		int count = 0;
		/*��ʱ��㣬�����ҵ�K��Ԫ�أ��ҵ�֮��Ϊ��K��Ԫ�ص���һ����㣬ע��Ҫ��head��ʼ������head�������£�����ͻ�һֱ��ͷ����������֮���head�������ڵ�temp�����Եڶ��α���ʱtemp�ͻ���ϴε�λ�ü���*/
		struct ListNode* temp = head;
		while (temp != NULL && count < k)
		{
			/*�ѷ���λ�õĽ�����ջ*/
			stack[count] = temp;
			temp = temp->next;
			count++;
		}
		/*���ʣ�µĽ�㲻���ˣ���ôֱ�ӽ���������preָ��head��Ŀ��������ʣ�µĽ��*/
		if (count != k)
		{
			pre->next = head;
			break;
		}
		/*��ջ�����ε���Ԫ�أ����²��룬pre���ǲ����ָ��*/
		while (count > 0)
		{
			pre->next = stack[count - 1];
			pre = pre->next;
			count--;
		}
		/*��һ���ַ�ת��Ϻ󣬽���ת֮���������temp���ӣ�Ҳ���Ǻͻ�û�з�ת��������кϲ��������head����Ҫ��ÿ�ζ�Ҫ���µ�temp��λ�ã����Ҳ����ƶ���ֻ����������ƶ�һ�Σ���������ÿ����������Kʱtemp����ʼλ�ã�Ҳ�ǲ���������Kʱ���Ӻ��������ָ��*/
		pre->next = temp;
		head = temp;
	}
	/*���ؽ��*/
	return newHead.next;
}

/*������ʡ��*/
