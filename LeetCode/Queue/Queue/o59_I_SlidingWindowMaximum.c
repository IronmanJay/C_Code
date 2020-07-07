#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
	/*如果数组为空直接返回*/
	if (numsSize == 0)
	{
		*returnSize = 0;
		return nums;
	}
	/*定义队列*/
	int* queue = (int *)malloc(numsSize * sizeof(int));
	/*定义结果数组*/
	int* res = (int *)malloc(numsSize * sizeof(int));
	/*头指针*/
	int front = 0;
	/*尾指针*/
	int rear = 0;
	/*定义结果数组下标*/
	int index = 0;
	/*开始循环*/
	for (int i = 0; i < numsSize; i++)
	{
		/*因为我们要维护这个队列里面的数据是从大到小的，所以如果队列最后一个元素小于等于数组当前值，那么弹出队列最后一个元素，加入新元素*/
		while (front < rear && nums[queue[rear - 1]] <= nums[i]);
		{
			rear--;
		}
		/*下面就把数组当前值加入到队列最后面，顺序仍然是从大到小*/
		queue[rear++] = i;
		/*如果窗口已经划过了队列头部的元素，那么这个元素用不到，需要把后面的元素“升级”，就将头元素弹出队列*/
		if (queue[front] == i - k)
		{
			front++;
		}
		/*如果达到一个窗口大小，那么结果数组就加入当前队列最大值，除了第一次需要等三个值为一个窗口，后面进来一个值就能形成一个窗口*/
		if (i >= k - 1)
		{
			res[index++] = nums[queue[front]];
		}
	}
	/*返回结果*/
	*returnSize = index;
	return res;
}