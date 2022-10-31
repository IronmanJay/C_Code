#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int data[1000];
	int top;
} MyQueue;

MyQueue* myQueueCreate()
{
	MyQueue* stack = (MyQueue*)malloc(sizeof(MyQueue));
	stack->top = -1;
	return stack;
}

void myQueuePush(MyQueue* obj, int x)
{
	if (obj->top == -1)
	{
		obj->data[++obj->top] = x;
		return;
	}
	MyQueue* temp = myQueueCreate();
	while (obj->top >= 0)
	{
		temp->data[++temp->top] = obj->data[obj->top--];
	}
	obj->data[++obj->top] = x;
	while (temp->top >= 0)
	{
		obj->data[++obj->top] = temp->data[temp->top--];
	}
}

bool myQueueEmpty(MyQueue* obj)
{
	return obj->top == -1;
}

int myQueuePop(MyQueue* obj)
{
	if (!myQueueEmpty(obj))
	{
		return obj->data[obj->top--];
	}
	return NULL;
}

int myQueuePeek(MyQueue* obj)
{
	if (!myQueueEmpty(obj))
	{
		int res = 0;
		res = obj->data[obj->top];
		return res;
	}
	return NULL;
}

void myQueueFree(MyQueue* obj)
{
	if (obj)
	{
		free(obj);
	}
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/