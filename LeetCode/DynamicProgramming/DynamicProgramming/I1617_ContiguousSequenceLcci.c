#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*���������нϴ�ֵ*/
int I1617_ContiguousSequenceLcci_Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int I1617_ContiguousSequenceLcci_Max_maxSubArray(int* nums, int numsSize)
{
	/*�пշ���0*/
	if (numsSize == 0)
	{
		return 0;
	}
	/*���ֻ��һ��Ԫ�أ�ֱ�ӷ���*/
	if (numsSize == 1)
	{
		return nums[0];
	}
	/*��̬���飬�洢�ۼ���ֵ*/
	int* dp = (int*)malloc(sizeof(int) * numsSize);
	/*��һ���ۼӾ�������ĵ�һ��ֵ*/
	dp[0] = nums[0];
	/*���ֵ����ʼֵΪ�����һ��Ԫ�أ����ϸ��£���󷵻��ܺ������������к�*/
	int max = nums[0];
	/*�ӵڶ���Ԫ�ؿ�ʼ������������*/
	for (int i = 1; i < numsSize; i++)
	{
		/*��̬�����Ӧλ�ô洢��ǰλ��Ԫ�غ�֮ǰ�ĺ�Ԫ���нϴ��ֵ*/
		dp[i] = I1617_ContiguousSequenceLcci_Max((dp[i - 1] + nums[i]), nums[i]);
		/*�������ֵ*/
		max = I1617_ContiguousSequenceLcci_Max(max, dp[i]);
	}
	/*���ؽ��*/
	return max;
}

/*������ʡ��*/
