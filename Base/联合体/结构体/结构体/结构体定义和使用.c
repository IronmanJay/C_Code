#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct student
{
	char name[21];
	int age;
	int score;
	char addr[51];
}stu = { "张三",18,100,"辽宁省朝阳市" };

int main01(void)
{
	/*struct student stu;
	strcpy(stu.name,"张三");
	stu.age = 18;
	stu.score = 100;
	strcpy(stu.addr, "辽宁省朝阳市");*/

	/*struct student stu = { "张三",18,100,"辽宁省朝阳市" };*/

	printf("性名：%s\n", stu.name);
	printf("年龄：%d\n", stu.age);
	printf("成绩：%d\n", stu.score);
	printf("地址：%s\n", stu.addr);
	
	getchar();
}

int main02(void)
{
	struct student stu;

	scanf("%s%d%d%s", stu.name, &stu.age, &stu.score, stu.addr);

	printf("性名：%s\n", stu.name);
	printf("年龄：%d\n", stu.age);
	printf("成绩：%d\n", stu.score);
	printf("地址：%s\n", stu.addr);

	getchar();
}
