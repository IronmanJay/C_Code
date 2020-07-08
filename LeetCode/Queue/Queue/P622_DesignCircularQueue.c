#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*ѭ�����нṹ��*/
typedef struct
{
	int *data; /*����ģ�����*/
	int front; /*ͷָ��*/
	int rear; /*βָ��*/
	int len; /*���鳤��*/
}MyCircularQueue;

/*��ʼ������*/
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	queue->data = (int *)malloc((k + 1) * sizeof(int));
	queue->front = 0;
	queue->rear = 0;
	queue->len = k + 1; /*����+1����ΪҪԤ��һ��Ԫ��λ��*/
	return queue;
}

/*�ж϶����Ƿ��*/
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->rear == obj->front;
}

/*�ж϶����Ƿ���*/
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->rear + 1) % obj->len == obj->front;
}

/*����в���Ԫ��*/
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->data[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->len; /*ȡģ����ת��һȦ��������˶������һ������ô��һ���͵��˶���ͷ*/
	return true;
}

/*��������ͷԪ��*/
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->front = (obj->front + 1) % obj->len; /*ȡģ����ת��һȦ��������˶������һ������ô��һ���͵��˶���ͷ*/
	return true;
}

/*�õ�����ͷԪ��*/
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->front + obj->len) % obj->len]; /*��Ϊͷָ��ָ�ľ����ģ�����ֱ�ӷ��أ������漰��תȦ������*/
}

/*�õ�����βԪ��*/
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->rear - 1 + obj->len) % obj->len]; /*��Ϊβָ�����һ��+1�ˣ����Զ�βԪ��Ҫ-1�������漰��תȦ������*/
}

/*�ͷ�Ԫ��*/
void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->data); /*ע������Ҫ���ͷŶ������飬���ͷ��������У�������������Խ�����*/
	free(obj);
}

/*������ʡ��*/
