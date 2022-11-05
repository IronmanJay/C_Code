#include<stdio.h>
#include<stdlib.h>

int* maxSlidingWindow_p239_SlidingWindowMaximum(int* nums, int numsSize, int k, int* returnSize)
{

	int* queue = (int*)malloc(sizeof(int) * numsSize);
	int front = 0;
	int rear = 0;
	int* res = (int*)malloc(sizeof(int) * (numsSize - k + 1));
	*returnSize = 0;
	for (int i = 0; i < numsSize; i++)
	{
		while ((front < rear) && nums[queue[rear - 1]] <= nums[i])
		{
			rear--;
		}
		queue[rear++] = i;
		if (queue[front] <= i - k)
		{
			front++;
		}
		if (i + 1 >= k)
		{
			res[(*returnSize)++] = nums[queue[front]];
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/