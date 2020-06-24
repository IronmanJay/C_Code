#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int findDuplicate(int* nums, int numsSize)
{
	/*����һ����ָ���һ����ָ�룬��ͬһ�����㣬��ָ��ÿ������������ָ��ÿ����һ��*/
	int fast = 0;
	int slow = 0;
	while (true)
	{
		fast = nums[nums[fast]];
		slow = nums[slow];
		/*������ڻ��Ļ�����ʱ����ָ�������*/
		if (fast == slow)
		{
			/*����֮����ָ��ص������㣬����������ָ������һ���ߣ��ٴ�����֮�����ǻ��ε����*/
			slow = 0;
			while (nums[slow] != nums[fast])
			{
				slow = nums[slow];
				fast = nums[fast];
			}
			return nums[slow];
		}
	}
}

/*������ʡ��*/
