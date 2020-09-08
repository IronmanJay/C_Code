#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int missingNumber(int* nums, int numsSize)
{
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = (right - left) / 2 + left;
		/*����м��������м�ֵ��ȣ�˵��nums[0,mid]�ǲ�ȱ��ֵ�ģ���Ϊ�����������ȱ��ֵ�������������ʹ�λ�ˣ��������ұ߲���*/
		if (nums[mid] == mid)
		{
			left = mid + 1;
		}
		/*����м��������м�ֵ����ȣ�˵��nums[0,mid]��ȱ��ֵ�ģ���Ϊ�����������ȱ��ֵ�������������ʹ�λ�ˣ���������߲��ң�����˵����ǰλ���п��ܾ���ȱʧֵ��ͬʱ��Ϊwhileѭ����������ֹ����*/
		else
		{
			right = mid - 1;
		}
	}
	/*��Ϊ���right�Ǵ�λ��mid-1��˵��right��ȱʧֵ֮ǰ����һ��Ԫ�أ���left��û��λ��mid+1��Ҳ�ͱ�֤��left����ȱʧֵ�����ؼ���*/
	return left;
}

/*������ʡ��*/
