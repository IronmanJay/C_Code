#include<stdio.h>

int main16(void) {

	char ch[] = "123456@qq.com";
	char str[100] = { 0 };
	strcpy(str, ch);
	char* p = strtok(str, "@");
	printf("%s\n", p);
	p = strtok(NULL, ".");
	printf("%s\n", p);
	getchar();
}