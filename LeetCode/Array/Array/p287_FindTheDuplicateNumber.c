#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int findDuplicate(int* nums, int numsSize)
{
	/*声明一个快指针和一个慢指针，从同一出发点，快指针每次走两步，慢指针每次走一步*/
	int fast = 0;
	int slow = 0;
	while (true)
	{
		fast = nums[nums[fast]];
		slow = nums[slow];
		/*如果存在环的话，此时快慢指针会相遇*/
		if (fast == slow)
		{
			/*相遇之后，慢指针回到出发点，接下来快慢指针两个一起走，再次相遇之处就是环形的入口*/
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

/*主函数省略*/
