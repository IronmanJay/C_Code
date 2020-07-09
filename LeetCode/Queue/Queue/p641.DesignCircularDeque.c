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
}MyCircularDeque;

/*初始化队列*/
MyCircularDeque* myCircularDequeCreate(int k)
{
	MyCircularDeque* queue = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
	queue->len = k + 1; /*这里+1是因为要预留一个元素位置*/
	queue->data = (int *)malloc(queue->len * sizeof(int));
	queue->front = 0;
	queue->rear = 0;
	return queue;
}

/*判断双端队列是否为空*/
bool myCircularDequeIsEmpty(MyCircularDeque* obj)
{
	return obj->rear == obj->front;
}

/*判断双端队列是否满*/
bool myCircularDequeIsFull(MyCircularDeque* obj)
{
	return (obj->rear + 1) % obj->len == obj->front;
}

/*向队列头插入元素*/
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

/*向队列尾插入元素*/
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

/*删除队列头元素*/
bool myCircularDequeDeleteFront(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return false;
	}
	obj->front = (obj->front + 1) % obj->len;
	return true;
}

/*删除队列尾元素*/
bool myCircularDequeDeleteLast(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return false;
	}
	obj->rear = (obj->rear - 1 + obj->len) % obj->len;
	return true;
}

/*返回队列头元素*/
int myCircularDequeGetFront(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->front + obj->len) % obj->len];
}

/*返回队列尾元素*/
int myCircularDequeGetRear(MyCircularDeque* obj)
{
	if (myCircularDequeIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[(obj->rear - 1 + obj->len) % obj->len];
}

/*释放元素*/
void myCircularDequeFree(MyCircularDeque* obj)
{
	free(obj->data);
	free(obj);
}

/*主函数省略*/
