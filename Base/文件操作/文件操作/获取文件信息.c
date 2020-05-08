#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main09(void)
{
	//文件状态结构体变量
	struct stat st;

	stat("D:/copy.exe", &st);

	printf("文件的大小:%d\n", st.st_size);

	getchar();
}