#include<stdio.h>

int my_strlen01(char* ch)
{
	int i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return i;

}

int my_strlen02(char* ch)
{
	char* temp = ch;
	while (*temp != '\0')
	{
		temp++;
	}
	return temp - ch;
}

int main9(void)
{
	char ch[] = "hello world";
	int len = my_strlen02(ch);
	printf("%d\n", len);
	getchar();
}