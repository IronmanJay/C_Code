#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�Զ�������*/
int p16_3SumClosest_compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
	/*�������������*/
	qsort(nums, numsSize, sizeof(int), p16_3SumClosest_compare);
	/*����ǰ������������ӽ�������֮�ͣ�Ϊ�����Ƚ���׼��*/
	int resThreeSumClosest = nums[0] + nums[1] + nums[2];
	/*�����������飬i<nums.length-2��Ϊ�˱�֤ÿ�ζ������γ��������ĺ�*/
	for (int i = 0; i < numsSize - 2; i++)
	{
		/*��ָ��Ϊ��ǰλ�õ���һ��λ��*/
		int left = i + 1;
		/*��ָ��Ϊ�������һ��Ԫ��*/
		int right = numsSize - 1;
		/*��ʼ������ǰ����*/
		while (left < right)
		{
			/*��ǰ������֮��*/
			int curThreeSumClosest = nums[i] + nums[left] + nums[right];
			/*�����ǰ������֮����Ŀ��ֵ�Ĳ�ֵ��֮ǰ���������֮����Ŀ��ֵ�Ĳ�ֵС��������ӽ�������֮��Ϊ��ǰ���С������֮��*/
			if (abs(curThreeSumClosest - target) < abs(resThreeSumClosest - target))
			{
				resThreeSumClosest = curThreeSumClosest;
			}
			/*�����ǰ������֮�ʹ���Ŀ��ֵ�������Ҹ��ӽ�������֮��*/
			else if (curThreeSumClosest > target)
			{
				right--;
			}
			/*�����ǰ������֮��С��Ŀ��ֵ�������Ҹ��ӽ�������֮��*/
			else if (curThreeSumClosest < target)
			{
				left++;
			}
			/*�����ǰ������֮�����õ���Ŀ��ֵ��˵���������ӽ��ģ�ֱ�ӷ��ؼ���*/
			else
			{
				return target;
			}
		}
	}
	/*���ؽ��*/
	return resThreeSumClosest;
}

/*������ʡ��*/
