/*王道2023考研计算机数据结构复习指导40页中二、综合应用题之12题*/

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
}Node, *Link;/*这里需要说明Node为结构体的名字，也就是typedef给结构体struct LNode定义了一个别名，这个别名叫Node，而*Link表示一个结构体指针，声明变量的时候要使用malloc开辟内存空间或者指向某一个已经声明的结构体；还有一个区别在于带*定义结构体指针的时候，取内部数据元素的时候要用->，而不带*的知识一个普通的结构体变量，取元素的时候要用.*/

/*打印单链表*/
void PrintLink_Del_Same(Link link)
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

/*此函数的功能为删除有序的带头结点的单链表中的重复元素*/
void Del_Same(Link L)
{
	Link p = L->next;
	Node* temp = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		return;/*如果单链表为空，结束程序*/
	}
	while (p->next != NULL)
	{
		temp = p->next;/*temp指向p的后继结点*/
		if (p->data == temp->data)/*找到重复值的结点*/
		{
			p->next = temp->next;/*跳过重复值结点，重新链接单链表*/
			free(temp);/*释放值相同元素结点*/
		}
		else
		{
			p = p->next;/*不是重复值的结点继续向下寻找*/
		}
	}
}

/*主函数*/
//int main()
//{
//	Link link = (Link)malloc(sizeof(Node));
//	link->next = NULL;
//	Node* p = link;
//	int len;
//	printf("请输入单链表的长度：");
//	scanf("%d", &len);/*输入单链表长度*/
//	printf("请输入单链表的元素：");
//	for (int i = 0; i < len; i++)/*扫描数据建立单链表*/
//	{
//		int x;
//		scanf("%d", &x);
//		Node* temp = (Node*)malloc(sizeof(Node));
//		temp->data = x;
//		temp->next = NULL;
//		p->next = temp;
//		p = temp;
//	}
//	printf("初始单链表为：");
//	PrintLink_Del_Same(link);
//	printf("\n");
//	Del_Same(link);
//	printf("删除重复元素后的单链表为：");
//	PrintLink_Del_Same(link);
//	printf("\n");
//	/*暂停程序*/
//	system("pause");
//	/*函数结束*/
//	return 0;
//}