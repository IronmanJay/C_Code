#include<stdio.h>

void inverse01(char* ch)
{
	int i = 0;
	int j = strlen(ch) - 1;
	while (i < j)
	{
		char temp = ch[i];
		ch[i] = ch[j];
		ch[j] = temp;
		i++;
		j--;
	}
	return;
}

void inverse02(char* ch)
{
	char* ftemp = ch;
	char* btemp = ch + strlen(ch) - 1;
	while (ftemp < btemp)
	{
		char temp = *ftemp;
		*ftemp = *btemp;
		*btemp = temp;
		ftemp++;
		btemp--;
	}
	return;
}

int main6(void)
{
	char ch[] = "hello world";
	inverse02(ch);
	printf("%s\n", ch);
	getchar();
}

//判断是否是回文字符串
int symm(char* ch)
{
	char* ftemp = ch;
	char* btemp = ch + strlen(ch) - 1;

	while (ftemp <= btemp)
	{
		if (*ftemp != *btemp)
		{
			return 1;
		}
		ftemp++;
		btemp--;
	}
	return 0;
}

int main7(void)
{
	char ch[] = "abcba";
	int value = symm(ch);
	if (!value)
	{
		printf("相同\n");
	}
	else
	{
		printf("不相同\n");
	}
	getchar();
}