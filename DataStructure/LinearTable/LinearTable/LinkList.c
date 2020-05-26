#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*存储空间初始分配量*/



typedef int Status; /*Status是函数的类型，其值是函数结果状态代码，如OK等*/
typedef int ElemType; /*ElemType类型根据实际情况而定，这里假设为int*/


/*线性表的单链表存储结构*/
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList; /*定义LinkList*/

/*打印字符*/
Status Linkvisit(ElemType c)
{
	printf("%d", c);
	return OK;
}

/* 初始化顺序线性表 */
Status LinkInitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /*产生头结点，并使L指向此头结点*/
	if (!(*L)) /*存储分配失败*/
	{
		return ERROR;
	}
	(*L)->next = NULL; /*指针域为空*/
	return OK;
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：若L为空表，则返回TRUE，否则返回FALSE*/
Status LinkListEmpty(LinkList L)
{
	if (L->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：返回L中数据元素个数*/
int LinkListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /*p指向第一个结点*/
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/
Status LinkGetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	p = L->next; /*让p指向链表L的第一个结点*/
	j = 1; /*j为计数器*/
	while (p && j < i) /*p不为空且计数器j还没有等于i时，循环继续*/
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR; /*第i个元素不存在*/
	}
	*e = p->data; /*取第i个元素的数据*/
	return OK;
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：返回L中第1个与e满足关系的数据元素的位序,若这样的数据元素不存在，则返回值为0*/
int LinkLocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next; /*让p指向链表L的第一个结点*/
	while (p)
	{
		i++;
		if (p->data == e) /*找到这样的数据元素*/
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}

/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status LinkListInsert(LinkList *L, int i, ElemType e)
{
	int j; /*j为计数器*/
	LinkList p, s; /*p为temp指针，s为待插入数据*/
	p = *L;
	j = 1;
	while (p && j < i) /*寻找第i个结点*/
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR; /*第i个元素不存在*/
	}
	s = (LinkList)malloc(sizeof(Node)); /*生成新结点(C标准函数)*/
	s->data = e;
	s->next = p->next; /*将p的后继结点赋值给s的后继*/
	p->next = s; /*将s赋值给p的后继*/
	return OK;
}

/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
Status LinkListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i) /*遍历寻找第i个元素*/
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
	{
		return ERROR; /*第i个元素不存在*/
	}
	q = p->next;
	p->next = q->next; /*将q的后继赋值给p的后继*/
	*e = q->data; /*将q结点中的数据给e*/
	free(q); /*让系统回收此结点，释放内存*/
	return OK;
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：依次对L的每个数据元素输出*/
Status LinkListTraverse(LinkList L)
{
	LinkList p = L->next; /*让p指向链表L的第一个结点*/
	while (p)
	{
		Linkvisit(p->data); /*打印当前指向的这个数据元素*/
		p = p->next; /*继续向下指向*/
	}
	printf("\n");
	return OK;
}

/*随机产生n个元素的值，建立带头结点的单链表线性表L（头插法）*/
void LinkCreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0)); /*初始化随机数种子*/
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL; /*先建立一个带头结点的单链表*/
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*生成新结点*/
		p->data = rand() % 100 + 1; /*随机生成100以内的数字*/
		p->next = (*L)->next;
		(*L)->next = p; /*插入到列表头*/
	}
}

/*随机产生n个元素的值，建立带头结点的单链表线性表L（尾插法）*/
void LinkCreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0)); /*初始化随机数种子*/
	*L = (LinkList)malloc(sizeof(Node)); /*为整个线性表*/
	r = *L; /*r为指向尾部的结点*/
	for (i = 0; i < n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*生成新节点*/
		p->data = rand() % 100 + 1; /*随机生成100以内的数字*/
		r->next = p; /*将尾部终端结点的指针指向新结点*/
		r = p; /*将当前的新结点定义为表尾终端结点*/
	}
	r->next = NULL; /*表示当前链表结束*/
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：将L重置为空表*/
Status LinkClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next; /*将第一个结点赋值给p*/
	while (p) /*没到表尾*/
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL; /*头结点指针域为空*/
	return OK;
}

/*线性表链式存储*/
int mainLinkList(void)
{
	LinkList L;
	ElemType e;
	Status i;
	int j, k;

	/*初始化单链表L*/
	i = LinkInitList(&L);
	printf("初始化L后：ListLength(L)=%d\n", LinkListLength(L));

	/*在单链表L表头插入元素*/
	for (j = 1; j <= 5; j++)
	{
		i = LinkListInsert(&L, 1, j);
	}
	printf("在L的表头依次插入1～5后：L.data=");
	LinkListTraverse(L);

	/*打印单链表L长度并判断是否为空*/
	printf("ListLength(L)=%d \n", LinkListLength(L));
	i = LinkListEmpty(L);
	printf("L是否空：i=%d(1：是 0：否)\n", i);

	/*清空单链表L打印长度并判断是否为空*/
	i = LinkClearList(&L);
	printf("清空L后：ListLength(L)=%d\n", LinkListLength(L));
	i = LinkListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	/*在单链表L表尾插入元素*/
	for (j = 1; j <= 10; j++)
	{
		LinkListInsert(&L, j, j);
	}
	printf("在L的表尾依次插入1～10后：L.data=");
	LinkListTraverse(L);

	/*打印单链表L的长度*/
	printf("ListLength(L)=%d \n", LinkListLength(L));

	/*在单链表表头插入一个元素*/
	LinkListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	LinkListTraverse(L);
	printf("ListLength(L)=%d \n", LinkListLength(L));

	/*获取单链表L指定位置的元素*/
	LinkGetElem(L, 5, &e);
	printf("第5个元素的值为：%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LinkLocateElem(L, j);
		if (k)
		{
			printf("第%d个元素的值为%d\n", k, j);
		}
		else
		{
			printf("没有值为%d的元素\n", j);
		}
	}

	/*删除单链表所有的元素*/
	k = LinkListLength(L); /*k为表长*/
	for (j = k + 1; j >= k; j--)
	{
		i = LinkListDelete(&L, j, &e); /*删除第j个数据*/
		if (i == ERROR)
		{
			printf("删除第%d个数据失败\n", j);
		}
		else
		{
			printf("删除第%d个的元素值为：%d\n", j, e);
		}
	}
	printf("依次输出L的元素：");
	LinkListTraverse(L);

	/*删除单链表L指定位置的元素*/
	j = 5;
	LinkListDelete(&L, j, &e); /*删除第5个元素*/
	printf("删除第%d个的元素值为：%d\n", j, e);
	printf("依次输出L的元素：");
	LinkListTraverse(L);

	/*清空表*/
	i = LinkClearList(&L);
	printf("清空L后：ListLength(L)=%d\n", LinkListLength(L));

	/*头插法整体创建L的元素*/
	LinkCreateListHead(&L, 20);
	printf("整体创建L的元素(头插法)：");
	LinkListTraverse(L);

	/*清空表*/
	i = LinkClearList(&L);
	printf("清空L后：ListLength(L)=%d\n", LinkListLength(L));

	/*尾插法整体创建L的元素*/
	LinkCreateListTail(&L, 20);
	printf("整体创建L的元素(尾插法)：");
	LinkListTraverse(L);

	getchar();

}