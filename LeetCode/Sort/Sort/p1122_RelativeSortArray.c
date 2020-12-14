#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	/*因为一共最多1000个数，所以定义数组长度为1001*/
	int nums[1001] = { 0 };
	int numsLen = sizeof(nums) / sizeof(int);
	/*定义结果数组，和arr1一样长度*/
	int *res = (int *)malloc(arr1Size * sizeof(int));
	/*遍历arr1，统计每个元素的个数*/
	for (int i = 0; i < arr1Size; i++)
	{
		nums[arr1[i]]++;
	}
	/*遍历arr2，将arr2在arr1中出现的元素按照arr2的顺序存入结果数组*/
	int index = 0;
	for (int i = 0; i < arr2Size; i++)
	{
		/*如果对应位置的值>0，说明找到了arr2在arr1中的元素，那么就将这个数存入结果数组，有几个存几个，顺序和arr2一样，然后nums对应位置的值-1，减去了arr2这个元素*/
		while (nums[arr2[i]] > 0)
		{
			res[index++] = arr2[i];
			nums[arr2[i]]--;
		}
	}
	/*遍历nums，将除去arr2中的元素进行排序，注意这里数组从头开始遍历，所以相当于排序了*/
	for (int i = 0; i < numsLen; i++)
	{
		/*这个while循环说明这个元素就是arr2中没有的，那么将它加入到结果数组*/
		while (nums[i] > 0)
		{
			res[index++] = i;
			nums[i]--;
		}
	}
	/*返回结果数组*/
	*returnSize = arr1Size;
	return res;
}

/*主函数省略*/
