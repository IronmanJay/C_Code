#include<stdio.h>

/*递归版本*/
int Fbi(int i)
{
	if (i < 2)
	{
		return i == 0 ? 0 : 1;
	}
	return Fbi(i - 1) + Fbi(i - 2); /*这里Fbi就是函数自己，它在调用自己*/
}

/*斐波那契函数*/
int mainFib(void)
{
	/*非递归版本（迭代）*/
	int i;
	int a[40];
	printf("迭代显示斐波那契数列：\n");
	a[0] = 0;
	a[1] = 1;
	printf("%d ", a[0]);
	printf("%d ", a[1]);
	for (int i = 2; i < 40; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("递归显示斐波那契数列：\n");
	for (int i = 0; i < 40; i++)
	{
		printf("%d ", Fbi(i));
	}

	getchar();
}