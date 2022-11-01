#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int* data;
	int front;
	int rear;
	int size;
	double sum;
} MovingAverage;


MovingAverage* movingAverageCreate(int size)
{
	MovingAverage* obj = (MovingAverage*)malloc(sizeof(MovingAverage));
	obj->data = (int*)malloc(sizeof(int) * (size + 1));
	obj->front = 0;
	obj->rear = 0;
	obj->size = size;
	obj->sum = 0;
	return obj;
}

double movingAverageNext(MovingAverage* obj, int val)
{
	int size = (obj->rear - obj->front + obj->size + 1) % (obj->size + 1);
	if (size == obj->size)
	{
		obj->sum -= obj->data[obj->front];
		obj->front = (obj->front + 1) % (obj->size + 1);
		size--;
	}
	obj->data[obj->rear] = val;
	obj->rear = (obj->rear + 1) % (obj->size + 1);
	obj->sum += val;
	size++;
	return obj->sum / size;
}

void movingAverageFree(MovingAverage* obj)
{
	free(obj->data);
	free(obj);
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/