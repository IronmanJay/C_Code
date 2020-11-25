#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*�Զ������򣬴�С��������*/
int compare_I1624_PairsWithSumLcci(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
	/*�½�������鲢���ٿռ�*/
	int** res = (int**)malloc(sizeof(int*)*(numsSize / 2));
	*returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize / 2));
	for (int i = 0; i < numsSize / 2; i++)
	{
		res[i] = (int*)malloc(sizeof(int) * 2);
		(*returnColumnSizes)[i] = 2;
	}
	/*��С��������*/
	qsort(nums, numsSize, sizeof(int), compare_I1624_PairsWithSumLcci);
	/*�����������*/
	int index = 0;
	/*����������ָ��*/
	int left = 0;
	/*����������ָ��*/
	int right = numsSize - 1;
	/*��ʼ����*/
	while (left < right)
	{
		/*����ҵ�һ�Լ��뵽������飬*/
		if (nums[left] + nums[right] == target)
		{
			res[index][0] = nums[left];
			res[index++][1] = nums[right];
			left++;
			right--;
		}
		/*�����ǰ��һ�Ժʹ���Ŀ��ֵ����ָ������*/
		else if (nums[left] + nums[right] > target)
		{
			right--;
		}
		/*�����ǰ��һ�Ժ�С��Ŀ��ֵ����ָ������*/
		else
		{
			left++;
		}
	}
	/*�������鳤��*/
	*returnSize = index;
	/*�������*/
	return res;
}

/*������ʡ��*/
