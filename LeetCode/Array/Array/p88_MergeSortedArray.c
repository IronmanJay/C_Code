#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	/*从后向前填充*/
	int index1 = m - 1;
	int index2 = n - 1;
	int tail = m + n - 1;
	/*只要是大的元素就写到nums1的后面，前面留出来位置就是nums2的元素*/
	while (index2 >= 0)
	{
		if (index1 >= 0 && nums1[index1] > nums2[index2])
		{
			nums1[tail] = nums1[index1];
			tail--;
			index1--;
		}
		else
		{
			nums1[tail] = nums2[index2];
			tail--;
			index2--;
		}
	}
}

/*主函数省略*/
