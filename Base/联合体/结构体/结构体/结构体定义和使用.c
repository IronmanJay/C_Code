#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct student
{
	char name[21];
	int age;
	int score;
	char addr[51];
}stu = { "����",18,100,"����ʡ������" };

int main01(void)
{
	/*struct student stu;
	strcpy(stu.name,"����");
	stu.age = 18;
	stu.score = 100;
	strcpy(stu.addr, "����ʡ������");*/

	/*struct student stu = { "����",18,100,"����ʡ������" };*/

	printf("������%s\n", stu.name);
	printf("���䣺%d\n", stu.age);
	printf("�ɼ���%d\n", stu.score);
	printf("��ַ��%s\n", stu.addr);
	
	getchar();
}

int main02(void)
{
	struct student stu;

	scanf("%s%d%d%s", stu.name, &stu.age, &stu.score, stu.addr);

	printf("������%s\n", stu.name);
	printf("���䣺%d\n", stu.age);
	printf("�ɼ���%d\n", stu.score);
	printf("��ַ��%s\n", stu.addr);

	getchar();
}
