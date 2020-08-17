#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*定义栈的大小*/
#define MAXSIZE 100

/*创建栈*/
struct Stack
{
	int data[MAXSIZE];
	int top;
};

typedef struct Stack MyStack;

/*队列定义为双栈*/
typedef struct
{
	MyStack stackMain; /*主栈*/
	MyStack stackHelp; /*辅助栈*/
} MyQueue;

/*初始化两个栈*/
MyQueue* myQueueCreate()
{
	MyQueue* Queue = (MyQueue*)malloc(sizeof(MyQueue));
	Queue->stackMain.top = -1;
	Queue->stackHelp.top = -1;
	return Queue;
}

/*向“队列”中加入元素*/
void myQueuePush(MyQueue* obj, int x)
{
	if (obj->stackMain.top < MAXSIZE)
	{
		obj->stackMain.data[++(obj->stackMain.top)] = x;
	}
}

/*弹出“队首”元素*/
int myQueuePop(MyQueue* obj)
{
	/*
		如果辅助栈为空，就将主栈的元素pop进辅助栈，那么辅助栈现在的结构就和队列一样了
		如果辅助栈不为空，说明已经将主栈的元素放入辅助栈了，那么辅助栈现在的结构就和队列一样了
		不管那种情况，辅助栈的结构都和队列一样，都可以弹出辅助栈栈首的元素，这就相当于“队首”元素
	*/
	if (obj->stackHelp.top == -1)
	{
		while (obj->stackMain.top != -1)
		{
			obj->stackHelp.data[++(obj->stackHelp.top)] = obj->stackMain.data[(obj->stackMain.top)--];
		}
	}
	/*这里和peek不同的是，pop要删除弹出的元素，所以栈顶指针--*/
	return obj->stackHelp.data[(obj->stackHelp.top)--];
}

/*查看“队首”元素*/
int myQueuePeek(MyQueue* obj)
{
	/*
		如果辅助栈为空，就将主栈的元素pop进辅助栈，那么辅助栈现在的结构就和队列一样了
		如果辅助栈不为空，说明已经将主栈的元素放入辅助栈了，那么辅助栈现在的结构就和队列一样了
		不管那种情况，辅助栈的结构都和队列一样，都可以取出辅助栈栈首的元素，这就相当于“队首”元素
	*/
	if (obj->stackHelp.top == -1)
	{
		while (obj->stackMain.top != -1)
		{
			obj->stackHelp.data[++(obj->stackHelp.top)] = obj->stackMain.data[(obj->stackMain.top)--];
		}
	}
	/*这里和pop不同的是，peek不删除弹出的元素，所以栈顶指针不动*/
	return obj->stackHelp.data[(obj->stackHelp.top)];
}

/*判断“队列”是否为空*/
bool myQueueEmpty(MyQueue* obj)
{
	/*只有当主栈和辅助栈都为空的时候，才说明“队列”已经空了，一个元素都没有了*/
	return obj->stackMain.top == -1 && obj->stackHelp.top == -1;
}

/*释放空间*/
void myQueueFree(MyQueue* obj)
{
	free(obj);
}

/*主函数省略*/
