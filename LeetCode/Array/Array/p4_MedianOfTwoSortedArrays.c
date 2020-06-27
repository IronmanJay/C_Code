#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/*�������ֵ��Сֵ*/
#define MAX_VALUE 65535
#define MIN_VALUE -65535

/*ȡ�������нϴ����*/
int p4_MAX(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

/*ȡ�������н�С����*/
int p4_MIN(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	
	/*�����������ĳ���*/
	int m = nums1Size;
	int n = nums2Size;
	/*��һ�����ҳ�x�������鳤�Ƚ�С��������Ϊnums1�������������*/
	if (m > n)
	{
		int* tempArr = nums1;
		nums1 = nums2;
		nums2 = tempArr;
		int tempLen = m;
		m = n;
		n = tempLen;
	}
	/*���ݹ�ʽ�ó���Ҫ��������ߵĸ���*/
	int totalLeft = (m + n + 1) / 2;
	/*������ָ�����ָ�룬��nums1Ϊ׼*/
	int left = 0;
	int right = m;
	/*��ʼѭ������nums1�����������ѭ����i��nums1�����������j��nums2���������*/
	while (left < right)
	{
		/*��nums1���м俪ʼ*/
		int i = left + (right - left) / 2;
		/*�����Ҫ������Ԫ�ظ�����ȥi����nums2�������Ԫ�صĸ���*/
		int j = totalLeft - i;
		/*���nums2[j-1] > nums1[i]��˵��nums1�ķֽ�����Ҫ���ң���[i right]����������Ѱ��*/
		if (nums2[j - 1] > nums1[i])
		{
			/*��һ��[i+1 right]����������Ѱ��*/
			left = i + 1;
		}
		else
		{
			/*����Ҫ���right��ֵ,��һ����[left i]����������Ѱ�ң�����������ѭ��*/
			right = i;
		}
	}
	/*�����ҵ��ֽ���*/
	int i = left;
	int j = totalLeft - i;
	/*�ҵ��ֽ������ߵ�ֵ*/
	int nums1LeftMax = i == 0 ? MIN_VALUE : nums1[i - 1];
	int nums1RightMin = i == m ? MAX_VALUE : nums1[i];
	int nums2LeftMax = j == 0 ? MIN_VALUE : nums2[j - 1];
	int nums2RightMin = j == n ? MAX_VALUE : nums2[j];
	/*����ж�������鳤��Ϊ�������طֽ���������ֵ�������ż�������طֽ�������ֵ��һ��*/
	if (((m + n) % 2) == 1)
	{
		return p4_MAX(nums1LeftMax, nums2LeftMax);
	}
	else
	{
		return (double)((p4_MAX(nums1LeftMax, nums2LeftMax) + p4_MIN(nums1RightMin, nums2RightMin))) / 2;
	}
}

/*������ʡ��*/
