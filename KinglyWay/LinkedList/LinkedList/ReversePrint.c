/*����2023���м�������ݽṹ��ϰָ��40ҳ�ж����ۺ�Ӧ����֮03��*/

/*ȥ������*/
#define _CRT_SECURE_NO_WARNINGS

/*����ͷ�ļ�*/
#include<stdio.h>
#include<stdlib.h>

/*����������ṹ�壬���а������ݺ�ָ����һ������ָ��*/
typedef struct LNode
{
	int data;
	struct LNode* next;/*�������ָ����һ������ָ�룬*��ʾ����һ��ָ�룬next�����ָ������֣�struct��ʾ���ָ��ָ��������Ǹ��ṹ��*/
}Node,*Link;/*������Ҫ˵��NodeΪ�ṹ������֣�Ҳ����typedef���ṹ��struct LNode������һ�����������������Node����*Link��ʾһ���ṹ��ָ�룬����������ʱ��Ҫʹ��malloc�����ڴ�ռ����ָ��ĳһ���Ѿ������Ľṹ�壻����һ���������ڴ�*����ṹ��ָ���ʱ��ȡ�ڲ�����Ԫ�ص�ʱ��Ҫ��->��������*��֪ʶһ����ͨ�Ľṹ�������ȡԪ�ص�ʱ��Ҫ��.*/

/*ʹ�õ������ͷ�巨����link1����Ϊ������link2*/
void Reverse(Link link1, Link link2)
{
	Node* p = link1;
	while (p->next != NULL)
	{
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = p->next->data;
		temp->next = link2->next;
		link2->next = temp;
		p = p->next;
	}
}

/*��ӡ������*/
void PrintLink_ReversePrint(Link link)
{
	Node* p = link->next;
	while (p != NULL)
	{
		if (p->next != NULL)
		{
			printf("%d->", p->data);
		}
		else
		{
			printf("%d", p->data);
		}
		p = p->next;
	}
}

/*������*/
int main()
{
	Link link1 = (Link)malloc(sizeof(Node));
	link1->next = NULL;
	Link link2 = (Link)malloc(sizeof(Node));
	link2->next = NULL;
	Node* p = link1;
	int len;
	printf("�����뵥����ĳ��ȣ�");
	scanf("%d", &len);/*���뵥������*/
	printf("�����뵥�����Ԫ�أ�");
	for (int i = 0; i < len; i++)/*ɨ�����ݽ���������*/
	{
		int x;
		scanf("%d", &x);
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = x;
		temp->next = NULL;
		p->next = temp;
		p = temp;
	}
	Reverse(link1, link2);
	printf("��ʼ������Ϊ��");
	PrintLink_ReversePrint(link1);
	printf("\n");
	printf("���ú�ĵ�����Ϊ��");
	PrintLink_ReversePrint(link2);
	printf("\n");
	/*��ͣ����*/
	system("pause");
	/*��������*/
	return 0;
}