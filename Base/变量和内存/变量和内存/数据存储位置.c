#include<stdio.h>

//安全的产量，存储区域为数据区
const int abc = 123;
//未初始化全局变量
int a1;
//初始化全局变量
int b1 = 10;
//未初始化静态全局变量
static int c1;
//初始化静态全局变量
static int d1 = 10;

int main04(void)
{
	//局部变量
	int e1 = 10;
	//未初始化的静态局部变量
	static int f1;
	//初始化的静态局部变量
	static int h1 = 10;
	//字符串常量
	char* p = "hello world";
	//数组
	int arr[] = { 1,2,3,4 };
	//指针
	int* pp = arr;
	printf("%p\n", &a1);
	printf("%p\n", &b1);
	printf("%p\n", &c1);
	printf("%p\n", &d1);
	printf("%p\n", &e1);
	printf("%p\n", &f1);
	printf("%p\n", &h1);
	printf("%p\n", p);
	printf("%p\n", arr);
	printf("%p\n", pp);
	printf("%p\n", &pp);
	
	getchar();
}