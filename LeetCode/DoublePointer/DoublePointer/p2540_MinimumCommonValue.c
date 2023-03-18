#include<stdio.h>

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int index1 = 0;
	int index2 = 0;
	while (index1 < nums1Size && index2 < nums2Size)
	{
		if (nums1[index1] == nums2[index2])
		{
			return nums1[index1];
		}
		else if (nums1[index1] < nums2[index2])
		{
			index1++;
		}
		else if (nums1[index1] > nums2[index2])
		{
			index2++;
		}
	}
	return -1;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/