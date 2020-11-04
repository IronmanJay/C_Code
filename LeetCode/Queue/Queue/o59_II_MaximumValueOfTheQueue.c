#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*自定义队列格式*/
typedef struct
{
	int* data;
	int front;
	int rear;
}Quque;

/*定义结果队列和辅助队列*/
typedef struct {
	Quque *resQueue;
	Quque *maxQueue;
} MaxQueue;

/*初始化结果队列和辅助队列*/
MaxQueue* maxQueueCreate()
{
	/*初始化存放结果队列和辅助队列的结构体*/
	MaxQueue* obj = (MaxQueue*)malloc(sizeof(MaxQueue));
	/*初始化结果队列*/
	obj->resQueue = (Quque*)malloc(sizeof(Quque));
	obj->resQueue->data = (int *)malloc(sizeof(int) * 20000);
	obj->resQueue->front = 0;
	obj->resQueue->rear = 0;
	/*初始化辅助队列*/
	obj->maxQueue = (Quque*)malloc(sizeof(Quque));
	obj->maxQueue->data = (int *)malloc(sizeof(int) * 20000);
	obj->maxQueue->front = 0;
	obj->maxQueue->rear = 0;
	/*返回存放结果队列和辅助队列的结构体*/
	return obj;
}

/*返回当前队列最大值*/
int maxQueueMax_value(MaxQueue* obj)
{
	/*判空返回1*/
	if (obj->resQueue->front == obj->resQueue->rear)
	{
		return -1;
	}
	/*辅助队列的头元素就是当前队列的最大值*/
	return obj->maxQueue->data[obj->maxQueue->front];
}

/*向队列添加元素*/
void maxQueuePush_back(MaxQueue* obj, int value)
{
	/*元素入结果队列*/
	obj->resQueue->data[obj->resQueue->rear++] = value;
	/*保证到当前队列位置的最大值*/
	while ((obj->maxQueue->front != obj->maxQueue->rear) && (obj->maxQueue->data[(obj->maxQueue->rear) - 1]) < value)
	{
		obj->maxQueue->rear--;
	}
	/*入辅助队列*/
	obj->maxQueue->data[obj->maxQueue->rear++] = value;
}

/*返回结果队列头元素*/
int maxQueuePop_front(MaxQueue* obj)
{
	/*判空返回-1*/
	if (obj->resQueue->front == obj->resQueue->rear)
	{
		return -1;
	}
	/*如果结果队列的头数字和辅助队列的头数字相等，都弹出*/
	int temp = obj->resQueue->data[obj->resQueue->front++];
	if (temp == obj->maxQueue->data[obj->maxQueue->front])
	{
		obj->maxQueue->front++;
	}
	/*返回当前队列头元素*/
	return temp;
}

/*释放空间*/
void maxQueueFree(MaxQueue* obj)
{
	free(obj->resQueue->data);
	free(obj->resQueue);
	free(obj->maxQueue->data);
	free(obj->maxQueue);
	free(obj);
}

/*主函数省略*/
