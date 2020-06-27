#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/*定义最大值最小值*/
#define MAX_VALUE 65535
#define MIN_VALUE -65535

/*取两个数中较大的数*/
int p4_MAX(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

/*取两个数中较小的数*/
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
	
	/*获得两个数组的长度*/
	int m = nums1Size;
	int n = nums2Size;
	/*这一步是找出x两个数组长度较小的数组作为nums1，方便后续步骤*/
	if (m > n)
	{
		int* tempArr = nums1;
		nums1 = nums2;
		nums2 = tempArr;
		int tempLen = m;
		m = n;
		n = tempLen;
	}
	/*根据公式得出需要的数组左边的个数*/
	int totalLeft = (m + n + 1) / 2;
	/*定义左指针和右指针，以nums1为准*/
	int left = 0;
	int right = m;
	/*开始循环，当nums1遍历完毕跳出循环，i是nums1数组的索引，j是nums2数组的索引*/
	while (left < right)
	{
		/*从nums1的中间开始*/
		int i = left + (right - left) / 2;
		/*左边需要的所有元素个数减去i就是nums2左边所有元素的个数*/
		int j = totalLeft - i;
		/*如果nums2[j-1] > nums1[i]，说明nums1的分界线需要向右，在[i right]这个区间继续寻找*/
		if (nums2[j - 1] > nums1[i])
		{
			/*下一轮[i+1 right]这个区间继续寻找*/
			left = i + 1;
		}
		else
		{
			/*符合要求给right赋值,下一轮在[left i]这个区间继续寻找，否则会造成死循环*/
			right = i;
		}
	}
	/*最终找到分界线*/
	int i = left;
	int j = totalLeft - i;
	/*找到分界线两边的值*/
	int nums1LeftMax = i == 0 ? MIN_VALUE : nums1[i - 1];
	int nums1RightMin = i == m ? MAX_VALUE : nums1[i];
	int nums2LeftMax = j == 0 ? MIN_VALUE : nums2[j - 1];
	int nums2RightMin = j == n ? MAX_VALUE : nums2[j];
	/*最后判断如果数组长度为奇数返回分界线左边最大值，如果是偶数，返回分界线两边值的一半*/
	if (((m + n) % 2) == 1)
	{
		return p4_MAX(nums1LeftMax, nums2LeftMax);
	}
	else
	{
		return (double)((p4_MAX(nums1LeftMax, nums2LeftMax) + p4_MIN(nums1RightMin, nums2RightMin))) / 2;
	}
}

/*主函数省略*/
