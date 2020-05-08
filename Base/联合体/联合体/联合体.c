#include<stdio.h>

union Var
{
	int a;
	float b;
	double c;
	char d;
	short f;
};

int main01(void)
{
	union Var var;
	var.a = 10;
	printf("%d\n", var.a);

	getchar();
}