#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE1
#define FALSE 0
#define MAXSIZE 1000 /*�洢�ռ��ʼ�������������������󳤶���1000*/

typedef int Status; /*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
typedef char ElemType; /*ElemType���͸���ʵ��������������������Ϊchar*/

/*���Ա�ľ�̬����洢�ṹ*/
typedef struct
{
	ElemType data;
	int cur;  /*�α�(Cursor) ��Ϊ0ʱ��ʾ��ָ��*/
} Component, StaticLinkList[MAXSIZE];

/*��ӡԪ��*/
Status StaticLinkListvisit(ElemType c)
{
	printf("%c", c);
	return OK;
}

/*��ʼ��������̬����L�Ѵ���*/
/*�������������L������Ԫ�ظ���*/
int StaticLinkListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

/*��һά����space�и���������һ��������*/
/*space[0].curΪͷָ�룬"0"��ʾ��ָ��*/
Status StaticLinkInitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0; /*Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0*/
	return OK;
}

/*���±�Ϊk�Ŀ��н����յ���������*/
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur; /*�ѵ�һ��Ԫ��curֵ��ֵ��Ҫɾ���ķ���cur*/
	space[0].cur = k; /*��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur*/
}

/*�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0*/
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur; /*��ǰ�����һ��Ԫ�ص�cur���ֵ������Ҫ���صĵ�һ�����ÿ��е��±�*/
	if (space[0].cur)
	{
		space[0].cur = space[i].cur; /*����Ҫ�ó�һ��������ʹ���ˣ��������Ǿ͵ð�������һ����������������*/
	}
	return i;
}

/*��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e*/
Status StaticLinkListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;
	k = MAXSIZE - 1; /*ע��k���������һ��Ԫ�ص��±�*/
	if (i < 1 || i> StaticLinkListLength(L) + 1)
	{
		return ERROR;
	}
	j = Malloc_SLL(L); /*��ÿռ�������±�*/
	if (j)
	{
		L[j].data = e; /*�����ݸ�ֵ���˷�����data*/
		for (l = 1; l <= i - 1; l++) /*�ҵ���i��Ԫ��֮ǰ��λ��*/
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur; /*�ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur*/
		L[k].cur = j; /*����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰ��Ԫ��cur*/
		return OK;
	}
	return ERROR;
}

/*ɾ����L�е�i������Ԫ��e*/
Status StaticLinkListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i<1 || i>StaticLinkListLength(L))
	{
		return ERROR;
	}
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
	{
		k = L[k].cur;
	}
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return OK;
}

/*������̬����*/
Status StaticLinkListTraverse(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		StaticLinkListvisit(L[i].data);
		i = L[i].cur;
		j++;
	}
	return j;
	printf("\n");
	return OK;
}

/*��̬����*/
int mainStaticLinkList(void)
{
	/*��ʼ������*/
	StaticLinkList L;
	Status i;

	/*��ʼ�����Ա�*/
	i = StaticLinkInitList(L);
	printf("��ʼ��L��L.length=%d", StaticLinkListLength(L));

	/*����Ԫ��*/
	i = StaticLinkListInsert(L, 1, 'F');
	i = StaticLinkListInsert(L, 1, 'E');
	i = StaticLinkListInsert(L, 1, 'D');
	i = StaticLinkListInsert(L, 1, 'B');
	i = StaticLinkListInsert(L, 1, 'A');

	/*�������Ա�*/
	printf("\n��L�ı�ͷ���β���FEDBA��\nL.data=");
	StaticLinkListTraverse(L);

	/*��ָ��λ�ò���Ԫ��*/
	i = StaticLinkListInsert(L, 3, 'C');
	printf("\n��L�ġ�B���롰D��֮����롰C����\nL.data=");
	StaticLinkListTraverse(L);

	/*ɾ��ָ��λ�õ�Ԫ��*/
	i = StaticLinkListDelete(L, 1);
	printf("\n��L��ɾ����A����\nL.data=");
	StaticLinkListTraverse(L);

	getchar();

}
