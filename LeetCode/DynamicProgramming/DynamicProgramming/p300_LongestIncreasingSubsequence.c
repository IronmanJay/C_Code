#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*��������֮��ϴ�ֵ*/
int p300_LongestIncreasingSubsequence_max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int lengthOfLIS(int* nums, int numsSize)
{
	/*��̬���飺��ŵ�ÿ��λ�õ������������еĳ���*/
	int* dp = (int*)malloc(sizeof(int)*numsSize);
	/*ÿ��λ�ó�ʼ����������������еĳ��Ⱦ����������Գ���Ϊ1*/
	for (int i = 0; i < numsSize; i++)
	{
		dp[i] = 1;
	}
	/*��Ž����Ĭ�ϳ���Ϊ1*/
	int res = 1;
	/*������ĵ�һ��λ�ÿ�ʼ�������൱�������λ�õ�ǰ��Ԫ�ؿ��Ƿ��е���������*/
	for (int i = 1; i < numsSize; i++)
	{
		/*��i֮ǰ������������*/
		for (int j = 0; j < i; j++)
		{
			/*���[0,i]�е�����Ԫ�أ����¶�̬�����ֵ*/
			if (nums[j] < nums[i])
			{
				/*��̬ת�Ʒ��̣�����һ����λ��iС��Ԫ����ô�϶������е����������У�����λ��i������������еĳ���*/
				dp[i] = p300_LongestIncreasingSubsequence_max(dp[j] + 1, dp[i]);
			}
		}
		/*ͬʱ���½��*/
		res = p300_LongestIncreasingSubsequence_max(res, dp[i]);
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
