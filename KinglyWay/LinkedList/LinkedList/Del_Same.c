/*����2023���м�������ݽṹ��ϰָ��40ҳ�ж����ۺ�Ӧ����֮12��*/

/*ȥ������*/
#define _CRT_SECURE_NO_WARNINGS

/*����ͷ�ļ�*/
#include<stdio.h>
#include<stdlib.h>

/*����������ṹ�壬���а������ݺ�ָ����һ������ָ��*/
typedef struct LNode
{
	int data;
	struct LNode* next;/*�������ָ����һ������ָ�룬*��ʾ����һ��ָ�룬next�����ָ������֣�struct��ʾ���ָ��ָ��������Ǹ��ṹ��*/
}Node, *Link;/*������Ҫ˵��NodeΪ�ṹ������֣�Ҳ����typedef���ṹ��struct LNode������һ�����������������Node����*Link��ʾһ���ṹ��ָ�룬����������ʱ��Ҫʹ��malloc�����ڴ�ռ����ָ��ĳһ���Ѿ������Ľṹ�壻����һ���������ڴ�*����ṹ��ָ���ʱ��ȡ�ڲ�����Ԫ�ص�ʱ��Ҫ��->��������*��֪ʶһ����ͨ�Ľṹ�������ȡԪ�ص�ʱ��Ҫ��.*/

/*��ӡ������*/
void PrintLink_Del_Same(Link link)
{
	Node* p = link->next;
	while (p != NULL)
	{
		if (p->next != NULL)
		{
			printf("%d->", p->data);
		}
		else
		{
			printf("%d", p->data);
		}
		p = p->next;
	}
}

/*�˺����Ĺ���Ϊɾ������Ĵ�ͷ���ĵ������е��ظ�Ԫ��*/
void Del_Same(Link L)
{
	Link p = L->next;
	Node* temp = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		return;/*���������Ϊ�գ���������*/
	}
	while (p->next != NULL)
	{
		temp = p->next;/*tempָ��p�ĺ�̽��*/
		if (p->data == temp->data)/*�ҵ��ظ�ֵ�Ľ��*/
		{
			p->next = temp->next;/*�����ظ�ֵ��㣬�������ӵ�����*/
			free(temp);/*�ͷ�ֵ��ͬԪ�ؽ��*/
		}
		else
		{
			p = p->next;/*�����ظ�ֵ�Ľ���������Ѱ��*/
		}
	}
}

/*������*/
//int main()
//{
//	Link link = (Link)malloc(sizeof(Node));
//	link->next = NULL;
//	Node* p = link;
//	int len;
//	printf("�����뵥����ĳ��ȣ�");
//	scanf("%d", &len);/*���뵥������*/
//	printf("�����뵥�����Ԫ�أ�");
//	for (int i = 0; i < len; i++)/*ɨ�����ݽ���������*/
//	{
//		int x;
//		scanf("%d", &x);
//		Node* temp = (Node*)malloc(sizeof(Node));
//		temp->data = x;
//		temp->next = NULL;
//		p->next = temp;
//		p = temp;
//	}
//	printf("��ʼ������Ϊ��");
//	PrintLink_Del_Same(link);
//	printf("\n");
//	Del_Same(link);
//	printf("ɾ���ظ�Ԫ�غ�ĵ�����Ϊ��");
//	PrintLink_Del_Same(link);
//	printf("\n");
//	/*��ͣ����*/
//	system("pause");
//	/*��������*/
//	return 0;
//}