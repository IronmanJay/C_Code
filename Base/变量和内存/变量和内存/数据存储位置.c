#include<stdio.h>

//��ȫ�Ĳ������洢����Ϊ������
const int abc = 123;
//δ��ʼ��ȫ�ֱ���
int a1;
//��ʼ��ȫ�ֱ���
int b1 = 10;
//δ��ʼ����̬ȫ�ֱ���
static int c1;
//��ʼ����̬ȫ�ֱ���
static int d1 = 10;

int main04(void)
{
	//�ֲ�����
	int e1 = 10;
	//δ��ʼ���ľ�̬�ֲ�����
	static int f1;
	//��ʼ���ľ�̬�ֲ�����
	static int h1 = 10;
	//�ַ�������
	char* p = "hello world";
	//����
	int arr[] = { 1,2,3,4 };
	//ָ��
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