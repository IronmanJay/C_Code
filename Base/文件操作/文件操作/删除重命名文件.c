#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main10(void)
{
	int value = remove("D:/d.txt");
	if (value==0)
	{
		printf("ɾ���ɹ�\n");
	}
	else {
		printf("ɾ��ʧ��\n");
	}

	getchar();
}

int main11(void)
{
	int value = rename("D:/a.txt", "D:/ABC.txt");
	if (value == 0)
	{
		printf("�������ɹ�\n");
	}
	else {
		printf("������ʧ��\n");
	}
	getchar();
}