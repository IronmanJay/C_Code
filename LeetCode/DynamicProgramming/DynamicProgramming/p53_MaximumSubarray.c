#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*��������֮��ϴ�ֵ*/
int p53_MaximumSubarray_max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int p53_MaximumSubarray_maxSubArray(int* nums, int numsSize)
{
	/*��̬�������飬��ŵ���ÿһ��λ�õ����ֵ*/
	int* dp = (int*)calloc(numsSize, sizeof(int));
	/*�����һ��λ�õ����ֵ�϶�����nums�е�һ��Ԫ��*/
	dp[0] = nums[0];
	/*������������*/
	for (int i = 1; i < numsSize; i++)
	{
		/*��̬ת�Ʒ��̣�ע����ֻ�ǰѵ���ǰλ�õ����ֵ�ҳ���������������ҳ���һ������������*/
		dp[i] = p53_MaximumSubarray_max(nums[i], nums[i] + dp[i - 1]);
	}
	/*����ҳ������������ֵ���ǽ��*/
	int max = -2147483648;
	for (int i = 0; i < numsSize; i++)
	{
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	/*���ؽ��*/
	return max;
}

/*������ʡ��*/
