#include<stdio.h>
#include<stdlib.h>

int main05(void)
{
	//ջ����С
	int arr[10] = { 0 };

	//���ٶѿռ�洢����
	int* p = (int*)malloc(sizeof(int));
	printf("%p\n", p);
	//ʹ�öѿռ�
	*p = 123;
	p = NULL;
	printf("%d\n", *p);
	//�ͷŶѿռ�
	free(p);
	printf("%p\n", p);
	*p = 456;
	printf("%d\n", *p);

	getchar();
}

int main06(void) {

	int* p = malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + 1));
	}
	free(p);

	getchar();
}