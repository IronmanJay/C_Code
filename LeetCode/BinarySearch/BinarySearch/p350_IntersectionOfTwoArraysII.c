#include<stdio.h>
#include<stdlib.h>

int *intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	/*ʹ��������δ��빹�췵�������С*/
	*returnSize = nums1Size > nums2Size ? nums1Size : nums2Size;
	/*����������*/
	int *res = (int *)calloc((*returnSize + 1), sizeof(int));
	/*��Ӧ�±�*/
	int size = 0;
	/*ʹ������forѭ���Ƚ����������е�ÿ��Ԫ��*/
	for (int i = 0; i < nums1Size; i++)
	{
		for (int j = 0; j < nums2Size; j++)
		{
			/*���ĳһ��λ�õ�Ԫ�����*/
			if (nums1[i] == nums2[j])
			{
				/*�����Ԫ�ر��浽�������*/
				res[size] = nums1[i];
				/*��nums2��Ӧ�����Ԫ��ɾ�������������һ��Ԫ�����*/
				nums2[j] = nums2[nums2Size - 1];
				/*nums2��Ӧ�ĳ��Ⱦ�-1*/
				nums2Size--;
				/*�±�+1*/
				size++;
				/*�������ȵģ�ֱ���������ѭ��������������һ������*/
				break;
			}
		}
	}
	/*���ص������С*/
	*returnSize = size;
	/*���ص�����*/
	return res;
}

/*������ʡ��*/
