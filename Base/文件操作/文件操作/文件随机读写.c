#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main09(void)
{
	FILE* fp = fopen("D:/a.txt", "r");

	if (!fp)
	{
		return -1;
	}

	char ch1[] = "hello ¹þ¹þ¹þ\n";
	char ch2[] = "world\n";

	fputs(ch1, fp);
	fseek(fp, -14, SEEK_CUR);
	fputs(ch2, fp);
	fclose(fp);

	getchar();
}