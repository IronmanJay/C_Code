#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main06(void)
{
	FILE* fp = fopen("D:/a.txt","r");
	FILE* fp2 = fopen("D:/b.txt", "w");
	char ch;
	while ((ch = fgetc(fp)) != EOF)
	{
		ch++;
		fputc(ch, fp2);
	}
	fclose(fp);
	fclose(fp2);
	getchar();
}

int main07(void)
{
	FILE* fp1 = fopen("D:/b.txt", "r");
	FILE* fp2 = fopen("D:/c.txt", "w");
	if (!fp1 || !fp2)
	{
		return -1;
	}
	char ch;
	while ((ch = fgetc(fp1)) != EOF)
	{
		ch--;
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	getchar();
}