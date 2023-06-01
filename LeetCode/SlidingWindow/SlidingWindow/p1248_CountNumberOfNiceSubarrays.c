#include<stdio.h>

int numberOfSubarrays(int* nums, int numsSize, int k)
{
	int len = numsSize;
	int* index = (int*)malloc(sizeof(int) * (len + 2));
	int odd_count = 0;
	int res = 0;
	for (int i = 0; i < len; i++) {
		if ((nums[i] & 1) == 1) {
			index[++odd_count] = i;
		}
	}
	index[0] = -1;
	index[odd_count + 1] = len;
	for (int i = 1; i + k < odd_count + 2; i++) {
		res += (index[i] - index[i - 1]) * (index[i + k] - index[i + k - 1]);
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/