#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct student
{
	char name[21];
	int age;
	char sex;
	int score[3];
	char addr[51];
};

int main03(void)
{
	struct student stu[3] = 
	{
		{"柏蕊",18,'F',100,99,6,"家"},
		{"赵越", 41, 'M',100,99,66, "家"},
		{"柏蕊",2,'F',100,99,66,"家"}
	};

	for (int i = 0; i < 3; i++)
	{
		printf("性名：%s\n", stu[i].name);
		printf("年龄：%d\n", stu[i].age);
		printf("性别：%s\n", stu[i].sex == 'M' ? "男" : "女");
		printf("成绩1：%d\n", stu[i].score[0]);
		printf("成绩2：%d\n", stu[i].score[1]);
		printf("成绩3：%d\n", stu[i].score[2]);
		printf("地址：%s\n", stu[i].addr);
	}

	getchar();
}

int main04(void)
{
	struct student stu[3] =
	{
		{"柏蕊",18,'F',100,99,6,"家"},
		{"赵越", 41, 'M',100,99,66, "家"},
		{"柏蕊",2,'F',100,99,66,"家"}
	};

	for (int i = 0; i < 3-1; i++)
	{
		for (int j = 0; j < 3-1-i; j++)
		{
			if (stu[j].age > stu[j + 1].age) 
			{
				struct student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("性名：%s\n", stu[i].name);
		printf("年龄：%d\n", stu[i].age);
		printf("性别：%s\n", stu[i].sex == 'M' ? "男" : "女");
		printf("成绩1：%d\n", stu[i].score[0]);
		printf("成绩2：%d\n", stu[i].score[1]);
		printf("成绩3：%d\n", stu[i].score[2]);
		printf("地址：%s\n", stu[i].addr);
	}

	getchar();
}