#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main12(void)
{
	FILE* fp = fopen("D:/a.txt", "w+");
	if (!fp)
	{
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
		fflush(fp);
		fputc(ch, fp);
	}
	fclose(fp);

	getchar();
}