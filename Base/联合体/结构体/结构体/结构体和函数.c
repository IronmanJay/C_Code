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
	strcpy(stu1.name, "¬����");
	printf("%s\n", stu1.name);
}

int main10(void)
{
	ss stu1 = { NULL,50,101,"ˮ����ɽ" };

	stu1.name = (char*)malloc(sizeof(char) * 21);
	strcpy(stu1.name, "�ν�");

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
		{"³����",30,25,"��̨ɽ"},
		{"�ֳ�",23,25,"��̨ɽ"},
		{"³�������",75,25,"��̨ɽ"},
	};

	BubbleSort(stu2,3);

	for (int i = 0; i < 3; i++)
	{
		printf("������%s\n", stu2[i].name);
		printf("���䣺%d\n", stu2[i].age);
		printf("�ɼ���%d\n", stu2[i].score);
		printf("��ַ��%s\n", stu2[i].addr);
	}

	getchar();
}