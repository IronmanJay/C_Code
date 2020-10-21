#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�����������н�С��ֵ*/
int p209_MinimumSizeSubarraySum_MIN(int x, int y)
{
	return x > y ? y : x;
}

int minSubArrayLen(int s, int* nums, int numsSize)
{
	/*�пշ���*/
	if (numsSize == 0)
	{
		return 0;
	}
	/*ͷָ��*/
	int start = 0;
	/*βָ��*/
	int end = 0;
	/*�洢��ǰ���ڣ����䣩�����ֺ�*/
	int sum = 0;
	/*��С����������ĳ���*/
	int len = numsSize + 1;
	/*��������*/
	while (end < numsSize)
	{
		/*�ۼ���ֵ���ҵ�����Ŀ��ֵ�����䣨���ڣ�*/
		sum += nums[end];
		/*�ҵ�һ�����ڣ����䣩����Ŀ��ֵ*/
		while (sum >= s)
		{
			/*������С����������ĳ���*/
			len = p209_MinimumSizeSubarraySum_MIN(len, (end - start + 1));
			/*������������ڣ����䣩��С��ǰ���ڣ����䣩����Ѱ�Ҵ��ڵ���Ŀ��ֵ��С���ڣ����䣩������еĻ�������ͷָ�����С����������ĳ���*/
			sum -= nums[start];
			start++;
		}
		/*��ǰ���ڣ����䣩�����ֺͲ����ڵ���Ŀ��ֵ�����һ�����������*/
		end++;
	}
	/*���ؽ��*/
	return len == (numsSize + 1) ? 0 : len;
}

/*������ʡ��*/
