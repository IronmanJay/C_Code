#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*����ջ�Ľṹ��*/
typedef struct
{
	int stackIn_count;
	int stackOut_count;
	int *stackIn;
	int *stackOut;
} CQueue;

/*��������ջ*/
CQueue* cQueueCreate()
{
	CQueue *obj = (CQueue *)malloc(sizeof(CQueue));
	obj->stackIn_count = 0;
	obj->stackOut_count = 0;
	obj->stackIn = (int *)malloc(sizeof(int) * 10000);
	obj->stackOut = (int *)malloc(sizeof(int) * 10000);
	return obj;
}

/*��stackIn��β���������*/
void cQueueAppendTail(CQueue* obj, int value)
{
	obj->stackIn[obj->stackIn_count++] = value;
}

/*��stackOut��ͷ������Ԫ��*/
int cQueueDeleteHead(CQueue* obj)
{
	if (obj->stackOut_count == 0)
	{
		if (obj->stackIn_count == 0)
		{
			return -1;
		}
		while (obj->stackIn_count != 0)
		{
			obj->stackOut[obj->stackOut_count++] = obj->stackIn[--obj->stackIn_count];
		}
	}
	return obj->stackOut[--obj->stackOut_count];
}

/*�ͷſռ�*/
void cQueueFree(CQueue* obj)
{
	free(obj->stackIn);
	free(obj->stackOut);
	free(obj);
}

/*������ʡ��*/
