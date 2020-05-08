#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void my_strcpy(char* dest, char* src) {
	while (*dest++ = *src++);
}

void my_strncpy(char* dest, char* src, size_t n) {
	while ((*dest++ = *src++) && n--);
}

void my_strncpy001(char* dest, char* src, size_t n) {
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
}

void my_strncpy002(char* dest, char* src, size_t n) {
	int i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
}


int main5(void)
{
	char ch[] = "hello world";

	char str[100] = { 0 };

	//strcpy(str, ch);
	//my_strcpy(str, ch);
	//strncpy(str, ch, 5);
	my_strncpy002(str, ch, 7);

	printf("%s\n", str);

	getchar();
}