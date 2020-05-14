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
typedef int SElemType; /*SElemType���͸���ʵ������������������Ϊint*/

/*��ջ����ռ�ṹ*/
typedef struct
{
	SElemType data[MAXSIZE];
	int top1; /*ջ1ջ��ָ��*/
	int top2; /*ջ2ջ��ָ��*/
}SqDoubleStack;

/*��ӡ����Ԫ��*/
Status DoubleStackvisit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

/*����һ����ջS*/
Status DoubleStackInitStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

/*��S��Ϊ��ջ*/
Status DoubleStackClearStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

/*��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE*/
Status DoubleStackEmpty(SqDoubleStack S)
{
	if (S.top1 == -1 && S.top2 == MAXSIZE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*����S��Ԫ�ظ�������ջ�ĳ���*/
Status DoubleStackLength(SqDoubleStack S)
{
	return (S.top1 + 1) + (MAXSIZE - S.top2);
}

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status DoubleStackPush(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2) /*ջ������������push��Ԫ����*/
	{
		return ERROR;
	}
	if (stackNumber == 1) /*ջ1��Ԫ�ؽ�ջ*/
	{
		S->data[++S->top1] = e; /*����ջ1����top1+1�������Ԫ�ظ�ֵ*/
	}
	else if (stackNumber == 2) /*ջ2��Ԫ�ؽ�ջ*/
	{
		S->data[--S->top2] = e; /*����ջ2����top2-1�������Ԫ�ظ�ֵ*/
	}
	return OK;
}

/*��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status DoubleStackPop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1) /*˵��ջ1�Ѿ��ǿ�ջ�����*/
		{
			return ERROR;
		}
		*e = S->data[S->top1--]; /*��ջ1��ջ��Ԫ�س�ջ*/
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE) /*˵��ջ2�Ѿ��ǿ�ջ�����*/
		{
			return ERROR;
		}
		*e = S->data[S->top2++]; /*��ջ2��ջ��Ԫ�س�ջ*/
	}
	return OK;
}

/*����ջ*/
Status DoubleStackTraverse(SqDoubleStack S)
{
	int i;
	i = 0;
	while (i <= S.top1)
	{
		DoubleStackvisit(S.data[i++]);
	}
	i = S.top2;
	while (i < MAXSIZE)
	{
		DoubleStackvisit(S.data[i++]);
	}
	printf("\n");
	return OK;
}

int mainDoubleStack(void)
{
	/*��ʼ������*/
	int j;
	SqDoubleStack s;
	int e;

	/*��ʼ��ջ������Ԫ��*/
	if (DoubleStackInitStack(&s) == OK)
	{
		for (j = 1; j <= 5; j++)
		{
			DoubleStackPush(&s, j, 1);
		}
		for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
		{
			DoubleStackPush(&s, j, 2);
		}
	}

	/*��ӡջ*/
	printf("ջ��Ԫ������Ϊ��");
	DoubleStackTraverse(s);

	/*��ӡջ�ĳ���*/
	printf("��ǰջ��Ԫ���У�%d \n", DoubleStackLength(s));

	/*����ջ��Ԫ��*/
	DoubleStackPop(&s, &e, 2);
	printf("������ջ��Ԫ�� e=%d\n", e);

	/*�ж�ջ�Ƿ�Ϊ��*/
	printf("ջ�շ�%d(1:�� 0:��)\n", DoubleStackEmpty(s));

	/*��ջ1�м���Ԫ��*/
	for (j = 6; j <= MAXSIZE; j++)
	{
		DoubleStackPush(&s, j, 1);
	}

	/*��ӡջ*/
	printf("ջ��Ԫ������Ϊ��");
	DoubleStackTraverse(s);

	/*��ջ1�м���Ԫ�أ����ж�ջ�Ƿ�Ϊ��*/
	printf("ջ�շ�%d(1:�� 0:��)\n", DoubleStackPush(&s, 100, 1));

	/*���ջ���ж�ջ�Ƿ�Ϊ��*/
	DoubleStackClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", DoubleStackEmpty(s));

	getchar();

}