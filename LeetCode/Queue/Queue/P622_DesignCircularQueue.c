#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*循环队列结构体*/
typedef struct
{
	int *data; /*数组模拟队列*/
	int front; /*头指针*/
	int rear; /*尾指针*/
	int len; /*数组长度*/
}MyCircularQueue;

/*初始化队列*/
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	queue->data = (int *)malloc((k + 1) * sizeof(int));
	queue->front = 0;
	queue->rear = 0;
	queue->len = k + 1; /*这里+1是因为要预留一个元素位置*/
	return queue;
}

/*判断队列是否空*/
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->rear == obj->front;
}

/*判断队列是否满*/
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->rear + 1) % obj->len == obj->front;
}

/*向队列插入元素*/
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->data[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->len; /*取模就是转了一圈，如果到了队列最后一个，那么下一个就到了队列头*/
	return true;
}

/*弹出队列头元素*/
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->front = (obj->front + 1) % obj->len; /*取模就是转了一圈，如果到了队列最后一个，那么下一个就到了队列头*/
	return true;
}

/*得到队列头元素*/
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->front + obj->len) % obj->len]; /*因为头指针指哪就是哪，所以直接返回，但是涉及到转圈的问题*/
}

/*得到队列尾元素*/
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->rear - 1 + obj->len) % obj->len]; /*因为尾指针最后一次+1了，所以队尾元素要-1，但是涉及到转圈的问题*/
}

/*释放元素*/
void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->data); /*注意这里要先释放队列数组，再释放整个队列，否则会出现数组越界情况*/
	free(obj);
}

/*主函数省略*/
