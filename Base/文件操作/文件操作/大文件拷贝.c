#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main08(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("缺少参数");
		return -1;
	}

	FILE* fp1 = fopen(argv[1], "rb");
	FILE* fp2 = fopen(argv[2], "wb");

	if (!fp2 || !fp2)
	{
		printf("复制文件出错");
		return -2;
	}

	char* temp = (char*)malloc(sizeof(char) * 1024);
	int count = 0;
	while (!feof(fp1))
	{
		memset(temp, 0, 1024);
		count = fread(temp, sizeof(char), 1024, fp1);
		fwrite(temp, sizeof(char), count, fp2);
	}

	free(temp);
	fclose(fp1);
	fclose(fp2);

	getchar();
}