#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main01(void)
{
	FILE* fp = fopen("D:/a.txt","r");
	if (fp = NULL)
	{
		printf("���ļ�ʧ��");
		return -1;
	}
	printf("�ļ��򿪳ɹ�\n");
	fclose(fp);
	getchar();
}