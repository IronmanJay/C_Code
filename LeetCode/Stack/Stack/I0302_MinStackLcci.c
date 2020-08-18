#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*����ջ���鳤��*/
#define MAXSIZE 10000

/*���ڱȽϵõ���Сֵ*/
int min;

/*�Ƚϵõ���Сֵ*/
int Min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

/*ջ�Ľṹ*/
typedef struct
{
	int data[MAXSIZE];
	int top;
} Stack;

typedef struct
{
	Stack stackMain; /*��ջ�����ڴ��ֵ*/
	Stack stackHelp; /*����ջ�����ڴ��ÿһ����ջ֮��ĵ�ǰջ��Сֵ*/
}MinStack;

/*��ʼ������ջ*/
MinStack* minStackCreate()
{
	min = 2147483647;
	MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
	stack->stackMain.top = -1;
	stack->stackHelp.top = -1;
	return stack;
}

/*������ջ*/
void minStackPush(MinStack* obj, int x)
{
	/*���Ȼ�ȡ��ǰԪ����ջ֮���ջ����Сֵ*/
	min = Min(min, x);
	/*��Ԫ������ջ*/
	obj->stackMain.data[++(obj->stackMain.top)] = x;
	/*����ǰջ����Сֵ�븨��ջ*/
	obj->stackHelp.data[++(obj->stackHelp.top)] = min;
}

/*����ջ��Ԫ��*/
void minStackPop(MinStack* obj)
{
	/*��ջ����ջ��Ԫ��*/
	obj->stackMain.top--;
	/*��Ϊ��ջ������һ��Ԫ�أ����Ը���ջ��Ӧ�ĵ�����ջ����СֵҲ�������ص���һ�������Сֵ��״̬*/
	obj->stackHelp.top--;
	/*�������ջ���ˣ�˵��û����Сֵ�ˣ����¸�ֵ�õ���Сֵ*/
	if (obj->stackHelp.top == -1)
	{
		min = 2147483647;
	}
	/*���û�գ���Ϊ����ջ��Ӧÿһ��ջ״̬����Сֵ�����Խ�min���¸�ֵΪ����ջ��Ԫ��֮��ǰջ��Ӧ����Сֵ��Ϊ��getMin()������׼��*/
	else
	{
		min = obj->stackHelp.data[obj->stackHelp.top];
	}
}

/*��ȡջ��Ԫ��*/
int minStackTop(MinStack* obj)
{
	return obj->stackMain.data[obj->stackHelp.top];
}

/*�õ���ǰջ����Сֵ*/
int minStackGetMin(MinStack* obj)
{
	return min;
}

/*�ͷ�����ջ*/
void minStackFree(MinStack* obj)
{
	free(obj);
}

/*������ʡ��*/
