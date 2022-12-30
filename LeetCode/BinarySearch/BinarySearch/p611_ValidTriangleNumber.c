int compare(int *a, int *b)
{
	return *a - *b;
}

int triangleNumber(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), compare);
	int len = numsSize;
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			int left = j + 1;
			int right = len - 1;
			int k = j;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] >= nums[i] + nums[j])
				{
					right = mid - 1;
				}
				else
				{
					k = mid;
					left = mid + 1;
				}
			}
			res += k - j;
		}
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/