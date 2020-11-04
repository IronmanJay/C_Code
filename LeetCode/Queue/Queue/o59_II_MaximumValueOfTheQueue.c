#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�Զ�����и�ʽ*/
typedef struct
{
	int* data;
	int front;
	int rear;
}Quque;

/*���������к͸�������*/
typedef struct {
	Quque *resQueue;
	Quque *maxQueue;
} MaxQueue;

/*��ʼ��������к͸�������*/
MaxQueue* maxQueueCreate()
{
	/*��ʼ����Ž�����к͸������еĽṹ��*/
	MaxQueue* obj = (MaxQueue*)malloc(sizeof(MaxQueue));
	/*��ʼ���������*/
	obj->resQueue = (Quque*)malloc(sizeof(Quque));
	obj->resQueue->data = (int *)malloc(sizeof(int) * 20000);
	obj->resQueue->front = 0;
	obj->resQueue->rear = 0;
	/*��ʼ����������*/
	obj->maxQueue = (Quque*)malloc(sizeof(Quque));
	obj->maxQueue->data = (int *)malloc(sizeof(int) * 20000);
	obj->maxQueue->front = 0;
	obj->maxQueue->rear = 0;
	/*���ش�Ž�����к͸������еĽṹ��*/
	return obj;
}

/*���ص�ǰ�������ֵ*/
int maxQueueMax_value(MaxQueue* obj)
{
	/*�пշ���1*/
	if (obj->resQueue->front == obj->resQueue->rear)
	{
		return -1;
	}
	/*�������е�ͷԪ�ؾ��ǵ�ǰ���е����ֵ*/
	return obj->maxQueue->data[obj->maxQueue->front];
}

/*��������Ԫ��*/
void maxQueuePush_back(MaxQueue* obj, int value)
{
	/*Ԫ����������*/
	obj->resQueue->data[obj->resQueue->rear++] = value;
	/*��֤����ǰ����λ�õ����ֵ*/
	while ((obj->maxQueue->front != obj->maxQueue->rear) && (obj->maxQueue->data[(obj->maxQueue->rear) - 1]) < value)
	{
		obj->maxQueue->rear--;
	}
	/*�븨������*/
	obj->maxQueue->data[obj->maxQueue->rear++] = value;
}

/*���ؽ������ͷԪ��*/
int maxQueuePop_front(MaxQueue* obj)
{
	/*�пշ���-1*/
	if (obj->resQueue->front == obj->resQueue->rear)
	{
		return -1;
	}
	/*���������е�ͷ���ֺ͸������е�ͷ������ȣ�������*/
	int temp = obj->resQueue->data[obj->resQueue->front++];
	if (temp == obj->maxQueue->data[obj->maxQueue->front])
	{
		obj->maxQueue->front++;
	}
	/*���ص�ǰ����ͷԪ��*/
	return temp;
}

/*�ͷſռ�*/
void maxQueueFree(MaxQueue* obj)
{
	free(obj->resQueue->data);
	free(obj->resQueue);
	free(obj->maxQueue->data);
	free(obj->maxQueue);
	free(obj);
}

/*������ʡ��*/
