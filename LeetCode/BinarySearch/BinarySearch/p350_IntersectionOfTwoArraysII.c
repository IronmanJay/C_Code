#include<stdio.h>
#include<stdlib.h>

int *intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	/*使用下面这段代码构造返回数组大小*/
	*returnSize = nums1Size > nums2Size ? nums1Size : nums2Size;
	/*构造结果数组*/
	int *res = (int *)calloc((*returnSize + 1), sizeof(int));
	/*对应下标*/
	int size = 0;
	/*使用两层for循环比较两个数组中的每个元素*/
	for (int i = 0; i < nums1Size; i++)
	{
		for (int j = 0; j < nums2Size; j++)
		{
			/*如果某一个位置的元素相等*/
			if (nums1[i] == nums2[j])
			{
				/*将这个元素保存到结果数组*/
				res[size] = nums1[i];
				/*将nums2对应的这个元素删掉，用数组最后一个元素填充*/
				nums2[j] = nums2[nums2Size - 1];
				/*nums2对应的长度就-1*/
				nums2Size--;
				/*下标+1*/
				size++;
				/*如果有相等的，直接跳出这次循环，继续查找下一个数字*/
				break;
			}
		}
	}
	/*返回的数组大小*/
	*returnSize = size;
	/*返回的数组*/
	return res;
}

/*主函数省略*/
