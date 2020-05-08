#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main01(void)
{
	FILE* fp = fopen("D:/a.txt","r");
	if (fp = NULL)
	{
		printf("打开文件失败");
		return -1;
	}
	printf("文件打开成功\n");
	fclose(fp);
	getchar();
}