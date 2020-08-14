#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char * s) {
	/*判空返回*/
	if (s == NULL || strlen(s) == 0)
	{
		return true;
	}
	/*定义左右指针*/
	int left = 0;
	int right = strlen(s) - 1;
	/*开始遍历*/
	while (left <= right)
	{
		/*如果在范围内且不是数字或者字母，跳过这个元素，左指针+1*/
		while (left <= right && !isalnum(s[left]))
		{
			left++;
		}
		/*如果在范围内且不是数字或者字母，跳过这个元素，右指针-1*/
		while (left <= right && !isalnum(s[right]))
		{
			right--;
		}
		/*如果在范围内且两字母不相等，返回false*/
		if (left <= right && tolower(s[left]) != tolower(s[right]))
		{
			return false;
		}
		/*如果相等，左指针+1，右指针-1，继续遍历*/
		left++;
		right--;
	}
	/*说明是回文串，返回true*/
	return true;
}

/*主函数省略*/
