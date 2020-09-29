#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*���������нϴ�ֵ*/
int p198_HouseRobber_Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int rob(int* nums, int numsSize)
{
	/*���鳤��Ϊ0����0�����鳤��Ϊ1���ص�һ����*/
	if (numsSize <= 1)
	{
		return numsSize == 0 ? 0 : nums[0];
	}
	/*��̬���飬��Ӧλ�ô�ŵ�����ط��ܻ�ȡ�����ֵ*/
	int* dp = (int*)malloc(sizeof(int)*numsSize);
	/*��һ�������ܻ�ȡ�����ֵ���ǵ�ǰֵ*/
	dp[0] = nums[0];
	/*�ڶ��������ܻ�ȡ�����ֵ�ǵ�һ��λ�ú͵ڶ���λ���еĽϴ�ֵ������ѡ��Ǯ��ķ���͵Ǯ*/
	dp[1] = p198_HouseRobber_Max(nums[0], nums[1]);
	/*�ӵ��������ݿ�ʼ����*/
	for (int i = 2; i < numsSize; i++)
	{
		/*�����Ӧ�ķ��ݸ��¿���͵��ǮΪ��ǰ�ķ��ݼ�֮ǰ�ķ��ݣ�i-2����֮ǰ�ķ��ݣ�i-1���еĽϴ�ֵ����Ϊ�б���װ�ã����Ը��ŷ���͵Ǯ*/
		dp[i] = p198_HouseRobber_Max(dp[i - 1], nums[i] + dp[i - 2]);
	}
	/*���ϸ��¶�̬���飬���һ��Ԫ�ؾ�����͵�����Ǯ*/
	return dp[numsSize - 1];
}

/*������ʡ��*/
