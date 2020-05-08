#include<stdio.h>
#include<stdlib.h>

typedef struct student ss;

struct student
{
	char name[21];
	int age;
	char sex;
	int score[3];
	char addr[51];
};

int main05(void)
{
	ss * p = (ss *)malloc(sizeof(ss) * 3);

	for (int i = 0; i < 3; i++)
	{
		scanf_s("%s%d,%c%d%d%d%s", p[i].name, &p[i].age, &p[i].sex, &p[i].score[0], &p[i].score[1], &p[i].score[2], p[i].addr);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("性名：%s\n", p[i].name);
		printf("年龄：%d\n", p[i].age);
		printf("性别：%s\n", p[i].sex == 'M' ? "男" : "女");
		printf("成绩1：%d\n", p[i].score[0]);
		printf("成绩2：%d\n", p[i].score[1]);
		printf("成绩3：%d\n", p[i].score[2]);
		printf("地址：%s\n", p[i].addr);
	}

	free(p);

	getchar();
}