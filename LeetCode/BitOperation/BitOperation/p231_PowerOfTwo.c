#include<stdio.h>
#include<stdbool.h>

bool isPowerOfTwo(int n)
{
	return n > 0 && (n & (n - 1)) == 0;
}

/*������ʡ��*/
int main()
{
	return 0;
}