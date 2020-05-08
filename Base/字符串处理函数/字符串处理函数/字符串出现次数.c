#include<stdio.h>

char* my_strstrstr(char* src, char* dest)
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

int main4(void)
{
	char* str = "11abcd111122abcd333abcd3322abcd3333322qqq";

	char ch[] = "abcd";

	char* p = my_strstrstr(str, ch);
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p + strlen(ch);
		p = my_strstrstr(p, ch);
	}
	printf("%d\n", count);

	getchar();
}

int main31(void)
{
	char* str = "11abcd111122abcd333abcd3322abcd3333322qqq";
	char ch[] = "abcd";
	char* p = my_strstrstr(str, ch);
	int count = 0;
	do
	{
		if (p)
		{
			count++;
			p = p + strlen(ch);
			p = my_strstrstr(p, ch);
		}
	} while (p);

	printf("%d\n", count);

	getchar();
}