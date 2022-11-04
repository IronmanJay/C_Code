#include<stdio.h>
#include<stdlib.h>

compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize)
{
	int* queue = (int*)malloc(sizeof(int) * (2 * deckSize));
	int rear = 0;
	int front = 0;
	for (int i = 0; i < deckSize; i++) {
		queue[rear++] = i;
	}
	qsort(deck, deckSize, sizeof(deck[0]), compare);
	int* res = (int*)malloc(sizeof(int) * deckSize);
	for (int i = 0; i < deckSize; i++)
	{
		int num = deck[i];
		res[queue[front++]] = num;
		if (front != rear)
		{
			queue[rear++] = queue[front++];
		}
	}
	*returnSize = deckSize;
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/