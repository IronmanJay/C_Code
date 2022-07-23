/*王道2023考研计算机数据结构复习指导18页中二、综合应用题之07题*/

/*去除警告*/
#define _CRT_SECURE_NO_WARNINGS

/*引入头文件*/
#include<stdio.h>
#include<stdbool.h>

/*宏定义顺序表最大长度为50*/
#define MaxSize 50

/*声明定义ElemType为int类型*/
typedef int ElemType;

/*声明定义顺序表结构体，其中包括顺序表和顺序表的长度*/
typedef struct
{
	ElemType data[MaxSize];/*静态分配数组内存空间*/
	int length;
}SqList;

void Merge(SqList A, SqList B)
{
	if (A.length + B.length > MaxSize)/*如果合并后的长度大于顺序表最大长度，则程序结束执行*/
	{
		return 0;
	}
	SqList C;
	C.length = 0;
	int indexA = 0, indexB = 0, indexC = 0;/*分别为三个顺序表的索引*/
	while (indexA < A.length && indexB < B.length)/*循环，A和B依次比较，取值小的存入C中*/
	{
		if (A.data[indexA] <= B.data[indexB])
		{
			C.data[indexC++] = A.data[indexA++];
		}
		else
		{
			C.data[indexC++] = B.data[indexB++];
		}
	}
	while (indexA < A.length)/*将还没有比较完的顺序表存入C中*/
	{
		C.data[indexC++] = A.data[indexA++];
	}
	while (indexB < B.length)
	{
		C.data[indexC++] = B.data[indexB++];
	}
	C.length = indexC;
	/*打印合并后的顺序表*/
	printf("合并后的顺序表为：");
	for (int i = 0; i < C.length; i++)
	{
		printf("%d ", C.data[i]);
	}
	/*换行*/
	printf("\n");
}

/*主函数*/
int main()
{
	/*数据初始化*/
	SqList A,B;
	A.length = 0;
	B.length = 0;
	int lenA, lenB;
	printf("请输入顺序表A的长度（长度应≤25）：");
	scanf("%d", &lenA);
	printf("请输入顺序表B的长度（长度应≤25）：");
	scanf("%d", &lenB);
	printf("请输入顺序表A的元素：");
	for (int i = 0; i < lenA; i++)
	{
		scanf("%d", &A.data[i]);
		A.length++;
	}
	printf("请输入顺序表B的元素：");
	for (int i = 0; i < lenB; i++)
	{
		scanf("%d", &B.data[i]);
		B.length++;
	}
	/*打印初始顺序表*/
	printf("初始顺序表A为：");
	for (int i = 0; i < A.length; i++)
	{
		printf("%d ", A.data[i]);
	}
	/*换行*/
	printf("\n");
	printf("初始顺序表B为：");
	for (int i = 0; i < B.length; i++)
	{
		printf("%d ", B.data[i]);
	}
	/*换行*/
	printf("\n");
	/*合并*/
	Merge(A, B);
	/*暂停程序*/
	system("pause");
	/*函数结束*/
	return 0;
}