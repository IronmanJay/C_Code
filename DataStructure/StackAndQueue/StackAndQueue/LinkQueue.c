#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*存储空间初始分配量*/

typedef int Status;
typedef int QElemType; /*QElemType类型根据实际情况而定，这里假设为int*/

/*结点结构*/
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

/*队列的链表结构*/
typedef struct
{
	QueuePtr front, rear; /*队头，队尾指针*/
}LinkQueue;

/*打印数据元素*/
Status visitLinkQueue(QElemType c)
{
	printf("%d ", c);
	return OK;
}

/*构造一个空队列Q*/
Status InitLinkQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
	{
		exit(OVERFLOW);
	}
	Q->front->next = NULL;
	return OK;
}

/*销毁队列*/
Status DestroyLinkQueue(LinkQueue *Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

/*将Q清空为空队列*/
Status ClearLinkQueue(LinkQueue *Q)
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

/*若Q为空队列，则返回TRUE，否则返回FALSE*/
Status LinkQueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*返回队列的长度*/
int LinkQueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR*/
Status GetLinkQueueHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	p = Q.front->next;
	*e = p->data;
	return OK;
}

/*插入元素e为新的队尾元素*/
Status LinkEnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) /*存储分配失败*/
	{
		exit(OVERFLOW);
	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s; /*把拥有元素e的新结点s赋值给队尾结点的后继*/
	Q->rear = s; /*把当前的s设置为队尾结点，rear指向s*/
	return OK;
}

/*若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR*/
Status LinkDeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next; /*将欲删除的队头结点暂存给p*/
	*e = p->data; /*将欲删除的队头结点的值赋值给e*/
	Q->front->next = p->next; /*将原队头结点的后继p->next赋值给头结点后继*/
	if (Q->rear == p) /*若队头就是队尾，则删除后将rear指向头结点*/
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

/*从队头到队尾依次对队列Q中每个元素输出*/
Status LinkQueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		visitLinkQueue(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int mainLinkQueue(void)
{
	/*初始化参数*/
	int i;
	QElemType d;
	LinkQueue q;

	/*初始化LinkQueue*/
	i = InitLinkQueue(&q);
	if (i)
	{
		printf("成功地构造了一个空队列!\n");
	}

	/*判断队列是否为空，并打印队列的长度*/
	printf("是否空队列？%d(1:空 0:否)  \n", LinkQueueEmpty(q));
	printf("队列的长度为%d\n", LinkQueueLength(q));

	/*插入元素*/
	LinkEnQueue(&q, -5);
	LinkEnQueue(&q, 5);
	LinkEnQueue(&q, 10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", LinkQueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  \n", LinkQueueEmpty(q));

	/*打印队列元素*/
	printf("队列的元素依次为：");
	LinkQueueTraverse(q);

	/*得到队头元素*/
	i = GetLinkQueueHead(q, &d);
	if (i == OK)
	{
		printf("队头元素是：%d\n", d);
	}

	/*删除队头元素*/
	LinkDeQueue(&q, &d);
	printf("删除了队头元素%d\n", d);
	i = GetLinkQueueHead(q, &d);
	if (i == OK)
	{
		printf("新的队头元素是：%d\n", d);
	}

	/*清空队列*/
	ClearLinkQueue(&q);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);

	/*销毁队列*/
	DestroyLinkQueue(&q);
	printf("销毁队列后,q.front=%u q.rear=%u\n", q.front, q.rear);

	getchar();

}
