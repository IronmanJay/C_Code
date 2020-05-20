#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*�洢�ռ��ʼ������*/

typedef int Status;
typedef int QElemType; /*QElemType���͸���ʵ������������������Ϊint*/

/*���ṹ*/
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

/*���е�����ṹ*/
typedef struct
{
	QueuePtr front, rear; /*��ͷ����βָ��*/
}LinkQueue;

/*��ӡ����Ԫ��*/
Status visitLinkQueue(QElemType c)
{
	printf("%d ", c);
	return OK;
}

/*����һ���ն���Q*/
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

/*���ٶ���*/
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

/*��Q���Ϊ�ն���*/
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

/*��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE*/
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

/*���ض��еĳ���*/
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

/*�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR*/
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

/*����Ԫ��eΪ�µĶ�βԪ��*/
Status LinkEnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) /*�洢����ʧ��*/
	{
		exit(OVERFLOW);
	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s; /*��ӵ��Ԫ��e���½��s��ֵ����β���ĺ��*/
	Q->rear = s; /*�ѵ�ǰ��s����Ϊ��β��㣬rearָ��s*/
	return OK;
}

/*�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status LinkDeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next; /*����ɾ���Ķ�ͷ����ݴ��p*/
	*e = p->data; /*����ɾ���Ķ�ͷ����ֵ��ֵ��e*/
	Q->front->next = p->next; /*��ԭ��ͷ���ĺ��p->next��ֵ��ͷ�����*/
	if (Q->rear == p) /*����ͷ���Ƕ�β����ɾ����rearָ��ͷ���*/
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

/*�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�����*/
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
	/*��ʼ������*/
	int i;
	QElemType d;
	LinkQueue q;

	/*��ʼ��LinkQueue*/
	i = InitLinkQueue(&q);
	if (i)
	{
		printf("�ɹ��ع�����һ���ն���!\n");
	}

	/*�ж϶����Ƿ�Ϊ�գ�����ӡ���еĳ���*/
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  \n", LinkQueueEmpty(q));
	printf("���еĳ���Ϊ%d\n", LinkQueueLength(q));

	/*����Ԫ��*/
	LinkEnQueue(&q, -5);
	LinkEnQueue(&q, 5);
	LinkEnQueue(&q, 10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", LinkQueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  \n", LinkQueueEmpty(q));

	/*��ӡ����Ԫ��*/
	printf("���е�Ԫ������Ϊ��");
	LinkQueueTraverse(q);

	/*�õ���ͷԪ��*/
	i = GetLinkQueueHead(q, &d);
	if (i == OK)
	{
		printf("��ͷԪ���ǣ�%d\n", d);
	}

	/*ɾ����ͷԪ��*/
	LinkDeQueue(&q, &d);
	printf("ɾ���˶�ͷԪ��%d\n", d);
	i = GetLinkQueueHead(q, &d);
	if (i == OK)
	{
		printf("�µĶ�ͷԪ���ǣ�%d\n", d);
	}

	/*��ն���*/
	ClearLinkQueue(&q);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);

	/*���ٶ���*/
	DestroyLinkQueue(&q);
	printf("���ٶ��к�,q.front=%u q.rear=%u\n", q.front, q.rear);

	getchar();

}
