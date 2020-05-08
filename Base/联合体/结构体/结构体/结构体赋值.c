#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char name[21];
	int age;
	int score;
	char addr[51];
};

int main07(void)
{
	struct student stu = { "ÀÔ…–œ„",26,60,"∞Õ Ò" };

	struct student s1 = stu;

	strcpy(s1.name, "∏ ∑Ú»À");

	printf("%s\n", stu.name);

	getchar();
}