#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main09(void)
{
	//�ļ�״̬�ṹ�����
	struct stat st;

	stat("D:/copy.exe", &st);

	printf("�ļ��Ĵ�С:%d\n", st.st_size);

	getchar();
}