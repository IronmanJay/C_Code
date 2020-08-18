#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*定义栈数组长度*/
#define MAXSIZE 10000

/*用于比较得到最小值*/
int min;

/*比较得到最小值*/
int Min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

/*栈的结构*/
typedef struct
{
	int data[MAXSIZE];
	int top;
} Stack;

typedef struct
{
	Stack stackMain; /*主栈，用于存放值*/
	Stack stackHelp; /*辅助栈，用于存放每一次入栈之后的当前栈最小值*/
}MinStack;

/*初始化两个栈*/
MinStack* minStackCreate()
{
	min = 2147483647;
	MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
	stack->stackMain.top = -1;
	stack->stackHelp.top = -1;
	return stack;
}

/*数据入栈*/
void minStackPush(MinStack* obj, int x)
{
	/*首先获取当前元素入栈之后的栈的最小值*/
	min = Min(min, x);
	/*将元素入主栈*/
	obj->stackMain.data[++(obj->stackMain.top)] = x;
	/*将当前栈的最小值入辅助栈*/
	obj->stackHelp.data[++(obj->stackHelp.top)] = min;
}

/*弹出栈顶元素*/
void minStackPop(MinStack* obj)
{
	/*主栈弹出栈顶元素*/
	obj->stackMain.top--;
	/*因为主栈弹出了一个元素，所以辅助栈对应的弹出的栈的最小值也弹出，回到上一个存放最小值的状态*/
	obj->stackHelp.top--;
	/*如果辅助栈空了，说明没有最小值了，重新赋值得到最小值*/
	if (obj->stackHelp.top == -1)
	{
		min = 2147483647;
	}
	/*如果没空，因为辅助栈对应每一个栈状态的最小值，所以将min重新赋值为弹出栈顶元素之后当前栈对应的最小值，为了getMin()方法做准备*/
	else
	{
		min = obj->stackHelp.data[obj->stackHelp.top];
	}
}

/*获取栈顶元素*/
int minStackTop(MinStack* obj)
{
	return obj->stackMain.data[obj->stackHelp.top];
}

/*得到当前栈的最小值*/
int minStackGetMin(MinStack* obj)
{
	return min;
}

/*释放两个栈*/
void minStackFree(MinStack* obj)
{
	free(obj);
}

/*主函数省略*/
