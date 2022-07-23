/*王道2023考研计算机数据结构复习指导40页中二、综合应用题之03题*/

/*去除警告*/
#define _CRT_SECURE_NO_WARNINGS

/*引入头文件*/
#include<stdio.h>
#include<stdlib.h>

/*声明定义结点结构体，其中包括数据和指向下一个结点的指针*/
typedef struct LNode
{
	int data;
	struct LNode* next;/*这里就是指向下一个结点的指针，*表示这是一个指针，next是这个指针的名字，struct表示这个指针指向的内容是个结构体*/
}Node,*Link;/*这里需要说明Node为结构体的名字，也就是typedef给结构体struct LNode定义了一个别名，这个别名叫Node，而*Link表示一个结构体指针，声明变量的时候要使用malloc开辟内存空间或者指向某一个已经声明的结构体；还有一个区别在于带*定义结构体指针的时候，取内部数据元素的时候要用->，而不带*的知识一个普通的结构体变量，取元素的时候要用.*/

/*使用单链表的头插法，将link1逆置为新链表link2*/
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

/*打印单链表*/
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

/*主函数*/
int main()
{
	Link link1 = (Link)malloc(sizeof(Node));
	link1->next = NULL;
	Link link2 = (Link)malloc(sizeof(Node));
	link2->next = NULL;
	Node* p = link1;
	int len;
	printf("请输入单链表的长度：");
	scanf("%d", &len);/*输入单链表长度*/
	printf("请输入单链表的元素：");
	for (int i = 0; i < len; i++)/*扫描数据建立单链表*/
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
	printf("初始单链表为：");
	PrintLink_ReversePrint(link1);
	printf("\n");
	printf("逆置后的单链表为：");
	PrintLink_ReversePrint(link2);
	printf("\n");
	/*暂停程序*/
	system("pause");
	/*函数结束*/
	return 0;
}