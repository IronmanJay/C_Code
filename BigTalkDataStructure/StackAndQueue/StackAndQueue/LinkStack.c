#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20  /*�洢�ռ��ʼ������*/

typedef int Status;
typedef int SElemType; /*SElemType���͸���ʵ������������������Ϊint*/

/*��ջ�ṹ*/
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

/*��ӡ����Ԫ��*/
Status LinkStackvisit(SElemType c)
{
	printf("%d", c);
	return OK;
}

/*����һ����ջS*/
Status LinkStackInitStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
	{
		return ERROR;
	}
	S->top = NULL;
	S->count = 0;
	return OK;
}

/*��S��Ϊ��ջ*/
Status LinkStackClearStack(LinkStack *S)
{
	LinkStackPtr p, q;
	p = S->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK;
}

/*��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE*/
Status LinkStackEmpty(LinkStack S)
{
	if (S.count == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*����S��Ԫ�ظ�������ջ�ĳ���*/
int LinkStackLength(LinkStack S)
{
	return S.count;
}

/*��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR*/
Status LinkStackGetTop(LinkStack S, SElemType *e)
{
	if (S.top == NULL)
	{
		return ERROR;
	}
	else
	{
		*e = S.top->data;
	}
	return OK;
}

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status LinkStackPush(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;	/*�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/
	S->top = s;         /*���µĽ��s��ֵ��ջ��ָ��*/
	S->count++;
	return OK;
}

/*��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR*/
Status LinkStackPop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
	{
		return ERROR;
	}
	*e = S->top->data;
	p = S->top;					/*��ջ����㸳ֵ��p*/
	S->top = S->top->next;		/*ʹ��ջ��ָ������һλ��ָ���һ���*/
	free(p);                    /*�ͷŽ��p*/
	S->count--;
	return OK;
}

/*����ջ*/
Status LinkStackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p = S.top;
	while (p)
	{
		LinkStackvisit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

/*��ջ*/
int mainLinkStack(void)
{
	/*��ʼ������*/
	int j;
	LinkStack s;
	int e;

	/*��ʼ����ջ��������Ԫ��*/
	if (LinkStackInitStack(&s) == OK)
	{
		for (j = 1; j <= 10; j++)
		{
			LinkStackPush(&s, j);
		}
	}

	/*��ӡ��ջԪ��*/
	printf("ջ��Ԫ������Ϊ��");
	LinkStackTraverse(s);

	/*����Ԫ��*/
	LinkStackPop(&s, &e);
	printf("������ջ��Ԫ�� e=%d\n", e);

	/*�ж��Ƿ�Ϊ��*/
	printf("ջ�շ�%d(1:�� 0:��)\n", LinkStackEmpty(s));

	/*�õ�ջ��Ԫ�أ�����ӡ����*/
	LinkStackGetTop(s, &e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, LinkStackLength(s));

	/*���ջ�����ж�ջ�Ƿ�Ϊ��*/
	LinkStackClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", LinkStackEmpty(s));

	getchar();

}