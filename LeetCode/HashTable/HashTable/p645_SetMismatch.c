#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�Զ�������һά�����С��������*/
int compare_p645_SetMismatch(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
	/*�пշ���*/
	if (numsSize == 0)
	{
		return nums;
	}
	/*�������*/
	int* res = (int*)malloc(2 * sizeof(int));
	/*��Ų��ظ�Ԫ�ص����飬���ƹ�ϣ���˼�룬����ע��Ҫʹ��calloc����ʼ��Ϊ0������������Ϊ������������жϽ��*/
	int* arr = (int*)calloc((numsSize + 1), sizeof(int));
	/*һά�����С��������*/
	qsort(nums, numsSize, sizeof(int), compare_p645_SetMismatch);
	/*������������*/
	for (int i = 0; i < numsSize; i++)
	{
		/*����ÿ��Ԫ�س��ֵĴ���*/
		arr[nums[i]]++;
	}
	/*��1~n����*/
	for (int i = 1; i <= numsSize; i++)
	{
		/*�����������˵�����ظ�ֵ���ŵ��������ĵ�һ��λ��*/
		if (arr[i] == 2)
		{
			res[0] = i;
		}
		/*���һ�ζ�û����˵����ȱʧֵ���ŵ��������ĵڶ���λ��*/
		if (arr[i] == 0)
		{
			res[1] = i;
		}
	}
	/*���������СΪ2*/
	*returnSize = 2;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
