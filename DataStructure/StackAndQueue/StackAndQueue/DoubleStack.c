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
typedef int SElemType; /*SElemType类型根据实际情况而定，这里假设为int*/

/*两栈共享空间结构*/
typedef struct
{
	SElemType data[MAXSIZE];
	int top1; /*栈1栈顶指针*/
	int top2; /*栈2栈顶指针*/
}SqDoubleStack;

/*打印数据元素*/
Status DoubleStackvisit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

/*构造一个空栈S*/
Status DoubleStackInitStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

/*把S置为空栈*/
Status DoubleStackClearStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

/*若栈S为空栈，则返回TRUE，否则返回FALSE*/
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

/*返回S的元素个数，即栈的长度*/
Status DoubleStackLength(SqDoubleStack S)
{
	return (S.top1 + 1) + (MAXSIZE - S.top2);
}

/*插入元素e为新的栈顶元素*/
Status DoubleStackPush(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2) /*栈已满，不能再push新元素了*/
	{
		return ERROR;
	}
	if (stackNumber == 1) /*栈1有元素进栈*/
	{
		S->data[++S->top1] = e; /*若是栈1则先top1+1后给数据元素赋值*/
	}
	else if (stackNumber == 2) /*栈2有元素进栈*/
	{
		S->data[--S->top2] = e; /*若是栈2则先top2-1后给数组元素赋值*/
	}
	return OK;
}

/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR*/
Status DoubleStackPop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1) /*说明栈1已经是空栈，溢出*/
		{
			return ERROR;
		}
		*e = S->data[S->top1--]; /*将栈1的栈顶元素出栈*/
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE) /*说明栈2已经是空栈，溢出*/
		{
			return ERROR;
		}
		*e = S->data[S->top2++]; /*将栈2的栈顶元素出栈*/
	}
	return OK;
}

/*遍历栈*/
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
	/*初始化参数*/
	int j;
	SqDoubleStack s;
	int e;

	/*初始化栈并加入元素*/
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

	/*打印栈*/
	printf("栈中元素依次为：");
	DoubleStackTraverse(s);

	/*打印栈的长度*/
	printf("当前栈中元素有：%d \n", DoubleStackLength(s));

	/*弹出栈中元素*/
	DoubleStackPop(&s, &e, 2);
	printf("弹出的栈顶元素 e=%d\n", e);

	/*判断栈是否为空*/
	printf("栈空否：%d(1:空 0:否)\n", DoubleStackEmpty(s));

	/*向栈1中加入元素*/
	for (j = 6; j <= MAXSIZE; j++)
	{
		DoubleStackPush(&s, j, 1);
	}

	/*打印栈*/
	printf("栈中元素依次为：");
	DoubleStackTraverse(s);

	/*向栈1中加入元素，并判断栈是否为空*/
	printf("栈空否：%d(1:空 0:否)\n", DoubleStackPush(&s, 100, 1));

	/*清空栈并判断栈是否为空*/
	DoubleStackClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", DoubleStackEmpty(s));

	getchar();

}