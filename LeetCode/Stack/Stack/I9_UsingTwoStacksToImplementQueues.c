#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*两个栈的结构体*/
typedef struct
{
	int stackIn_count;
	int stackOut_count;
	int *stackIn;
	int *stackOut;
} CQueue;

/*创建两个栈*/
CQueue* cQueueCreate()
{
	CQueue *obj = (CQueue *)malloc(sizeof(CQueue));
	obj->stackIn_count = 0;
	obj->stackOut_count = 0;
	obj->stackIn = (int *)malloc(sizeof(int) * 10000);
	obj->stackOut = (int *)malloc(sizeof(int) * 10000);
	return obj;
}

/*在stackIn的尾部添加数据*/
void cQueueAppendTail(CQueue* obj, int value)
{
	obj->stackIn[obj->stackIn_count++] = value;
}

/*在stackOut的头部弹出元素*/
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

/*释放空间*/
void cQueueFree(CQueue* obj)
{
	free(obj->stackIn);
	free(obj->stackOut);
	free(obj);
}

/*主函数省略*/
