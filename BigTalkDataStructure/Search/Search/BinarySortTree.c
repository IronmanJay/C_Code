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

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

/*�������Ķ���������ṹ����*/
typedef struct BiTree /*���ṹ*/
{
	int data; /*�������*/
	struct BiTNode *lchild, *rchild; /*���Һ���ָ��*/
}BiTNode,*BiTree;

/*�ݹ���Ҷ���������T���Ƿ����key*/
/*ָ��fָ��T��˫�ף����ʼ����ֵΪNULL*/
/*�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE*/
/*����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE*/
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T) /*���Ҳ��ɹ�*/
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data) /*���ҳɹ�*/
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
	{
		return SearchBST(T->lchild, key, T, p); /*���������м�������*/
	}
	else
	{
		return SearchBST(T->rchild, key, T, p); /*���������м�������*/
	}
}

/*������������T�в����ڹؼ���key������Ԫ��ʱ������key������TRUE�����򷵻�FALSE*/
Status InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)) /*���Ҳ��ɹ�*/
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
		{
			*T = s; /*����ǿ���������sΪ�µĸ��ڵ�*/
		}
		else if (key < p->data) /*���С�ڲ��ҵ������һ���ڵ㣬����sΪ����*/
		{
			p->lchild = s;
		}
		else /*������ڲ��ҵ������һ���ڵ㣬����sΪ�Һ���*/
		{
			p->rchild = s;
		}
	}
	else
	{
		return FALSE; /*�������йؼ�����ͬ�Ľ�㣬���ٲ���*/
	}
}

/*�Ӷ�����������ɾ�����p�����ؽ��������������*/
Status Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL) /*���������������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧��*/
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL) /*���������������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧��*/
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else /*������������Ϊ��*/
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild) /*ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ����*/
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data; /*sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ��*/
		if (q != *p) /*���q��pָ��Ĳ���һ�����*/
		{
			q->rchild = s->lchild; /*�ؽ�q��������*/
		}
		else /*���p��qָ�����һ�����*/
		{
			q->lchild = s->lchild; /*�ؽ�q��������*/
		}
		free(s);
	}
	return TRUE;
}

/*������������T�д��ڹؼ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ�㣬������TRUE�����򷵻�FALSE*/
Status DeleteBST(BiTree *T, int key)
{
	if (!*T) /*�����ڹؼ��ֵ���key������Ԫ��*/
	{
		return FALSE;
	}
	else
	{
		if (key == (*T)->data) /*�ҵ��ؼ��ֵ���key������Ԫ��*/
		{
			return Delete(T);
		}
		else if (key < (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, key);
		}
		else
		{
			return DeleteBST(&(*T)->rchild, key);
		}
	}
}

/*�����������������*/
Status BSTInOrderTraverse(BiTree T)
{
	if (T->lchild != NULL) /*���������գ�����ݹ�*/
	{
		BSTInOrderTraverse(T->lchild);
	}
	printf("%d ", T->data); /*��ӡԪ��*/
	if (T->rchild != NULL) /*���������գ����ҵݹ�*/
	{
		BSTInOrderTraverse(T->rchild);
	}
	return OK;
}


int mainBinarySortTree(void)
{

	int i;
	int a[10] = { 62,88,58,47,35,73,51,99,37,93 };
	BiTree T = NULL;

	for (i = 0; i < 10; i++)
	{
		InsertBST(&T, a[i]);
	}
	BSTInOrderTraverse(T);
	printf("\n");
	DeleteBST(&T, 93);
	BSTInOrderTraverse(T);
	printf("\n");
	DeleteBST(&T, 47);
	BSTInOrderTraverse(T);
	printf("\n");

	getchar();

}
