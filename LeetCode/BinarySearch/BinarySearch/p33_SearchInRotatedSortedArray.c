#include<stdio.h>
#include<stdlib.h>

int search(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	/*进入二分查找*/
	while (left <= right)
	{
		/*定义中间值*/
		int mid = (left + right) / 2;
		/*如果找到了直接返回*/
		if (nums[mid] == target)
		{
			return mid;
		}
		/*如果中间值大于左边的值，说明左边的数组是升序的*/
		if (nums[mid] >= nums[left])
		{
			/*在这个前提下，如果target>=左边值并且target<=中间值，那么说明target一定在左边，那么变化右边的值，否则target一定在右边，变化左边的值*/
			if (target >= nums[left] && target <= nums[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else
		{
			/*如果中间值不大于左边的值，说明右边的数组是升序的，同样，如果target<=右边值并且target>=中间值，那么说明target一定在右边，那么变化左边的值，否则target一定在左边，变化右边的值*/
			if (target >= nums[mid] && target <= nums[right])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
	return -1;
}

/*主函数省略*/