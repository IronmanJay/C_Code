#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*得到每次的数*/
int getHappyNum(int n)
{
	/*存放每一次的值*/
	int res = 0;
	/*存放每一位的平方和*/
	int t;
	while (n != 0)
	{
		/*从个位开始向左位取每一位的平方和*/
		t = n % 10;
		res = res + t * t;
		/*从个位向左，遍历下一个位数的值*/
		n = n / 10;
	}
	/*返回这次的结果*/
	return res;
}

/*判断是否存在*/
bool exist(int* set, int n, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (set[i] == n)
		{
			return true;
		}
	}
	return false;
}

bool isHappy(int n)
{
	int len = 1;
	int set[100];
	/*首先将这个数字加入*/
	set[0] = n;
	n = getHappyNum(n);
	/*开始无限循环，当有结果时返回*/
	while (n != 1)
	{
		/*如果出现循环，返回False*/
		if (exist(set, n, len))
		{
			return false;
		}
		// 否则更新n的值继续循环
		else
		{
			set[len++] = n;
			/*更新n的值*/
			n = getHappyNum(n);
		}
	}
	/*如果n=1返回True*/
	return true;
}

int main(void)
{
	/*主函数省略*/
}
