#include<stdio.h>
#include<stdlib.h>

int main05(void)
{
	//栈区大小
	int arr[10] = { 0 };

	//开辟堆空间存储数据
	int* p = (int*)malloc(sizeof(int));
	printf("%p\n", p);
	//使用堆空间
	*p = 123;
	p = NULL;
	printf("%d\n", *p);
	//释放堆空间
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