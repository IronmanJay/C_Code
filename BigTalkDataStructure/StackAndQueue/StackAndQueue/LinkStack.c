#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20  /*存储空间初始分配量*/

typedef int Status;
typedef int SElemType; /*SElemType类型根据实际情况而定，这里假设为int*/

/*链栈结构*/
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

/*打印数据元素*/
Status LinkStackvisit(SElemType c)
{
	printf("%d", c);
	return OK;
}

/*构造一个空栈S*/
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

/*把S置为空栈*/
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

/*若栈S为空栈，则返回TRUE，否则返回FALSE*/
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

/*返回S的元素个数，即栈的长度*/
int LinkStackLength(LinkStack S)
{
	return S.count;
}

/*若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR*/
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

/*插入元素e为新的栈顶元素*/
Status LinkStackPush(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;	/*把当前的栈顶元素赋值给新结点的直接后继*/
	S->top = s;         /*将新的结点s赋值给栈顶指针*/
	S->count++;
	return OK;
}

/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR*/
Status LinkStackPop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
	{
		return ERROR;
	}
	*e = S->top->data;
	p = S->top;					/*将栈顶结点赋值给p*/
	S->top = S->top->next;		/*使得栈顶指针下移一位，指向后一结点*/
	free(p);                    /*释放结点p*/
	S->count--;
	return OK;
}

/*遍历栈*/
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

/*链栈*/
int mainLinkStack(void)
{
	/*初始化参数*/
	int j;
	LinkStack s;
	int e;

	/*初始化链栈，并加入元素*/
	if (LinkStackInitStack(&s) == OK)
	{
		for (j = 1; j <= 10; j++)
		{
			LinkStackPush(&s, j);
		}
	}

	/*打印链栈元素*/
	printf("栈中元素依次为：");
	LinkStackTraverse(s);

	/*弹出元素*/
	LinkStackPop(&s, &e);
	printf("弹出的栈顶元素 e=%d\n", e);

	/*判断是否为空*/
	printf("栈空否：%d(1:空 0:否)\n", LinkStackEmpty(s));

	/*得到栈顶元素，并打印长度*/
	LinkStackGetTop(s, &e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, LinkStackLength(s));

	/*清空栈，并判断栈是否为空*/
	LinkStackClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", LinkStackEmpty(s));

	getchar();

}