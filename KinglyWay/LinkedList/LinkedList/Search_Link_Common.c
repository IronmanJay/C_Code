/*王道2023考研计算机数据结构复习指导40页中二、综合应用题之08题*/

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

/*求单链表的长度*/
int Length(Link link)
{
	int len = 0;
	Node* p = link->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

/*本函数的功能为找到两个带头结点的单链表的第一个公共结点*/
Link Search_Link_Common(Link L1, Link L2)
{
	int len1 = Length(L1);/*求两个单链表的长度*/
	int len2 = Length(L2);
	int dist;/*保存两个单链表长度的差值*/
	Link shortLink, longLink;/*分别指向表长较长和较短的单链表*/
	if (len1 > len2)/*两表比较长度*/
	{
		shortLink = L2->next;
		longLink = L1->next;
		dist = len1 - len2;
	}
	else
	{
		shortLink = L1->next;
		longLink = L2->next;
		dist = len2 - len1;
	}
	while (dist--)/*注意：0为假，非0为真*/
	{
		longLink = longLink->next;/*表长的单链表与表短的单链表进行长度的同步*/
	}
	while (longLink != NULL)/*同步寻找公共结点，使用哪个指针都可以，因为已经同步了*/
	{
		if (shortLink == longLink)/*找到第一个公共结点*/
		{
			return longLink;
		}
		else/*继续同步寻找*/
		{
			longLink = longLink->next;
			shortLink = shortLink->next;
		}
	}
	/*如果找不到第一个公共结点，返回空值*/
	return NULL;
}

/*主函数*/
//int main()
//{
//	/*初始化第一个单链表*/
//	Link link1 = (Link)malloc(sizeof(Node));
//	link1->next = NULL;
//	Node* p1 = link1;
//	
//	int len1;
//	printf("请输入单链表L1的长度：");
//	scanf("%d", &len1);/*输入单链表长度*/
//	printf("请输入单链表L1的元素：");
//	for (int i = 0; i < len1; i++)/*扫描数据建立单链表*/
//	{
//		int x;
//		scanf("%d", &x);
//		Node* temp = (Node*)malloc(sizeof(Node));
//		temp->data = x;
//		temp->next = NULL;
//		p1->next = temp;
//		p1 = temp;
//	}
//	p1 = link1;/*随机设定某个结点为公共结点，准备让link2链接上*/
//	for (int i = 0; i < 3; i++)
//	{
//		p1 = p1->next;
//	}
//	/*初始化第二个单链表*/
//	Link link2 = (Link)malloc(sizeof(Node));
//	link2->next = NULL;
//	Node* p2 = link2;
//	int len2;
//	printf("请输入单链表L2的长度（只需要输入第一个公共结点前面的长度即可）：");
//	scanf("%d", &len2);/*输入单链表长度*/
//	printf("请输入单链表L2的元素（只需要输入第一个公共结点前面的元素即可）：");
//	for (int i = 0; i < len2; i++)
//	{
//		int x;
//		scanf("%d", &x);
//		Node* temp = (Node*)malloc(sizeof(Node));
//		temp->data = x;
//		temp->next = NULL;
//		p2->next = temp;
//		p2 = temp;
//	}
//	p2->next = p1;/*链接公共结点*/
//	Link res = Search_Link_Common(link1, link2);
//	printf("第一个公共结点为：%d",res->data);
//	printf("\n");
//	/*暂停程序*/
//	system("pause");
//	/*函数结束*/
//	return 0;
//}