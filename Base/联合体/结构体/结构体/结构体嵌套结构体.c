#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct scores
{
	int cl;
	int cpp;
	int cs;
};

struct student
{
	char name[21];
	int age;
	struct scores ss;
	char addr[51];
};

int main06(void)
{
	//struct student stu = { "貂蝉",18,99,99,99,"徐州" };

	struct student stu;
	strcpy(stu.name, "小乔");
	stu.age = 20;
	stu.ss.cl = 88;
	stu.ss.cpp = 88;
	stu.ss.cs = 88;
	strcpy(stu.addr, "江东");

	printf("%s\n%d\n%d\n%d\n%d\n%s\n", stu.name, stu.age, stu.ss.cl, stu.ss.cpp, stu.ss.cs, stu.addr);

	getchar();
}