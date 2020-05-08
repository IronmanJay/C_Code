#include<stdio.h>
#include<string.h>

char* my_strchr(const char* s,int c) {
	while (*s) {
		if (*s == c) {
			return s;
		}
		s++;
	}
	return NULL;
}

int main14(void)
{
	char ch[] = "hello world";
	char c = 'l';
	//char* p = strchr(ch, c);
	char* p = my_strchr(ch, c);
	printf("%s\n", p);
	getchar();
}

int main15(void) {

	char ch[] = "hello world";
	char str[] = "llo";
	char* p = strstr(ch, str);
	printf("%s\n", p);
	getchar();
}