/*����2023���м�������ݽṹ��ϰָ��18ҳ�ж����ۺ�Ӧ����֮02��*/

/*ȥ������*/
#define _CRT_SECURE_NO_WARNINGS

/*����ͷ�ļ�*/
#include<stdio.h>

/*�궨��˳�����󳤶�Ϊ50*/
#define MaxSize 50

/*��������ElemTypeΪint����*/
typedef int ElemType;

/*��������˳���ṹ�壬���а���˳����˳���ĳ���*/
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

/*��������˳���ĺ������������Ϊ˳���ṹ�壬ֱ�Ӵ�ӡ���ú��˳����ʲ���Ҫ����ֵ*/
void Reverse(SqList L)
{
	ElemType temp; /*�����������ڽ�������ʱ��Ϊ�м����ʹ��*/
	for (int i = 0; i < L.length / 2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];/*����˳������˵�Ԫ��*/
		L.data[L.length - 1 - i] = temp;
	}
	/*��ӡ���ú��˳���*/
	printf("���ú��˳���Ϊ��");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	/*����*/
	printf("\n");
}

/*������*/
//int main()
//{
//	/*���ݳ�ʼ��*/
//	SqList L;
//	L.length = 0;
//	int len;
//	printf("������˳����ȣ�����Ӧ��50����");
//	scanf("%d", &len);
//	printf("������˳���Ԫ�أ�");
//	for (int i = 0; i < len; i++)
//	{
//		scanf("%d", &L.data[i]);
//		L.length++;
//	}
//	/*��ӡ��ʼ˳���*/
//	printf("��ʼ˳���Ϊ��");
//	for (int i = 0; i < L.length; i++)
//	{
//		printf("%d ", L.data[i]);
//	}
//	/*����*/
//	printf("\n");
//	/*����*/
//	Reverse(L);
//	/*��ͣ����*/
//	system("pause");
//	/*��������*/
//	return 0;
//}