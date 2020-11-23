#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	/*结果数组*/
	int* res = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
	/*利用哈希表思想存放不重复元素，注意这里使用calloc开辟空间初始化值为0，因为malloc初始化值未知，有可能是0，使第一个数组和第二个数组交集的集合去重出现错误*/
	int* map = (int*)calloc(1000, sizeof(int));
	/*结果数组指针*/
	int index = 0;
	/*遍历第一个数组，数组元素对应位置值为1，表示出现过还没使用过，方便和第二个数组的集合去重*/
	for (int i = 0; i < nums1Size; i++)
	{
		map[nums1[i]] = 1;
	}
	/*遍历第二个数组，只要遇到对应位置值不为0，说明有交集并且还没使用过，并且遇到交集之后这个位置对应的值重新置为0，说明已经使用过当前值进而防止出现集合出现重复元素*/
	for (int i = 0; i < nums2Size; i++)
	{
		if (map[nums2[i]] != 0)
		{
			res[index++] = nums2[i];
			map[nums2[i]] = 0;
		}
	}
	/*结果数组长度*/
	*returnSize = index;
	/*返回结果*/
	return res;
}

/*主函数省略*/
