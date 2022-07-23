/*王道2023考研计算机数据结构复习指导18页中二、综合应用题之06题*/

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
	ElemType data[MaxSize];
	int length;
}SqList;

/*定义在有序表中删除重复元素的函数，传入参数为顺序表结构体，直接打印删除重复元素后的顺序表，故不需要返回值*/
void Delete_Same(SqList L)
{
	if (L.length == 0)/*若顺序表长度为0，直接结束程序*/
	{
		return 0;
	}
	int index = 0, cur = 1;/*index为不相同元素的索引，cur为工作索引*/
	while (cur < L.length)
	{
		if (L.data[index] != L.data[cur])/*查找下一个与上一个元素值不同的元素*/
		{
			index++;
			L.data[index] = L.data[cur];/*找到后，将元素前移*/
		}
		cur++;
	}
	L.length = index + 1;
	/*打印删除重复元素后的的顺序表*/
	printf("删除重复元素后的顺序表为：");
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
//	/*删除重复元素*/
//	Delete_Same(L);
//	/*暂停程序*/
//	system("pause");
//	/*函数结束*/
//	return 0;
//}