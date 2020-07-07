#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
	/*�������Ϊ��ֱ�ӷ���*/
	if (numsSize == 0)
	{
		*returnSize = 0;
		return nums;
	}
	/*�������*/
	int* queue = (int *)malloc(numsSize * sizeof(int));
	/*����������*/
	int* res = (int *)malloc(numsSize * sizeof(int));
	/*ͷָ��*/
	int front = 0;
	/*βָ��*/
	int rear = 0;
	/*�����������±�*/
	int index = 0;
	/*��ʼѭ��*/
	for (int i = 0; i < numsSize; i++)
	{
		/*��Ϊ����Ҫά�������������������ǴӴ�С�ģ���������������һ��Ԫ��С�ڵ������鵱ǰֵ����ô�����������һ��Ԫ�أ�������Ԫ��*/
		while (front < rear && nums[queue[rear - 1]] <= nums[i]);
		{
			rear--;
		}
		/*����Ͱ����鵱ǰֵ���뵽��������棬˳����Ȼ�ǴӴ�С*/
		queue[rear++] = i;
		/*��������Ѿ������˶���ͷ����Ԫ�أ���ô���Ԫ���ò�������Ҫ�Ѻ����Ԫ�ء����������ͽ�ͷԪ�ص�������*/
		if (queue[front] == i - k)
		{
			front++;
		}
		/*����ﵽһ�����ڴ�С����ô�������ͼ��뵱ǰ�������ֵ�����˵�һ����Ҫ������ֵΪһ�����ڣ��������һ��ֵ�����γ�һ������*/
		if (i >= k - 1)
		{
			res[index++] = nums[queue[front]];
		}
	}
	/*���ؽ��*/
	*returnSize = index;
	return res;
}