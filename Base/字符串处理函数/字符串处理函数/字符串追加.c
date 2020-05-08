#include<stdio.h>

void my_strcat(char* dest, const char* src) {
	while (*dest)dest++;
	while (*dest++ = *src++);
}

void my_strncat(char* dest, char* src, size_t n) {
	while (*dest)dest++;
	while ((*dest++ = *src++) && --n);
}

int main10(void) {

	char dest[100] = "hello";

	char src[] = "world";

	//strcat(dest, src);
	//my_strcat(dest, src);
	//strncat(dest, src, 3);
	my_strncat(dest, src, 3);

	printf("%s", dest);

	getchar();
}