#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int balancedStringSplit(char * s)
{
	/*结果*/
	int res = 0;
	/*定义平衡因子，如果为零，说明当前平衡，res++，假设一开始是平衡的，所以为0*/
	int balance = 0;
	/*开始遍历*/
	for (int i = 0; i < strlen(s); i++)
	{
		/*遇到'L'，balance--*/
		if (s[i] == 'L')
		{
			balance--;
		}
		/*遇到'R'，balance++*/
		if (s[i] == 'R')
		{
			balance++;
		}
		/*如果到这里balance为0，说明遇到一个平衡子平衡字符串，结果+1*/
		if (balance == 0)
		{
			res++;
		}
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
