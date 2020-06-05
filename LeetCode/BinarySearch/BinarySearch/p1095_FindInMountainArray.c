#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findInMountainArray(int target, int* mountainArr) {
	/*�����Ѿ��ҵ��ķ嶥Ԫ���±�*/
	int topIndex = findPeakElement_1095(mountainArr);
	/*���Ŀ��ֵ���ڷ�ֵ����ô���ü����ж��ˣ�ֱ�ӷ���*/
	if (mountainArr[topIndex] < target)
	{
		return -1;
	}
	/*�������鳤��*/
	int len = sizeof(mountainArr) / sizeof(int);
	/*��������һ��ֵС��Ŀ��ֵ��˵����������������*/
	if (mountainArr[0] <= target)
	{
		int left = 0;
		int right = topIndex;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			int mVal = mountainArr[mid];
			if (mVal == target) 
			{
				return mid;
			}
			else if (target < mVal)
			{
				right = mid - 1;
			}
			else if (target > mVal)
			{
				left = mid + 1;
			}
		}
	}
	/*����������һ��ֵС��Ŀ��ֵ��˵���ұ߽������Ҳ���*/
	if (mountainArr[len - 1] <= target)
	{
		int left = topIndex;
		int right = len - 1;
		int mid;
		while (left <= right) 
		{
			mid = left + (right - left) / 2;
			int mVal = mountainArr[mid];
			if (mVal == target)
			{
				return mid;
			}
			else if (target < mVal)
			{
				left = mid + 1;
			}
			else if (target > mVal)
			{
				right = mid - 1;
			}
		}
	}
	return -1;
}

/*���ڷ��ط嶥Ԫ��*/
int findPeakElement_1095(int* nums)
{
	/*���ȶ�������ָ��*/
	int left = 0;
	int right = sizeof(nums) / sizeof(int) - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int mVal = nums[mid];
		/*������Ԫ�ش�����������Ԫ�أ���ô��������Ҫ�ҵ�*/
		if (mVal > nums[mid + 1] && mVal > nums[mid - 1]) 
		{
			return mid;
		}
		/*�����ǰԪ��С�����ұߵ�Ԫ�أ���ô˵��Ҫ���ұ���*/
		if (mVal < nums[mid + 1])
		{
			left = mid + 1;
		}
		/*�����ǰԪ��С������ߵ�Ԫ�أ���ô˵��Ҫ������� */
		else if (mVal < nums[mid - 1])
		{
			right = mid - 1;
		}
	}
	return -1;
}

/*������ʡ��*/
