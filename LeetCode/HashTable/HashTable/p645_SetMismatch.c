#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*自定义排序，一维数组从小到大排序*/
int compare_p645_SetMismatch(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
	/*判空返回*/
	if (numsSize == 0)
	{
		return nums;
	}
	/*结果数组*/
	int* res = (int*)malloc(2 * sizeof(int));
	/*存放不重复元素的数组，类似哈希表的思想，这里注意要使用calloc，初始化为0，否则会出错，因为后面会根据这个判断结果*/
	int* arr = (int*)calloc((numsSize + 1), sizeof(int));
	/*一维数组从小到大排序*/
	qsort(nums, numsSize, sizeof(int), compare_p645_SetMismatch);
	/*遍历整个数组*/
	for (int i = 0; i < numsSize; i++)
	{
		/*计算每个元素出现的次数*/
		arr[nums[i]]++;
	}
	/*从1~n遍历*/
	for (int i = 1; i <= numsSize; i++)
	{
		/*如果出现两次说明是重复值，放到结果数组的第一个位置*/
		if (arr[i] == 2)
		{
			res[0] = i;
		}
		/*如果一次都没出现说明是缺失值，放到结果数组的第二个位置*/
		if (arr[i] == 0)
		{
			res[1] = i;
		}
	}
	/*返回数组大小为2*/
	*returnSize = 2;
	/*返回结果*/
	return res;
}

/*主函数省略*/
