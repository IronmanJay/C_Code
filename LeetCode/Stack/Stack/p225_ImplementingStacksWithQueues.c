#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 101

typedef struct queue
{
	int* data;
	int front;
	int rear;
}Queue;

typedef struct
{
	Queue *queue1;
	Queue *queue2;
} MyStack;

MyStack* myStackCreate()
{
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	obj->queue1 = (Queue*)malloc(sizeof(Queue));
	obj->queue2 = (Queue*)malloc(sizeof(Queue));
	obj->queue1->data = (int*)malloc(sizeof(int)*MAXSIZE);
	obj->queue2->data = (int*)malloc(sizeof(int)*MAXSIZE);
	obj->queue1->front = 0;
	obj->queue1->rear = 0;
	obj->queue2->front = 0;
	obj->queue2->rear = 0;
	return obj;
}

void myStackPush(MyStack* obj, int x)
{
	obj->queue1->data[obj->queue1->rear] = x;
	obj->queue1->rear = (obj->queue1->rear + 1) % MAXSIZE;
}

int myStackPop(MyStack* obj)
{
	while ((obj->queue1->front + 1) % MAXSIZE != (obj->queue1->rear) % MAXSIZE)
	{
		obj->queue2->data[obj->queue2->rear] = obj->queue1->data[obj->queue1->front];
		obj->queue2->rear = (obj->queue2->rear + 1) % MAXSIZE;
		obj->queue1->front = (obj->queue1->front + 1) % MAXSIZE;
	}
	Queue* temp = obj->queue1;
	obj->queue1 = obj->queue2;
	obj->queue2 = temp;
	int res = obj->queue2->data[obj->queue2->front];
	obj->queue2->front = (obj->queue2->front + 1) % MAXSIZE;
	return res;
}

int myStackTop(MyStack* obj)
{
	while ((obj->queue1->front + 1) % MAXSIZE != (obj->queue1->rear) % MAXSIZE)
	{
		obj->queue2->data[obj->queue2->rear] = obj->queue1->data[obj->queue1->front];
		obj->queue2->rear = (obj->queue2->rear + 1) % MAXSIZE;
		obj->queue1->front = (obj->queue1->front + 1) % MAXSIZE;
	}
	int res = obj->queue1->data[obj->queue1->front];
	obj->queue2->data[obj->queue2->rear] = obj->queue1->data[obj->queue1->front];
	obj->queue2->rear = (obj->queue2->rear + 1) % MAXSIZE;
	obj->queue1->front = (obj->queue1->front + 1) % MAXSIZE;
	Queue* temp = obj->queue1;
	obj->queue1 = obj->queue2;
	obj->queue2 = temp;
	return res;
}

bool myStackEmpty(MyStack* obj)
{
	return obj->queue1->front == obj->queue1->rear;
}

void myStackFree(MyStack* obj)
{
	free(obj->queue1->data);
	obj->queue1->data = NULL;
	free(obj->queue2->data);
	obj->queue2->data = NULL;
	free(obj->queue1);
	obj->queue1 = NULL;
	free(obj->queue2);
	obj->queue2 = NULL;
	free(obj);
	obj = NULL;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/