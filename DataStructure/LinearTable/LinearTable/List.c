#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define MAXSIZE 20 /*存储空间初始分配量*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; /*Status是函数的类型，其值是函数结果状态代码，如OK等*/
typedef int ElemType; /*ElemType类型根据实际情况而定，这里假设为int*/

typedef struct
{
	ElemType data[MAXSIZE]; /*数组存储数据元素，最大值为MAXSIZE*/
	int length; /*线性表当前长度*/
}SqList;

/*初始化顺序线性表*/
Status InitList(SqList *L) 
{
	L->length = 0;
	return OK;
}

/*打印元素*/
Status visit(ElemType c) 
{
	printf("%d", c);
	return OK;
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：若List为空表，则返回TRUE，否则返回FALSE*/
Status ListEmpty(SqList L) 
{
	if (L.length == 0) 
	{
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：将L重置为空表*/
Status ClearList(SqList *L) 
{
	L->length = 0;
	return OK;
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：返回L中数据元素个数*/
Status ListLength(SqList L)
{
	return L.length;
}

/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值，注意i是指位置，第1个位置的数组是从0开始*/
Status GetElem(SqList L, int i, ElemType *e) 
{
	if (L.length == 0 || i < 1 || i > L.length) 
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：返回L中第一个与e满足关系的数据元素的位序，若这样的数据元素不存在，则返回值为0*/
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
	{
		return 0;
	}
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			break;
		}
	}
	if (i >= L.length)
	{
		return 0;
	}
	return i + 1;
}

/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(SqList *L, int i, ElemType e) {
	int k;
	if (L->length == MAXSIZE) /*顺序线性表已经满*/
	{
		return ERROR;
	}
	if (i < 1 || i > L->length + 1)  /*当i不在范围内时*/
	{
		return ERROR;
	}
	if (i <= L->length) /*若插入数据位置不在表尾*/
	{
		for (k = L->length - 1; k >= i - 1; k--) /*将要插入位置后元素向后移动一位*/
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e; /*将新元素插入*/
	L->length++; /*线性表L长度加1*/
	return OK;
}

/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0) /*线性表为空*/
	{
		return ERROR;
	}
	if (i<1 || i>L->length) /*删除位置不正确*/
	{
		return ERROR;
	}
	*e = L->data[i - 1];
	if (i < L->length) /*如果删除不是最后位置*/
	{
		for (int k = i; k < L->length; k++) /*将删除位置后继元素前移*/
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

/*初始条件：顺序线性表L已存在*/
/*操作结果：依次对L的每个数据元素输出*/
Status ListTraverse(SqList L) 
{
	int i;
	for (i = 0; i < L.length; i++) 
	{
		visit(L.data[i]);
	}
	printf("\n");
	return OK;
}

/*初始条件：顺序线性表La和Lb已存在*/
/*操作结果：合并顺序线性表La和Lb*/
void unionL(SqList *La, SqList Lb)
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
		{
			ListInsert(La, ++La_len, e);
		}
	}
}

/*主函数*/
int main(void) 
{
	/*初始化两个线性顺序表*/
	SqList L;
	SqList Lb;

	/*定义初始化状态和临时数字和标识位等*/
	ElemType e;
	Status i;
	int j, k;

	/*初始化线性顺序表L*/
	i = InitList(&L);
	printf("初始化L后：L.length=%d\n", L.length);

	/*给线性顺序表L赋值*/
	for (j = 1; j <= 5; j++)
	{
		i = ListInsert(&L, 1, j);
	}
	printf("在L的表头依次插入1~5后：L.data=");
	ListTraverse(L);

	/*打印顺序线性表L的长度并判断L是否为空*/
	printf("L.length=%d \n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1：是 0：否)\n", i);

	/*清空顺序线性表L并判断清空之后的L是否为空*/
	i = ClearList(&L);
	printf("清空L后，L.length=%d\n", L.length);
	i = ListEmpty(L);
	printf("L是否空：i=%d(1：是 0：否)\n", i);

	/*给顺序线性表L重新赋值*/
	for (j = 1; j <= 10; j++)
	{
		i = ListInsert(&L, j, j);
	}
	printf("在L的表头依次插入1~10后：L.data=");
	ListTraverse(L);

	/*打印顺序线性表L的长度*/
	printf("L.length=%d \n", L.length);

	/*在顺序线性表L的表头插入元素*/
	ListInsert(&L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L);
	printf("L.length=%d \n", L.length);

	/*在顺序线性表L中取得对应位置的元素*/
	GetElem(L, 5, &e);
	printf("第5个元素的值为：%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
		{
			printf("第%d个元素的值为%d\n", k, j);
		}
		else
		{
			printf("没有值为%d的元素\n", j);
		}
	}

	/*在顺序线性表L中删除对应位置的元素*/
	k = ListLength(L); /*k为表长*/
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); /*删除第j个数据*/
		if (i == ERROR)
		{
			printf("删除第%d个数据失败\n", j);
		}
		else
		{
			printf("删除第%d个的元素值为：%d\n", j, e);
		}
	}
	printf("依次输出L的元素：");
	ListTraverse(L);
	j = 5;
	ListDelete(&L, j, &e); /*删除第5个元素*/
	printf("删除第%d个的元素值为：%d\n", j, e);
	printf("依次输出L的元素：");
	ListTraverse(L);

	/*合并顺序线性表L和Lb*/
	i = InitList(&Lb); /*构造一个有10个数的Lb*/
	for (j = 6; j <= 15; j++)
	{
		i = ListInsert(&Lb, 1, j);
	}
	printf("依次输出Lb的元素：");
	ListTraverse(Lb);
	unionL(&L, Lb);
	printf("依次输出合并了Lb的L的元素：");
	ListTraverse(L);

	getchar();

}