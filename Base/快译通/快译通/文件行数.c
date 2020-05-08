#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"dict.h"
#include<stdio.h>
#include<string.h>

int main01(void)
{
	FILE* fp = fopen("D:/d.txt", "r");
	if (!fp)
	{
		return -1;
	}
	char* temp = (char*)malloc(sizeof(char) * 1024);
	int i = 0;
	while (!feof(fp))
	{
		fgets(temp, 1024, fp);
		i++;
	}
	printf("%d\n", i);
	fclose(fp);
	getchar();
}