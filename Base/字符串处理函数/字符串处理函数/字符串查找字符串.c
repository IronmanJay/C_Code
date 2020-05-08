#include<stdio.h>

char* my_strstr(char* src, char* dest)
{
	//遍历源字符串的指针
	char* fsrc = src;
	//记录每次字符串首地址
	char* rsrc = src;
	char* tdest = dest;
	while (*fsrc)
	{
		rsrc = fsrc;
		while (*fsrc == *tdest && *fsrc != '\0')
		{
			fsrc++;
			tdest++;
		}
		if (*tdest == '\0')
		{
			return rsrc;
		}
		//目标字符串更新到起始位置
		tdest = dest;
		fsrc = rsrc;
		fsrc++;
	}
	return NULL;
}

int main3(void)
{
	char src[] = "hello world";
	char dest[] = "llo";
	char* p = my_strstr(src, dest);
	printf("%s\n", p);

	getchar();
}