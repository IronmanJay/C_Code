/*����2023���м�������ݽṹ��ϰָ��18ҳ�ж����ۺ�Ӧ����֮06��*/

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
	ElemType data[MaxSize];
	int length;
}SqList;

/*�������������ɾ���ظ�Ԫ�صĺ������������Ϊ˳���ṹ�壬ֱ�Ӵ�ӡɾ���ظ�Ԫ�غ��˳����ʲ���Ҫ����ֵ*/
void Delete_Same(SqList L)
{
	if (L.length == 0)/*��˳�����Ϊ0��ֱ�ӽ�������*/
	{
		return 0;
	}
	int index = 0, cur = 1;/*indexΪ����ͬԪ�ص�������curΪ��������*/
	while (cur < L.length)
	{
		if (L.data[index] != L.data[cur])/*������һ������һ��Ԫ��ֵ��ͬ��Ԫ��*/
		{
			index++;
			L.data[index] = L.data[cur];/*�ҵ��󣬽�Ԫ��ǰ��*/
		}
		cur++;
	}
	L.length = index + 1;
	/*��ӡɾ���ظ�Ԫ�غ�ĵ�˳���*/
	printf("ɾ���ظ�Ԫ�غ��˳���Ϊ��");
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
//	/*ɾ���ظ�Ԫ��*/
//	Delete_Same(L);
//	/*��ͣ����*/
//	system("pause");
//	/*��������*/
//	return 0;
//}