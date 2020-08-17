#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*����ջ�Ĵ�С*/
#define MAXSIZE 100

/*����ջ*/
struct Stack
{
	int data[MAXSIZE];
	int top;
};

typedef struct Stack MyStack;

/*���ж���Ϊ˫ջ*/
typedef struct
{
	MyStack stackMain; /*��ջ*/
	MyStack stackHelp; /*����ջ*/
} MyQueue;

/*��ʼ������ջ*/
MyQueue* myQueueCreate()
{
	MyQueue* Queue = (MyQueue*)malloc(sizeof(MyQueue));
	Queue->stackMain.top = -1;
	Queue->stackHelp.top = -1;
	return Queue;
}

/*�򡰶��С��м���Ԫ��*/
void myQueuePush(MyQueue* obj, int x)
{
	if (obj->stackMain.top < MAXSIZE)
	{
		obj->stackMain.data[++(obj->stackMain.top)] = x;
	}
}

/*���������ס�Ԫ��*/
int myQueuePop(MyQueue* obj)
{
	/*
		�������ջΪ�գ��ͽ���ջ��Ԫ��pop������ջ����ô����ջ���ڵĽṹ�ͺͶ���һ����
		�������ջ��Ϊ�գ�˵���Ѿ�����ջ��Ԫ�ط��븨��ջ�ˣ���ô����ջ���ڵĽṹ�ͺͶ���һ����
		�����������������ջ�Ľṹ���Ͷ���һ���������Ե�������ջջ�׵�Ԫ�أ�����൱�ڡ����ס�Ԫ��
	*/
	if (obj->stackHelp.top == -1)
	{
		while (obj->stackMain.top != -1)
		{
			obj->stackHelp.data[++(obj->stackHelp.top)] = obj->stackMain.data[(obj->stackMain.top)--];
		}
	}
	/*�����peek��ͬ���ǣ�popҪɾ��������Ԫ�أ�����ջ��ָ��--*/
	return obj->stackHelp.data[(obj->stackHelp.top)--];
}

/*�鿴�����ס�Ԫ��*/
int myQueuePeek(MyQueue* obj)
{
	/*
		�������ջΪ�գ��ͽ���ջ��Ԫ��pop������ջ����ô����ջ���ڵĽṹ�ͺͶ���һ����
		�������ջ��Ϊ�գ�˵���Ѿ�����ջ��Ԫ�ط��븨��ջ�ˣ���ô����ջ���ڵĽṹ�ͺͶ���һ����
		�����������������ջ�Ľṹ���Ͷ���һ����������ȡ������ջջ�׵�Ԫ�أ�����൱�ڡ����ס�Ԫ��
	*/
	if (obj->stackHelp.top == -1)
	{
		while (obj->stackMain.top != -1)
		{
			obj->stackHelp.data[++(obj->stackHelp.top)] = obj->stackMain.data[(obj->stackMain.top)--];
		}
	}
	/*�����pop��ͬ���ǣ�peek��ɾ��������Ԫ�أ�����ջ��ָ�벻��*/
	return obj->stackHelp.data[(obj->stackHelp.top)];
}

/*�жϡ����С��Ƿ�Ϊ��*/
bool myQueueEmpty(MyQueue* obj)
{
	/*ֻ�е���ջ�͸���ջ��Ϊ�յ�ʱ�򣬲�˵�������С��Ѿ����ˣ�һ��Ԫ�ض�û����*/
	return obj->stackMain.top == -1 && obj->stackHelp.top == -1;
}

/*�ͷſռ�*/
void myQueueFree(MyQueue* obj)
{
	free(obj);
}

/*������ʡ��*/
