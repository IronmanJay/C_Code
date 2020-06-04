#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��*/
typedef char TElemType;
typedef enum
{
	Link,
	Thread
}PointerTag; /*Link==0��ʾָ�����Һ���ָ�룬Thread==1��ʾָ��ǰ�����̵�����*/

/*���������洢���ṹ*/
typedef struct BiThrNode
{
	TElemType data; /*�������*/
	struct BiThrNode *lchild, *rchild; /*���Һ���ָ��*/
	PointerTag LTag;
	PointerTag RTag; /*���ұ�־*/
}BiThrNode,*BiThrTree;

TElemType ThrNil = '#'; /*��#Ϊ��*/

/*��ӡ���ݽṹ*/
Status Thrvisit(TElemType e)
{
	printf("%c ", e);
	return OK;
}

/*��ǰ����������������н���ֵ,�������������T*/
/*0(����)/�ո�(�ַ���)��ʾ�ս��*/
Status CreateBiThrTree(BiThrTree *T)
{
	TElemType h;
	scanf_s("%c", &h);
	if (h == ThrNil)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!*T)
		{
			exit(OVERFLOW);
		}
		(*T)->data = h; /*���ɸ��ڵ㣨ǰ��*/
		CreateBiThrTree(&(*T)->lchild); /*�ݹ鹹��������*/
		if ((*T)->lchild) /*������*/
		{
			(*T)->LTag = Link;
		}
		CreateBiThrTree(&(*T)->rchild); /*�ݹ鹹��������*/
		if ((*T)->rchild)
		{
			(*T)->RTag = Link;
		}
	}
	return OK;
}

BiThrTree pre; /*ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ��*/

/*���������������������*/
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild); /*�ݹ�������������*/
		if (!p->lchild) /*û������*/
		{
			p->LTag = Thread; /*ǰ������*/
			p->lchild = pre; /*����ָ��ָ��ǰ��*/
		}
		if (!pre->rchild) /*ǰ��û���Һ���*/
		{
			pre->RTag = Thread; /*�������*/
			pre->rchild = p; /*ǰ���Һ���ָ��ָ���̣���ǰ���p��*/
		}
		pre = p; /*����preָ��p��ǰ��*/
		InThreading(p->rchild); /*�ݹ�������������*/
	}
}

/*�������������T,����������������,Thrtָ��ͷ���*/
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if (!*Thrt)
	{
		exit(OVERFLOW);
	}
	(*Thrt)->LTag = Link; /*��ͷ���*/
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = (*Thrt); /*��ָ���ָ*/
	if (!T) /*����������,����ָ���ָ*/
	{
		(*Thrt)->lchild = *Thrt;
	}
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T); /*���������������������*/
		pre->rchild = *Thrt;
		pre->RTag = Thread; /*���һ�����������*/
		(*Thrt)->rchild = pre;
	}
	return OK;
}

/*�����������������T(ͷ���)�ķǵݹ��㷨*/
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild; /*pָ����ڵ�*/
	while (p != T) /*�������������ʱ,p==T*/
	{
		while (p->LTag == Link)
		{
			p = p->lchild;
		}
		if (!Thrvisit(p->data)) /*������������Ϊ�յĽ��*/
		{
			return ERROR;
		}
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			Thrvisit(p->data); /*���ʺ�̽��*/
		}
		p = p->rchild;
	}
	return OK;
}

/*����������*/
int mainThreading(void)
{

	/*��ʼ������*/
	BiThrTree H, T;

	/*��ǰ�����������*/
	printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
	CreateBiThrTree(&T);

	/*�������,������������������*/
	InOrderThreading(&H, T);

	/*�������(���)����������*/
	printf("�������(���)����������:\n");
	InOrderTraverse_Thr(H);

	getchar();

}
