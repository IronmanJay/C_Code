#include<stdio.h>
#include<string.h>

int my_strcmp01(const char* s1, const char* s2)
{
	while (*s1 == *s2) 
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 > *s2 ? 1 : -1;
}

int my_strcmp02(const char* s1, const char* s2)
{
	while (*s1++ == *s2++ && !*s1);
	if (!*--s1 && !*--s2)return 0;
	return *s1 > *s2 ? 1 : -1;
}

int my_strncmp(const char *s1, const char *s2,size_t n)
{
	for (int i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return s1[i] > s2[i] ? 1 : -1;
		}
	}
	return 0;
}

int main11(void)
{
	char ch1[] = "hello world";
	char ch2[] = "hello world";

	//int value = strcmp(ch1, ch2);
	//int value = strncmp(ch1, ch2, 15);
	//int value = my_strcmp02(ch1, ch2, 5);
	int value = my_strncmp(ch1, ch2, 5);

	printf("%d\n", value);
	getchar();
}