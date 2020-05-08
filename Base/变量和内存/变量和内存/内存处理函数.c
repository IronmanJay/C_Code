#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main07(void)
{
	int* p = (int*)malloc(sizeof(int) * 10);

	memset(p, 1, 40);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}

	free(p);

	getchar();
}

int main08(void)
{
	char ch[10];

	memset(ch, 'A', sizeof(char)*10);

	printf("%s\n", ch);

	getchar();
}

int main09(void)
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };

	int* p = (int*)malloc(sizeof(int) * 9);

	memcpy(p, arr, sizeof(int) * 9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}
	free(p);

	getchar();
}