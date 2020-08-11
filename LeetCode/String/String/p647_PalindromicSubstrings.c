#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*定义结果的全局变量*/
int res;

void count(char * s, int left, int right)
{
	/*当left和right不越界的时候，从中心点向两边拓展，遇到相等的说明有回文子串*/
	while (left >= 0 && right < strlen(s) && s[left] == s[right])
	{
		res++;
		left--;
		right++;
	}
}

int countSubstrings(char * s)
{
	/*别忘了把结果的全局变量初始化一下*/
	res = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		/*当选取的中心点为奇数个，也就是一个字符*/
		count(s, i, i);
		/*当选取的中心点为偶数个，也就是两个字符*/
		count(s, i, i + 1);
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
