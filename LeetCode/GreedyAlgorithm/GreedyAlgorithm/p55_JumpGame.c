#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*�����������д�ֵ*/
int Max_p55_JumpGame(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

bool canJump(int* nums, int numsSize)
{
	/*��ʾÿ��λ�ÿ���������Զ����*/
	int maxLen = nums[0];
	/*��ʼ����*/
	for (int i = 1; i < numsSize; i++)
	{
		/*�����ǰλ����ǰһ��λ������������Զ���뷶Χ�ڣ�����ǰλ����������Զ�����Ƿ����ǰһ��λ������������Զ����*/
		if (i <= maxLen)
		{
			/*��������ĸ�Զ�����¿���������Զ����*/
			maxLen = Max_p55_JumpGame(maxLen, nums[i] + i);
		}
	}
	/*������յľ��볬�����һ��λ�ã������Ե������һ��λ��*/
	return maxLen >= numsSize - 1;
}

/*������ʡ��*/
