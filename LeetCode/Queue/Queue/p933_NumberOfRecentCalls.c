#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 10000 /*队列最大长度*/

typedef struct
{
	int *data;
	int front; /*头指针*/
	int rear; /*尾指针，若队列不空，指向队列尾元素的下一个位置*/
}RecentCounter;

/*初始化队列*/
RecentCounter* recentCounterCreate()
{
	RecentCounter* queue = (RecentCounter *)malloc(sizeof(RecentCounter));
	queue->data = (int *)calloc(MAXSIZE, sizeof(int));
	queue->front = 0;
	queue->rear = 0;
	return queue;
}

/*ping的函数*/
int recentCounterPing(RecentCounter* obj, int t)
{
	/*首先将当前值加入队列*/
	obj->data[obj->rear++] = t;
	/*然后开始循环把不在[t-3000,t]这个范围的值"弹"出*/
	while (obj->data[obj->front] < t - 3000)
	{
		obj->front++;
	}
	/*最后返回当前队列的个数*/
	return obj->rear - obj->front;
}

/*释放资源*/
void recentCounterFree(RecentCounter* obj)
{
	free(obj->data);
	free(obj);
}

int main(void)
{
	/*主函数省略*/
}
