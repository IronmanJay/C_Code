#include<stdio.h>

int wiggleMaxLength(int* nums, int numsSize)
{
	if (numsSize < 2)
	{
		return numsSize;
	}
	int preDiff = nums[1] - nums[0];
	int res = preDiff != 0 ? 2 : 1;
	for (int i = 2; i < numsSize; i++)
	{
		int diff = nums[i] - nums[i - 1];
		if ((preDiff >= 0 && diff < 0) || (preDiff <= 0 && diff > 0))
		{
			res++;
			preDiff = diff;
		}
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/