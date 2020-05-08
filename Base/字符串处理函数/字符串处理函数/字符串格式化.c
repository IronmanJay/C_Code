#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main12(void)
{
	char ch[100];

	sprintf(ch, "%d+%d=%d",1,2,3);

	printf("%s\n", ch);

	getchar();
}

int main13(void) {

	char ch[] = "1+2=3";
	int a, b, c;
	sscanf(ch, "%d+%d=%d", &a, &b, &c);
	printf("%s\n", a);
	printf("%s\n", b);
	printf("%s\n", c);
	getchar();
}