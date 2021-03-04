#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int numDistinct(char * s, char * t)
{
	/*求出s和t的长度*/
	int s_len = strlen(s);
	int t_len = strlen(t);
	/*创建对应的w二维数组，并开辟空间，这里要用long，要不输入z字符串太长会出错，这里+1的作用是考虑到t和s为0的情况*/
	long dp[0 + 1][0 + 1]; /*因为c语言不允许使用没定义的参数，所以这里写成固定的，正常应该是long dp[s_len + 1][t_len + 1];*/
	memset(dp, 0, sizeof(dp));
	/*将每一行的最后一位置为1，因为当t为空时，只能在s中选中一个，而当s为空时，一个也选不中，按理说应该把每列的最后一个置为 0，但是二维数组默认就是0，这里只需要修改每一行的最后一位*/
	for (int i = 0; i <= s_len; i++)
	{
		dp[i][t_len] = 1;
	}
	/*从这里开始，倒着进行循环，从t字符串的后面开始，t每次增加一个字母，因为是从s里面找t，所以t的循环在外面*/
	for (int t_i = t_len - 1; t_i >= 0; t_i--)
	{
		/*倒着进行循环，从s字符串的后面开始，s每次增加一个字母*/
		for (int s_i = s_len - 1; s_i >= 0; s_i--)
		{
			/*如果两个字母相等*/
			if (t[t_i] == s[s_i])
			{
				/*在相等的情况下，可以选择s中的字母，跳过s中的，也跳过t中的；也可以不选择s中的字母，跳过s中的，不跳过t中的*/
				dp[s_i][t_i] = dp[s_i + 1][t_i + 1] + dp[s_i + 1][t_i];
			}
			/*如果两个字母不相等*/
			else
			{
				/*不选择s中的字母，跳过s中的，不跳过t中的*/
				dp[s_i][t_i] = dp[s_i + 1][t_i];
			}
		}
	}
	/*因为是从后向前循环的，所以返回第一行第一列的值*/
	return dp[0][0];
}

/*主函数省略*/