/*����2023���м�������ݽṹ��ϰָ��40ҳ�ж����ۺ�Ӧ����֮08��*/

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

/*������ĳ���*/
int Length(Link link)
{
	int len = 0;
	Node* p = link->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

/*�������Ĺ���Ϊ�ҵ�������ͷ���ĵ�����ĵ�һ���������*/
Link Search_Link_Common(Link L1, Link L2)
{
	int len1 = Length(L1);/*������������ĳ���*/
	int len2 = Length(L2);
	int dist;/*���������������ȵĲ�ֵ*/
	Link shortLink, longLink;/*�ֱ�ָ����ϳ��ͽ϶̵ĵ�����*/
	if (len1 > len2)/*����Ƚϳ���*/
	{
		shortLink = L2->next;
		longLink = L1->next;
		dist = len1 - len2;
	}
	else
	{
		shortLink = L1->next;
		longLink = L2->next;
		dist = len2 - len1;
	}
	while (dist--)/*ע�⣺0Ϊ�٣���0Ϊ��*/
	{
		longLink = longLink->next;/*���ĵ��������̵ĵ�������г��ȵ�ͬ��*/
	}
	while (longLink != NULL)/*ͬ��Ѱ�ҹ�����㣬ʹ���ĸ�ָ�붼���ԣ���Ϊ�Ѿ�ͬ����*/
	{
		if (shortLink == longLink)/*�ҵ���һ���������*/
		{
			return longLink;
		}
		else/*����ͬ��Ѱ��*/
		{
			longLink = longLink->next;
			shortLink = shortLink->next;
		}
	}
	/*����Ҳ�����һ��������㣬���ؿ�ֵ*/
	return NULL;
}

/*������*/
//int main()
//{
//	/*��ʼ����һ��������*/
//	Link link1 = (Link)malloc(sizeof(Node));
//	link1->next = NULL;
//	Node* p1 = link1;
//	
//	int len1;
//	printf("�����뵥����L1�ĳ��ȣ�");
//	scanf("%d", &len1);/*���뵥������*/
//	printf("�����뵥����L1��Ԫ�أ�");
//	for (int i = 0; i < len1; i++)/*ɨ�����ݽ���������*/
//	{
//		int x;
//		scanf("%d", &x);
//		Node* temp = (Node*)malloc(sizeof(Node));
//		temp->data = x;
//		temp->next = NULL;
//		p1->next = temp;
//		p1 = temp;
//	}
//	p1 = link1;/*����趨ĳ�����Ϊ������㣬׼����link2������*/
//	for (int i = 0; i < 3; i++)
//	{
//		p1 = p1->next;
//	}
//	/*��ʼ���ڶ���������*/
//	Link link2 = (Link)malloc(sizeof(Node));
//	link2->next = NULL;
//	Node* p2 = link2;
//	int len2;
//	printf("�����뵥����L2�ĳ��ȣ�ֻ��Ҫ�����һ���������ǰ��ĳ��ȼ��ɣ���");
//	scanf("%d", &len2);/*���뵥������*/
//	printf("�����뵥����L2��Ԫ�أ�ֻ��Ҫ�����һ���������ǰ���Ԫ�ؼ��ɣ���");
//	for (int i = 0; i < len2; i++)
//	{
//		int x;
//		scanf("%d", &x);
//		Node* temp = (Node*)malloc(sizeof(Node));
//		temp->data = x;
//		temp->next = NULL;
//		p2->next = temp;
//		p2 = temp;
//	}
//	p2->next = p1;/*���ӹ������*/
//	Link res = Search_Link_Common(link1, link2);
//	printf("��һ���������Ϊ��%d",res->data);
//	printf("\n");
//	/*��ͣ����*/
//	system("pause");
//	/*��������*/
//	return 0;
//}