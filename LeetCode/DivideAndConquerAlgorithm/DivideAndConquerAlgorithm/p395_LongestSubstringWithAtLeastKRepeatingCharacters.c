#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*返回两个数中最大值*/
int MAX_p395_LongestSubstringWithAtLeastKRepeatingCharacters(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int longestSubstring(char * s, int k)
{
	/*获取字符串长度*/
	int len = strlen(s);
	/*边界值判断*/
	if (len == 0 || k > len)
	{
		return 0;
	}
	if (k < 2)
	{
		return len;
	}
	/*返回结果*/
	return getRes(s, k, 0, len - 1);
}

int getRes(char* s, int k, int left, int right)
{
	/*如果当前状态的字符串长度小于k，说明当前状态的字符串就算全是一个字母，也达不到k个重复，返回0，所以要时刻保证当前状态的子串长度是否>k，从而减少不必要的比较*/
	if (right - left + 1 < k)
	{
		return 0;
	}
	/*记录26个英文字母出现的次数*/
	int* count = (int*)calloc(26, sizeof(int));
	for (int i = left; i <= right; i++)
	{
		count[s[i] - 'a']++;
	}
	/*如果某个字母出现的次数小于k，不可能出现在结果字符串中，所以修改两个指针的位置，将不满足要求的字母排除*/
	while (right - left + 1 >= k && count[s[left] - 'a'] < k)
	{
		left++;
	}
	while (right - left + 1 >= k && count[s[right] - 'a'] < k)
	{
		right--;
	}
	/*再次判断，如果当前状态的字符串长度小于k，说明当前状态的字符串肯定不符合要求，返回0*/
	if (right - left + 1 < k)
	{
		return 0;
	}
	/*开始分治，如果当前的字符串中有出现次数小于k的字母，说明当前的字符串肯定不满足要求，那么划分字串同上递归处理，返回最大值*/
	for (int i = left; i <= right; i++)
	{
		if (count[s[i] - 'a'] < k)
		{
			return MAX_p395_LongestSubstringWithAtLeastKRepeatingCharacters(getRes(s, k, left, i - 1), getRes(s, k, i + 1, right));
		}
	}
	/*最终肯定是满足要求的子串，返回即可*/
	return right - left + 1;
}

/*主函数省略*/
