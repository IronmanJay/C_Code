#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define MAXSIZE 20 /*�洢�ռ��ʼ������*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; /*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
typedef int ElemType; /*ElemType���͸���ʵ������������������Ϊint*/

typedef struct
{
	ElemType data[MAXSIZE]; /*����洢����Ԫ�أ����ֵΪMAXSIZE*/
	int length; /*���Ա�ǰ����*/
}SqList;

/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ��ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ*/
Status GetElem(SqList L, int i, ElemType *e) {
	if (L.length == 0 || i < 1 || i > L.length) {
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)*/
/*�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/
Status ListInsert(SqList *L, int i, ElemType e) {
	int k;
	if (L->length == MAXSIZE) { /*˳�����Ա��Ѿ���*/
		return ERROR;
	}
	if (i < 1 || i > L->length + 1) { /*��i���ڷ�Χ��ʱ*/
		return ERROR;
	}
	if (i <= L->length) { /*����������λ�ò��ڱ�β*/
		for (k = L->length - 1; k >= i - 1; k--) { /*��Ҫ����λ�ú�Ԫ������ƶ�һλ*/
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e; /*����Ԫ�ز���*/
	L->length++; /*���Ա�L���ȼ�1*/
	return OK;
}

/*������*/
int main(void) {

}