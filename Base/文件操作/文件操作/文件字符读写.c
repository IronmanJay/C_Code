#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main02(void)
{
	FILE* fp = fopen("D:/a.txt", "r");
	if (!fp)
	{
		printf("文件打开失败");
		return -1;
	}
	char ch;
	ch = fgetc(fp);
	printf("%c\n", ch);
	fclose(fp);
	getchar();
}

int main03(void)
{
	FILE* fp = fopen("D:/a.txt", "r");
	if (!fp)
	{
		return -1;
	}
	char ch;
	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
	}
	fclose(fp);
	getchar();
}

int main04(void)
{
	FILE* fp = fopen("D:/a.txt", "w");
	if (!fp)
	{
		return -1;
	}
	char ch = "a";
	fputc(ch, fp);
	fclose(fp);
	getchar();
}

int main05(void)
{
	FILE* fp = fopen("D:/a.c", "w");
	if (!fp)
	{
		printf("文件打开失败");
		return -1;
	}
	char ch;
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '@')
		{
			break;
		}
		fputc(ch, fp);
	}
	fclose(fp);
	getchar();
}