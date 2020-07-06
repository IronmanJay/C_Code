#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 10000 /*������󳤶�*/

typedef struct
{
	int *data;
	int front; /*ͷָ��*/
	int rear; /*βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/
}RecentCounter;

/*��ʼ������*/
RecentCounter* recentCounterCreate()
{
	RecentCounter* queue = (RecentCounter *)malloc(sizeof(RecentCounter));
	queue->data = (int *)calloc(MAXSIZE, sizeof(int));
	queue->front = 0;
	queue->rear = 0;
	return queue;
}

/*ping�ĺ���*/
int recentCounterPing(RecentCounter* obj, int t)
{
	/*���Ƚ���ǰֵ�������*/
	obj->data[obj->rear++] = t;
	/*Ȼ��ʼѭ���Ѳ���[t-3000,t]�����Χ��ֵ"��"��*/
	while (obj->data[obj->front] < t - 3000)
	{
		obj->front++;
	}
	/*��󷵻ص�ǰ���еĸ���*/
	return obj->rear - obj->front;
}

/*�ͷ���Դ*/
void recentCounterFree(RecentCounter* obj)
{
	free(obj->data);
	free(obj);
}

int main(void)
{
	/*������ʡ��*/
}
