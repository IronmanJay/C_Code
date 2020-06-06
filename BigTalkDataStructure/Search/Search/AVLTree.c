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
	int bf; /*����ƽ������*/
	struct BiTree *lchild, *rchild; /*���Һ���ָ��*/
}BiNode,*BiTree;

/*����PΪ���Ķ�������������������*/
/*����֮��Pָ���µ�������㣬����ת����֮ǰ���������ĸ��ڵ�*/
void R_Rotate(BiTree *P)
{
	BiTree L;
	L = (*P)->lchild; /*Lָ��P�����������ڵ�*/
	(*P)->lchild = L->rchild; /*L���������ҽ�ΪP��������*/
	L->rchild = (*P);
	*P = L; /*Pָ���µĸ��ڵ�*/
}

/*����PΪ���Ķ�������������������*/
/*����֮��Pָ���µ�������㣬����ת����֮ǰ���������ĸ��ڵ�*/
void L_Rotate(BiTree *P)
{
	BiTree R;
	R = (*P)->rchild; /*Rָ��P�����������ڵ�*/
	(*P)->rchild = R->lchild; /*R���������ҽ�ΪP��������*/
	R->lchild = (*P);
	*P = R; /*Pָ���µĸ��ڵ�*/
}

#define LH +1 /*���*/
#define EH 0 /*�ȸ�*/
#define RH -1 /*�Ҹ�*/

/*����ָ��T��ָ���ڵ�Ϊ���Ķ���������ƽ����ת����*/
/*���㷨����ʱ��ָ��Tָ���µĸ����*/
void LeftBalance(BiTree *T)
{
	BiTree L, Lr;
	L = (*T)->lchild; /*Lָ��T�����������ڵ�*/
	switch (L->bf) /*���T��������ƽ��ȣ�������Ӧƽ�⴦��*/
	{
		case LH: /*�½�������T�����ӵ��������ϣ�Ҫ������������*/
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH: /*�½�������T���Һ��ӵ��������ϣ�Ҫ��˫������*/
			Lr = L->rchild; /*Lrָ��T�����ӵ���������*/
			switch (Lr->bf) /*�޸�T�������ӵ�ƽ������*/
			{
				case LH: 
					(*T)->bf = RH;
					L->bf = EH;
					break;
				case EH:
					(*T)->bf = L->bf = EH;
					break;
				case RH:
					(*T)->bf = EH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild); /*��T��������������ƽ�⴦��*/
			R_Rotate(T); /*��T������ƽ�⴦��*/
	}
}

/*����ָ��T��ָ���Ϊ���Ķ���������ƽ�⴦��*/
/*���㷨����ʱ��ָ��Tָ���µĸ��ڵ�*/
void RightBalance(BiTree *T)
{
	BiTree R, Rl;
	R = (*T)->rchild; /*Rָ��T�����������ڵ�*/
	switch (R->bf) /*���T����������ƽ��ȣ�������Ӧƽ�⴦��*/
	{
		case RH: /*�½�������T���Һ��ӵ��������ϣ�Ҫ������������*/
			(*T)->bf = R->bf = EH;
			L_Rotate(T);
			break;
		case LH: /*�½�������T���Һ��ӵ��������ϣ�Ҫ��˫������*/
			Rl = R->lchild; /*Rlָ��T���Һ��ӵ���������*/
			switch (Rl->bf) /*�޸�T�����Һ��ӵ�ƽ������*/
			{
				case RH:
					(*T)->bf = LH;
					R->bf = EH;
					break;
				case EH:
					(*T)->bf = R->bf = EH;
					break;
				case LH:
					(*T)->bf = EH;
					R->bf = RH;
					break;
			}
			Rl->bf = EH;
			R_Rotate(&(*T)->rchild); /*��T��������������ƽ�⴦��*/
			L_Rotate(T); /*��T������ƽ�⴦��*/
	}
}

/*����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��Ϊe���½�㣬������1�����򷵻�0*/
/*��������ʹ����������ʧȥƽ�⣬����ƽ����ת������������taller��ӦT�������*/
Status InsertAVL(BiTree *T, int e, Status *taller)
{
	if (!*T) /*�����½�㣬�����ߣ���tallerΪTRUE*/
	{
		*T = (BiTree)malloc(sizeof(BiNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if (e == (*T)->data) /*�����Ѿ����ں�e����ͬ�ؼ��ֵĽ�����ٲ���*/
		{
			*taller = FALSE;
			return FALSE;
		}
		if (e < (*T)->data) /*Ӧ������T���������н�������*/
		{
			if (!InsertAVL(&(*T)->lchild, e, taller)) /*û�в���ɹ�*/
			{
				return FALSE;
			}
			if (*taller) /*�Ѿ����뵽T����������������������*/
			{
				switch ((*T)->bf) /*���T��ƽ���*/
				{
					case LH: /*ԭ�����������������ߣ���Ҫ����ƽ�⴦��*/
						LeftBalance(T);
						*taller = FALSE;
						break;
					case EH: /*ԭ�����������ȸߣ��������������߶�ʹ������*/
						(*T)->bf = LH;
						*taller = TRUE;
						break;
					case RH: /*ԭ�����������������ߣ������������ȸ�*/
						(*T)->bf = EH;
						*taller = FALSE;
						break;
				}
			}
		}
		else /*Ӧ������T���������н�������*/
		{
			if (!InsertAVL(&(*T)->rchild, e, taller)) /*û�в���ɹ�*/
			{
				return FALSE;
			}
			if (*taller) /*�Ѳ��뵽T��������������������*/
			{
				switch ((*T)->bf) /*���T��ƽ���*/
				{
				case LH: /*ԭ�����������������ߣ������������ȸ�*/
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				case EH: /*ԭ�����������ȸߣ��������������߶�ʹ������*/
					(*T)->bf = RH;
					*taller = TRUE;
					break;
				case RH: /*ԭ�����������������ߣ���Ҫ����ƽ�⴦��*/
					RightBalance(T);
					*taller = FALSE;
					break;
				}
			}
		}
	}
	return TRUE;
}

/*�������AVL��*/
Status AVLInOrderTraverse(BiTree T)
{
	if (T->lchild != NULL) /*���������գ�����ݹ�*/
	{
		AVLInOrderTraverse(T->lchild);
	}
	printf("%d ", T->data); /*��ӡԪ��*/
	if (T->rchild != NULL) /*���������գ����ҵݹ�*/
	{
		AVLInOrderTraverse(T->rchild);
	}
	return OK;
}

int mainAVLTree(void)
{

	int i;
	int a[10] = { 3,2,1,4,5,6,7,10,9,8 };
	BiTree T = NULL;
	Status taller;

	for (i = 0; i < 10; i++)
	{
		InsertAVL(&T, a[i], &taller);
	}

	AVLInOrderTraverse(T);

	getchar();

}
