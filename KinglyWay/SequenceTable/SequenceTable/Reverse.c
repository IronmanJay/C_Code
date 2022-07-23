/*王道2023考研计算机数据结构复习指导18页中二、综合应用题之02题*/

/*去除警告*/
#define _CRT_SECURE_NO_WARNINGS

/*引入头文件*/
#include<stdio.h>

/*宏定义顺序表最大长度为50*/
#define MaxSize 50

/*声明定义ElemType为int类型*/
typedef int ElemType;

/*声明定义顺序表结构体，其中包括顺序表和顺序表的长度*/
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

/*定义逆置顺序表的函数，传入参数为顺序表结构体，直接打印逆置后的顺序表，故不需要返回值*/
void Reverse(SqList L)
{
	ElemType temp; /*辅助变量，在交换数据时作为中间变量使用*/
	for (int i = 0; i < L.length / 2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];/*交换顺序表两端的元素*/
		L.data[L.length - 1 - i] = temp;
	}
	/*打印逆置后的顺序表*/
	printf("逆置后的顺序表为：");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	/*换行*/
	printf("\n");
}

/*主函数*/
//int main()
//{
//	/*数据初始化*/
//	SqList L;
//	L.length = 0;
//	int len;
//	printf("请输入顺序表长度（长度应≤50）：");
//	scanf("%d", &len);
//	printf("请输入顺序表元素：");
//	for (int i = 0; i < len; i++)
//	{
//		scanf("%d", &L.data[i]);
//		L.length++;
//	}
//	/*打印初始顺序表*/
//	printf("初始顺序表为：");
//	for (int i = 0; i < L.length; i++)
//	{
//		printf("%d ", L.data[i]);
//	}
//	/*换行*/
//	printf("\n");
//	/*逆置*/
//	Reverse(L);
//	/*暂停程序*/
//	system("pause");
//	/*函数结束*/
//	return 0;
//}