#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	/*�Ӻ���ǰ���*/
	int index1 = m - 1;
	int index2 = n - 1;
	int tail = m + n - 1;
	/*ֻҪ�Ǵ��Ԫ�ؾ�д��nums1�ĺ��棬ǰ��������λ�þ���nums2��Ԫ��*/
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

/*������ʡ��*/
