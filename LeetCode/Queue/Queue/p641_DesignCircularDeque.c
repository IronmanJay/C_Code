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
}MyCircularDeque;

/*��ʼ������*/
MyCircularDeque* myCircularDequeCreate(int k)
{
	MyCircularDeque* queue = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
	queue->len = k + 1; /*����+1����ΪҪԤ��һ��Ԫ��λ��*/
	queue->data = (int *)malloc(queue->len * sizeof(int));
	queue->front = 0;
	queue->rear = 0;
	return queue;
}

/*�ж�˫�˶����Ƿ�Ϊ��*/
bool myCircularDequeIsEmpty(MyCircularDeque* obj)
{
	return obj->rear == obj->front;
}

/*�ж�˫�˶����Ƿ���*/
bool myCircularDequeIsFull(MyCircularDeque* obj)
{
	return (obj->rear + 1) % obj->len == obj->front;
}

/*�����ͷ����Ԫ��*/
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value)
{
	if (myCircularDequeIsFull(obj))
	{
		return false;
	}
	obj->front = (obj->front - 1 + obj->len) % obj->len;
	obj->data[obj->front] = value;
	return true;
}

/*�����β����Ԫ��*/
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value)
{
	if (myCircularDequeIsFull(obj))
	{
		return false;
	}
	obj->data[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->len;
	return true;
}

/*ɾ������ͷԪ��*/
bool myCircularDequeDeleteFront(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return false;
	}
	obj->front = (obj->front + 1) % obj->len;
	return true;
}

/*ɾ������βԪ��*/
bool myCircularDequeDeleteLast(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return false;
	}
	obj->rear = (obj->rear - 1 + obj->len) % obj->len;
	return true;
}

/*���ض���ͷԪ��*/
int myCircularDequeGetFront(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->front + obj->len) % obj->len];
}

/*���ض���βԪ��*/
int myCircularDequeGetRear(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->rear - 1 + obj->len) % obj->len];
}

/*�ͷ�Ԫ��*/
void myCircularDequeFree(MyCircularDeque* obj)
{
	free(obj->data);
	free(obj);
}

/*������ʡ��*/
