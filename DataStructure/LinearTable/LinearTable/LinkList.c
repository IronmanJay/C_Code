#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*�洢�ռ��ʼ������*/



typedef int Status; /*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
typedef int ElemType; /*ElemType���͸���ʵ������������������Ϊint*/


/*���Ա�ĵ�����洢�ṹ*/
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList; /*����LinkList*/

/*��ӡ�ַ�*/
Status Linkvisit(ElemType c)
{
	printf("%d", c);
	return OK;
}

/* ��ʼ��˳�����Ա� */
Status LinkInitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /*����ͷ��㣬��ʹLָ���ͷ���*/
	if (!(*L)) /*�洢����ʧ��*/
	{
		return ERROR;
	}
	(*L)->next = NULL; /*ָ����Ϊ��*/
	return OK;
}

/*��ʼ������˳�����Ա�L�Ѵ���*/
/*�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE*/
Status LinkListEmpty(LinkList L)
{
	if (L->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*��ʼ������˳�����Ա�L�Ѵ���*/
/*�������������L������Ԫ�ظ���*/
int LinkListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /*pָ���һ�����*/
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ*/
Status LinkGetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	p = L->next; /*��pָ������L�ĵ�һ�����*/
	j = 1; /*jΪ������*/
	while (p && j < i) /*p��Ϊ���Ҽ�����j��û�е���iʱ��ѭ������*/
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR; /*��i��Ԫ�ز�����*/
	}
	*e = p->data; /*ȡ��i��Ԫ�ص�����*/
	return OK;
}

/*��ʼ������˳�����Ա�L�Ѵ���*/
/*�������������L�е�1����e�����ϵ������Ԫ�ص�λ��,������������Ԫ�ز����ڣ��򷵻�ֵΪ0*/
int LinkLocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next; /*��pָ������L�ĵ�һ�����*/
	while (p)
	{
		i++;
		if (p->data == e) /*�ҵ�����������Ԫ��*/
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}

/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)*/
/*�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/
Status LinkListInsert(LinkList *L, int i, ElemType e)
{
	int j; /*jΪ������*/
	LinkList p, s; /*pΪtempָ�룬sΪ����������*/
	p = *L;
	j = 1;
	while (p && j < i) /*Ѱ�ҵ�i�����*/
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR; /*��i��Ԫ�ز�����*/
	}
	s = (LinkList)malloc(sizeof(Node)); /*�����½��(C��׼����)*/
	s->data = e;
	s->next = p->next; /*��p�ĺ�̽�㸳ֵ��s�ĺ��*/
	p->next = s; /*��s��ֵ��p�ĺ��*/
	return OK;
}

/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)*/
/*���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/
Status LinkListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i) /*����Ѱ�ҵ�i��Ԫ��*/
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
	{
		return ERROR; /*��i��Ԫ�ز�����*/
	}
	q = p->next;
	p->next = q->next; /*��q�ĺ�̸�ֵ��p�ĺ��*/
	*e = q->data; /*��q����е����ݸ�e*/
	free(q); /*��ϵͳ���մ˽�㣬�ͷ��ڴ�*/
	return OK;
}

/*��ʼ������˳�����Ա�L�Ѵ���*/
/*������������ζ�L��ÿ������Ԫ�����*/
Status LinkListTraverse(LinkList L)
{
	LinkList p = L->next; /*��pָ������L�ĵ�һ�����*/
	while (p)
	{
		Linkvisit(p->data); /*��ӡ��ǰָ����������Ԫ��*/
		p = p->next; /*��������ָ��*/
	}
	printf("\n");
	return OK;
}

/*�������n��Ԫ�ص�ֵ��������ͷ���ĵ��������Ա�L��ͷ�巨��*/
void LinkCreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0)); /*��ʼ�����������*/
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL; /*�Ƚ���һ����ͷ���ĵ�����*/
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*�����½��*/
		p->data = rand() % 100 + 1; /*�������100���ڵ�����*/
		p->next = (*L)->next;
		(*L)->next = p; /*���뵽�б�ͷ*/
	}
}

/*�������n��Ԫ�ص�ֵ��������ͷ���ĵ��������Ա�L��β�巨��*/
void LinkCreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0)); /*��ʼ�����������*/
	*L = (LinkList)malloc(sizeof(Node)); /*Ϊ�������Ա�*/
	r = *L; /*rΪָ��β���Ľ��*/
	for (i = 0; i < n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*�����½ڵ�*/
		p->data = rand() % 100 + 1; /*�������100���ڵ�����*/
		r->next = p; /*��β���ն˽���ָ��ָ���½��*/
		r = p; /*����ǰ���½�㶨��Ϊ��β�ն˽��*/
	}
	r->next = NULL; /*��ʾ��ǰ�������*/
}

/*��ʼ������˳�����Ա�L�Ѵ���*/
/*�����������L����Ϊ�ձ�*/
Status LinkClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next; /*����һ����㸳ֵ��p*/
	while (p) /*û����β*/
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL; /*ͷ���ָ����Ϊ��*/
	return OK;
}

/*���Ա���ʽ�洢*/
int mainLinkList(void)
{
	LinkList L;
	ElemType e;
	Status i;
	int j, k;

	/*��ʼ��������L*/
	i = LinkInitList(&L);
	printf("��ʼ��L��ListLength(L)=%d\n", LinkListLength(L));

	/*�ڵ�����L��ͷ����Ԫ��*/
	for (j = 1; j <= 5; j++)
	{
		i = LinkListInsert(&L, 1, j);
	}
	printf("��L�ı�ͷ���β���1��5��L.data=");
	LinkListTraverse(L);

	/*��ӡ������L���Ȳ��ж��Ƿ�Ϊ��*/
	printf("ListLength(L)=%d \n", LinkListLength(L));
	i = LinkListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1���� 0����)\n", i);

	/*��յ�����L��ӡ���Ȳ��ж��Ƿ�Ϊ��*/
	i = LinkClearList(&L);
	printf("���L��ListLength(L)=%d\n", LinkListLength(L));
	i = LinkListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	/*�ڵ�����L��β����Ԫ��*/
	for (j = 1; j <= 10; j++)
	{
		LinkListInsert(&L, j, j);
	}
	printf("��L�ı�β���β���1��10��L.data=");
	LinkListTraverse(L);

	/*��ӡ������L�ĳ���*/
	printf("ListLength(L)=%d \n", LinkListLength(L));

	/*�ڵ������ͷ����һ��Ԫ��*/
	LinkListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��L.data=");
	LinkListTraverse(L);
	printf("ListLength(L)=%d \n", LinkListLength(L));

	/*��ȡ������Lָ��λ�õ�Ԫ��*/
	LinkGetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LinkLocateElem(L, j);
		if (k)
		{
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		}
		else
		{
			printf("û��ֵΪ%d��Ԫ��\n", j);
		}
	}

	/*ɾ�����������е�Ԫ��*/
	k = LinkListLength(L); /*kΪ��*/
	for (j = k + 1; j >= k; j--)
	{
		i = LinkListDelete(&L, j, &e); /*ɾ����j������*/
		if (i == ERROR)
		{
			printf("ɾ����%d������ʧ��\n", j);
		}
		else
		{
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
		}
	}
	printf("�������L��Ԫ�أ�");
	LinkListTraverse(L);

	/*ɾ��������Lָ��λ�õ�Ԫ��*/
	j = 5;
	LinkListDelete(&L, j, &e); /*ɾ����5��Ԫ��*/
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
	printf("�������L��Ԫ�أ�");
	LinkListTraverse(L);

	/*��ձ�*/
	i = LinkClearList(&L);
	printf("���L��ListLength(L)=%d\n", LinkListLength(L));

	/*ͷ�巨���崴��L��Ԫ��*/
	LinkCreateListHead(&L, 20);
	printf("���崴��L��Ԫ��(ͷ�巨)��");
	LinkListTraverse(L);

	/*��ձ�*/
	i = LinkClearList(&L);
	printf("���L��ListLength(L)=%d\n", LinkListLength(L));

	/*β�巨���崴��L��Ԫ��*/
	LinkCreateListTail(&L, 20);
	printf("���崴��L��Ԫ��(β�巨)��");
	LinkListTraverse(L);

	getchar();

}