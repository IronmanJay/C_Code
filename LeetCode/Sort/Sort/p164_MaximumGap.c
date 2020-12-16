#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<io.h>

#define RADIX 10
#define KEYNUM 10

/*�ҵ�num�Ĵӵ͵��ߵĵ�posλ������*/
int GetNumInPos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
	{
		temp *= 10;
	}
	return (num / temp) % 10;
}

/*�������򣬲���ע�ͣ�����ο�C_Code/BigTalkDataStructure/Sort/RadixSort.c*/
void RadixSort(int* nums, int numsLen)
{
	int *radixArr[RADIX];
	for (int i = 0; i < 10; i++)
	{
		radixArr[i] = (int *)malloc(sizeof(int) * (numsLen + 1));
		radixArr[i][0] = 0;
	}
	for (int pos = 1; pos <= KEYNUM; pos++)
	{
		for (int i = 0; i < numsLen; i++)
		{
			int num = GetNumInPos(nums[i], pos);
			int index = ++radixArr[num][0];
			radixArr[num][index] = nums[i];
		}
		for (int i = 0, j = 0; i < RADIX; i++)
		{
			for (int k = 1; k <= radixArr[i][0]; k++)
			{
				nums[j++] = radixArr[i][k];
			}
			radixArr[i][0] = 0;
		}
	}
}

int maximumGap(int* nums, int numsSize)
{
	/*������鳤��С��2������0*/
	if (numsSize < 2)
	{
		return 0;
	}
	/*ʹ�û����������������*/
	RadixSort(nums, numsSize);
	/*�ҵ������*/
	int max = 0;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] - nums[i - 1] > max)
		{
			max = nums[i] - nums[i - 1];
		}
	}
	return max;
}

/*������ʡ��*/
