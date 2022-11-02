#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int* data;
	int front;
	int rear;
} RecentCounter;


RecentCounter* oII042_NumberOfRecentRequests_recentCounterCreate()
{
	RecentCounter* queue = (RecentCounter*)malloc(sizeof(RecentCounter));
	queue->data = (int*)malloc(sizeof(int) * 10001);
	queue->front = 0;
	queue->rear = 0;
	return queue;
}

int oII042_NumberOfRecentRequests_recentCounterPing(RecentCounter* obj, int t)
{
	obj->data[obj->rear++] = t;
	while (t - 3000 > obj->data[obj->front])
	{
		obj->front++;
	}
	return obj->rear - obj->front;
}

void oII042_NumberOfRecentRequests_recentCounterFree(RecentCounter* obj)
{
	free(obj->data);
	free(obj);
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/