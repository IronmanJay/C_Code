#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ṹ���ԱΪָ��
struct student
{
	char* name;
	int age;
	int* scores;
	char* addr;
};

int main08(void)
{
	struct student stu;
	//stu.name = "����";
	stu.name = (char*)malloc(sizeof(char) * 21);
	strcpy(stu.name, "����");
	stu.age = 18;
	stu.scores = (int*)malloc(sizeof(int) * 3);
	stu.addr = (char*)malloc(sizeof(char) * 51);
	stu.scores[0] = 88;
	stu.scores[1] = 99;
	stu.scores[2] = 100;
	strcpy(stu.addr, "����");

	printf("%s\n", stu.name);
	printf("%d\n", stu.age);
	printf("%d\n", stu.scores[1]);
	printf("%d\n", stu.scores[2]);
	printf("%d\n", stu.scores[3]);
	printf("%s\n", stu.addr);
	free(stu.name);
	free(stu.scores);
	free(stu.addr);
	getchar();
}

struct stu
{
	char name[21];
	int age;
	int scores[3];
	char addr[51];
};

//�ṹ��ָ��
int main09(void)
{
	struct stu ss = { "�ֳ�",30,30,100,100,"�꾩" };

	struct stu* ppp = &ss;

	//printf("%s\n", (*ppp).name);
	printf("%s\n", ppp->name);
	printf("%d\n", ppp->age);

	getchar();
}