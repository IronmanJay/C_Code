#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student ss;

struct student
{
	//char name[21];
	char* name;
	int age;
	int score;
	char addr[51];
};

void func01(ss stu1)
{
	strcpy(stu1.name, "卢俊义");
	printf("%s\n", stu1.name);
}

int main10(void)
{
	ss stu1 = { NULL,50,101,"水泊梁山" };

	stu1.name = (char*)malloc(sizeof(char) * 21);
	strcpy(stu1.name, "宋江");

	func01(stu1);

	getchar();
}

void BubbleSort(ss* stu2, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if ((stu2 + j)->age > (stu2 + j + 1)->age)
			{
				ss temp = stu2[j];
				stu2[j] = stu2[j + 1];
				stu2[j + 1] = temp;
			}
		}
	}
}

int main11(void)
{
	ss stu2[3] =
	{
		{"鲁智深",30,25,"五台山"},
		{"林冲",23,25,"五台山"},
		{"鲁智深儿子",75,25,"五台山"},
	};

	BubbleSort(stu2,3);

	for (int i = 0; i < 3; i++)
	{
		printf("性名：%s\n", stu2[i].name);
		printf("年龄：%d\n", stu2[i].age);
		printf("成绩：%d\n", stu2[i].score);
		printf("地址：%s\n", stu2[i].addr);
	}

	getchar();
}