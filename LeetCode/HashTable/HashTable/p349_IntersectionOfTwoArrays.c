#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	/*�������*/
	int* res = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
	/*���ù�ϣ��˼���Ų��ظ�Ԫ�أ�ע������ʹ��calloc���ٿռ��ʼ��ֵΪ0����Ϊmalloc��ʼ��ֵδ֪���п�����0��ʹ��һ������͵ڶ������齻���ļ���ȥ�س��ִ���*/
	int* map = (int*)calloc(1000, sizeof(int));
	/*�������ָ��*/
	int index = 0;
	/*������һ�����飬����Ԫ�ض�Ӧλ��ֵΪ1����ʾ���ֹ���ûʹ�ù�������͵ڶ�������ļ���ȥ��*/
	for (int i = 0; i < nums1Size; i++)
	{
		map[nums1[i]] = 1;
	}
	/*�����ڶ������飬ֻҪ������Ӧλ��ֵ��Ϊ0��˵���н������һ�ûʹ�ù���������������֮�����λ�ö�Ӧ��ֵ������Ϊ0��˵���Ѿ�ʹ�ù���ǰֵ������ֹ���ּ��ϳ����ظ�Ԫ��*/
	for (int i = 0; i < nums2Size; i++)
	{
		if (map[nums2[i]] != 0)
		{
			res[index++] = nums2[i];
			map[nums2[i]] = 0;
		}
	}
	/*������鳤��*/
	*returnSize = index;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
