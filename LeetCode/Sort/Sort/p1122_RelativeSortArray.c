#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	/*��Ϊһ�����1000���������Զ������鳤��Ϊ1001*/
	int nums[1001] = { 0 };
	int numsLen = sizeof(nums) / sizeof(int);
	/*���������飬��arr1һ������*/
	int *res = (int *)malloc(arr1Size * sizeof(int));
	/*����arr1��ͳ��ÿ��Ԫ�صĸ���*/
	for (int i = 0; i < arr1Size; i++)
	{
		nums[arr1[i]]++;
	}
	/*����arr2����arr2��arr1�г��ֵ�Ԫ�ذ���arr2��˳�����������*/
	int index = 0;
	for (int i = 0; i < arr2Size; i++)
	{
		/*�����Ӧλ�õ�ֵ>0��˵���ҵ���arr2��arr1�е�Ԫ�أ���ô�ͽ���������������飬�м����漸����˳���arr2һ����Ȼ��nums��Ӧλ�õ�ֵ-1����ȥ��arr2���Ԫ��*/
		while (nums[arr2[i]] > 0)
		{
			res[index++] = arr2[i];
			nums[arr2[i]]--;
		}
	}
	/*����nums������ȥarr2�е�Ԫ�ؽ�������ע�����������ͷ��ʼ�����������൱��������*/
	for (int i = 0; i < numsLen; i++)
	{
		/*���whileѭ��˵�����Ԫ�ؾ���arr2��û�еģ���ô�������뵽�������*/
		while (nums[i] > 0)
		{
			res[index++] = i;
			nums[i]--;
		}
	}
	/*���ؽ������*/
	*returnSize = arr1Size;
	return res;
}

/*������ʡ��*/
