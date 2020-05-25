#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/

typedef int Status;		/*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

/*���ڹ��������*/
int index = 1;
typedef char String[24]; /*0�ŵ�Ԫ��Ŵ��ĳ���*/
String str;

/*��ʼ��������*/
Status LinkStrAssign(String T, char *chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
	{
		return ERROR;
	}
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
		{
			T[i] = *(chars + i - 1);
		}
		return OK;
	}
}

/* ************************************************ */

typedef char TElemType;
TElemType LinkNil = ' '; /*�ַ����Կո��Ϊ��*/

/*��ӡ����Ԫ��*/
Status Linkvisit(TElemType e)
{
	printf("%c ", e);
	return OK;
}

/*���ṹ*/
typedef struct BiTNode
{
	TElemType data;		/* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
}BiTNode, *BiTree;


/*����ն�����T*/
Status LinkInitBiTree(BiTree *T)
{
	*T = NULL;
	return OK;
}

/*��ʼ����: ������T����*/
/*�������: ���ٶ�����T*/
void LinkDestroyBiTree(BiTree *T)
{
	if (*T)
	{
		if ((*T)->lchild) /*������*/
		{
			LinkDestroyBiTree(&(*T)->lchild); /*������������*/
		}
		if ((*T)->rchild) /* ���Һ��� */
		{
			LinkDestroyBiTree(&(*T)->rchild); /*�����Һ�������*/
		}
		free(*T); /*�ͷŸ����*/
		*T = NULL; /*��ָ�븳0*/
	}
}

/*��ǰ������������н���ֵ��һ���ַ���*/
/*#��ʾ������������������ʾ������T*/
void LinkCreateBiTree(BiTree *T)
{
	TElemType ch;
	ch = str[index++];
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		{
			exit(OVERFLOW);
		}
		(*T)->data = ch; /* ���ɸ���� */
		LinkCreateBiTree(&(*T)->lchild); /* ���������� */
		LinkCreateBiTree(&(*T)->rchild); /* ���������� */
	}
}

/*��ʼ����: ������T����*/
/*�������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE*/
Status LinkBiTreeEmpty(BiTree T)
{
	if (T)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

#define LinkClearBiTree LinkDestroyBiTree

/*��ʼ����: ������T����*/
/*�������: ����T�����*/
int LinkBiTreeDepth(BiTree T)
{
	int i, j;
	if (!T)
	{
		return 0;
	}
	if (T->lchild)
	{
		i = LinkBiTreeDepth(T->lchild);
	}
	else
	{
		i = 0;
	}
	if (T->rchild)
	{
		j = LinkBiTreeDepth(T->rchild);
	}
	else
	{
		j = 0;
	}
	return i > j ? i + 1 : j + 1;
}

/*��ʼ����: ������T����*/
/*�������: ����T�ĸ�*/
TElemType LinkRoot(BiTree T)
{
	if (LinkBiTreeEmpty(T))
	{
		return ERROR; /*֮ǰ��LinkNil����Ϊ�ж���Boolean���ͣ����Ըĳ���ERROR*/
	}
	else
	{
		return T->data;
	}
}

/*��ʼ����: ������T���ڣ�pָ��T��ĳ�����*/
/*�������: ����p��ָ����ֵ*/
TElemType LinkValue(BiTree p)
{
	return p->data;
}

/*��p��ָ��㸳ֵΪvalue*/
void LinkAssign(BiTree p, TElemType value)
{
	p->data = value;
}

/*��ʼ����: ������T����*/
/*�������: ǰ��ݹ����T*/
void LinkPreOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c", T->data);/*��ʾ������ݣ����Ը���Ϊ�����Խ�����*/
	LinkPreOrderTraverse(T->lchild); /*���������������*/
	LinkPreOrderTraverse(T->rchild); /*����������������*/
}

/*��ʼ����: ������T���� */
/*�������: ����ݹ����T */
void LinkInOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	LinkInOrderTraverse(T->lchild); /*�������������*/
	printf("%c", T->data);/*��ʾ������ݣ����Ը���Ϊ�����Խ�����*/
	LinkInOrderTraverse(T->rchild); /*����������������*/
}

/*��ʼ����: ������T����*/
/*�������: ����ݹ����T*/
void LinkPostOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	LinkPostOrderTraverse(T->lchild); /*�Ⱥ������������*/
	LinkPostOrderTraverse(T->rchild); /* �ٺ������������  */
	printf("%c", T->data); /*��ʾ������ݣ����Ը���Ϊ�����Խ�����*/
}


int mainLink(void)
{
	/*��ʼ������*/
	int i;
	BiTree T;
	TElemType e1;
	LinkInitBiTree(&T);

	/*��ʼ��������*/
	LinkStrAssign(str, "ABDH#K###E##CFI###G#J##");

	/*����������*/
	LinkCreateBiTree(&T);

	/*��ӡ��Ϣ*/
	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n", LinkBiTreeEmpty(T), LinkBiTreeDepth(T));

	/*��ø����*/
	e1 = LinkRoot(T);
	printf("�������ĸ�Ϊ: %c\n", e1);

	/*ǰ�����򡢺������������*/
	printf("ǰ�����������:");
	LinkPreOrderTraverse(T);
	printf("\n�������������:");
	LinkInOrderTraverse(T);
	printf("\n�������������:");
	LinkPostOrderTraverse(T);

	/*��ն�����*/
	LinkClearBiTree(&T);

	/*��ӡ��Ϣ*/
	printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n", LinkBiTreeEmpty(T), LinkBiTreeDepth(T));

	/*��ӡ���ڵ�*/
	i = LinkRoot(T);
	if (!i)
	{
		printf("���գ��޸�\n");
	}

	getchar();

}

