/*����2023���м�������ݽṹ��ϰָ��18ҳ�ж����ۺ�Ӧ����֮07��*/

/*ȥ������*/
#define _CRT_SECURE_NO_WARNINGS

/*����ͷ�ļ�*/
#include<stdio.h>
#include<stdbool.h>

/*�궨��˳�����󳤶�Ϊ50*/
#define MaxSize 50

/*��������ElemTypeΪint����*/
typedef int ElemType;

/*��������˳���ṹ�壬���а���˳����˳���ĳ���*/
typedef struct
{
	ElemType data[MaxSize];/*��̬���������ڴ�ռ�*/
	int length;
}SqList;

void Merge(SqList A, SqList B)
{
	if (A.length + B.length > MaxSize)/*����ϲ���ĳ��ȴ���˳�����󳤶ȣ���������ִ��*/
	{
		return 0;
	}
	SqList C;
	C.length = 0;
	int indexA = 0, indexB = 0, indexC = 0;/*�ֱ�Ϊ����˳��������*/
	while (indexA < A.length && indexB < B.length)/*ѭ����A��B���αȽϣ�ȡֵС�Ĵ���C��*/
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
	while (indexA < A.length)/*����û�бȽ����˳������C��*/
	{
		C.data[indexC++] = A.data[indexA++];
	}
	while (indexB < B.length)
	{
		C.data[indexC++] = B.data[indexB++];
	}
	C.length = indexC;
	/*��ӡ�ϲ����˳���*/
	printf("�ϲ����˳���Ϊ��");
	for (int i = 0; i < C.length; i++)
	{
		printf("%d ", C.data[i]);
	}
	/*����*/
	printf("\n");
}

/*������*/
int main()
{
	/*���ݳ�ʼ��*/
	SqList A,B;
	A.length = 0;
	B.length = 0;
	int lenA, lenB;
	printf("������˳���A�ĳ��ȣ�����Ӧ��25����");
	scanf("%d", &lenA);
	printf("������˳���B�ĳ��ȣ�����Ӧ��25����");
	scanf("%d", &lenB);
	printf("������˳���A��Ԫ�أ�");
	for (int i = 0; i < lenA; i++)
	{
		scanf("%d", &A.data[i]);
		A.length++;
	}
	printf("������˳���B��Ԫ�أ�");
	for (int i = 0; i < lenB; i++)
	{
		scanf("%d", &B.data[i]);
		B.length++;
	}
	/*��ӡ��ʼ˳���*/
	printf("��ʼ˳���AΪ��");
	for (int i = 0; i < A.length; i++)
	{
		printf("%d ", A.data[i]);
	}
	/*����*/
	printf("\n");
	printf("��ʼ˳���BΪ��");
	for (int i = 0; i < B.length; i++)
	{
		printf("%d ", B.data[i]);
	}
	/*����*/
	printf("\n");
	/*�ϲ�*/
	Merge(A, B);
	/*��ͣ����*/
	system("pause");
	/*��������*/
	return 0;
}