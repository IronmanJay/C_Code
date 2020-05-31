#include<stdio.h>
#include<stdbool.h>

bool isPerfectSquare(int num)
{
	if (num < 2)
	{
		return true;
	}
	long left = 0;
	long right = num;
	long mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long square = mid * mid;
		if (square == num)
		{
			return true;
		}
		else if (square < num)
		{
			left = mid + 1;
		}
		else if (square > num)
		{
			right = mid - 1;
		}
	}
	return false;
}

/*主函数*/
int main(void)
{
	/*主函数内容省略*/
}