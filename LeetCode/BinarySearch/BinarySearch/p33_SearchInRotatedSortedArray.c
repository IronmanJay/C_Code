#include<stdio.h>
#include<stdlib.h>

int search(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	/*������ֲ���*/
	while (left <= right)
	{
		/*�����м�ֵ*/
		int mid = (left + right) / 2;
		/*����ҵ���ֱ�ӷ���*/
		if (nums[mid] == target)
		{
			return mid;
		}
		/*����м�ֵ������ߵ�ֵ��˵����ߵ������������*/
		if (nums[mid] >= nums[left])
		{
			/*�����ǰ���£����target>=���ֵ����target<=�м�ֵ����ô˵��targetһ������ߣ���ô�仯�ұߵ�ֵ������targetһ�����ұߣ��仯��ߵ�ֵ*/
			if (target >= nums[left] && target <= nums[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else
		{
			/*����м�ֵ��������ߵ�ֵ��˵���ұߵ�����������ģ�ͬ�������target<=�ұ�ֵ����target>=�м�ֵ����ô˵��targetһ�����ұߣ���ô�仯��ߵ�ֵ������targetһ������ߣ��仯�ұߵ�ֵ*/
			if (target >= nums[mid] && target <= nums[right])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
	return -1;
}

/*������ʡ��*/