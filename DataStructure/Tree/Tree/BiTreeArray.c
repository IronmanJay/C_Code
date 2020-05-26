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
#define MAX_TREE_SIZE 100 /*���������������*/

typedef int Status; /*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
typedef int TElemType; /*�������������ͣ�Ŀǰ�ݶ�Ϊ����*/
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /*0�ŵ�Ԫ�洢�����*/

typedef struct
{
	int level, order; /*���Ĳ㣬������ţ��������������㣩*/
}Position;

TElemType Nil = 0; /*��������0Ϊ��*/

/*��ӡ����Ԫ��*/
Status visit(TElemType c)
{
	printf("%d ", c);
	return OK;
}

/*����ն�����T����ΪT�ǹ̶����飬����ı䣬�ʲ���Ҫ&*/
Status InitBiTree(SqBiTree T)
{
	int i;
	for (i = 0; i < MAX_TREE_SIZE; i++)
	{
		T[i] = Nil; /*��ֵΪ��*/
	}
	return OK;
}

/*�������������������н���ֵ���ַ��ͻ����ͣ�������˳��洢�Ķ�����T*/
Status CreateBiTree(SqBiTree T)
{
	int i = 0;
	while (i < 10)
	{
		T[i] = i + 1;
		if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil) /*�˽�㣨���գ���˫���Ҳ��Ǹ�*/
		{
			printf("������˫�׵ķǸ����%d\n", T[i]);
			exit(ERROR);
		}
		i++;
	}
	while (i < MAX_TREE_SIZE)
	{
		T[i] = Nil; /*���ո�ֵ��T�ĺ���Ľ��*/
		i++;
	}
	return OK;
}

/*��ն���������˳��洢�ṹ�У���������ȫһ��*/
#define ClearBiTree InitBiTree

/*��ʼ������������T����*/
/*�����������TΪ�ն��������򷵻�TRUE�����򷵻�FALSE*/
Status BiTreeEmpty(SqBiTree T)
{
	if (T[0] == Nil) /*���ڵ�Ϊ�գ�������*/
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*��ʼ������������T����*/
/*�������������T�����*/
int BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--) /*�ҵ����һ�����*/
	{
		if (T[i] != Nil)
		{
			break;
		}
	}
	i++;
	do
	{
		j++;
	} while (i >= powl(2, j)); /*����2��j����*/
	return j;
}

/*��ʼ������������T����*/
/*�����������T���գ���e����T�ĸ�������OK�����򷵻�ERROR��e�޶���*/
Status Root(SqBiTree T, TElemType *e)
{
	if (BiTreeEmpty(T)) /*��*/
	{
		return ERROR;
	}
	else
	{
		*e = T[0];
		return OK;
	}
}

/*��ʼ������������T���ڣ�e��T��ĳ����㣨��λ�ã�*/
/*������������ش���λ��e���㣬������ţ��Ľ���ֵ*/
TElemType Value(SqBiTree T, Position e)
{
	return T[(int)powl(2, e.level - 1) + e.order - 2];
}

/*��ʼ������������T���ڣ�e��T��ĳ����㣨��λ�ã�*/
/*������������ش���λ��e���㣬������ţ��Ľ�㸳��ֵvalue*/
Status Assign(SqBiTree T, Position e, TElemType value)
{
	int i = (int)powl(2, e.level - 1) + e.order - 2; /*���㡢�������תΪ��������*/
	if (value != Nil && T[(i + 1) / 2 - 1] == Nil) /*��Ҷ�Ӹ��ǿ�ֵ��˫��Ϊ��*/
	{
		return ERROR;
	}
	else if (value == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil)) /*��˫�׸���ֵ����Ҷ�ӣ����գ�*/
	{
		return ERROR;
	}
	T[i] = value;
	return OK;
}

/*��ʼ������������T���ڣ�e��T��ĳ�����*/
/*�����������e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻�"��"*/
TElemType Parent(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil) /*����*/
	{
		return Nil;
	}
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e) /*�ҵ�e*/
		{
			return T[(i + 1) / 2 - 1];
		}
	}
	return Nil; /*û�ҵ�e*/
}

/*��ʼ������������T���ڣ�e��T��ĳ�����*/
/*�������������e�����ӣ���e�����ӣ��򷵻�"��"*/
TElemType LeftChild(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil) /*����*/
	{
		return Nil;
	}
	for (i = 0; i <= MAX_TREE_SIZE - 1; i++) {
		if (T[i] == e) /*�ҵ�e*/
		{
			return T[i * 2 + 1]; 
		}
	}
	return Nil; /*û�ҵ�e*/
}

/*��ʼ������������T���ڣ�e��T��ĳ�����*/
/*�������������e���Һ��ӣ���e���Һ��ӣ��򷵻�"��"*/
TElemType RightChild(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil) /*����*/
	{
		return Nil;
	}
	for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e) /*�ҵ�e*/
		{
			return T[i * 2 + 2];
		}
	}
	return Nil; /*û�ҵ�e*/
}

/*��ʼ������������T���ڣ�e��T��ĳ�����*/
/*�������������e�����ֵܣ���e��T�����ӻ������ֵܣ��򷵻�"��"*/
TElemType LeftSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil) /*����*/
	{
		return Nil;
	}
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e && i % 2 == 0) /*�ҵ�e�������Ϊż�������Һ��ӣ�*/
		{
			return T[i - 1];
		}
	}
	return Nil; /*û�ҵ�e*/
}

/*��ʼ������������T���ڣ�e��T��ĳ�����*/
/*�������������e�����ֵܣ���e��T���Һ��ӻ������ֵܣ��򷵻�"��"*/
TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil) /*����*/
	{
		return Nil;
	}
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e && i % 2) /*�ҵ�e�������Ϊ�����������ӣ�*/
		{
			return T[i + 1];
		}
	}
	return Nil; /*û�ҵ�e*/
}

/*PreOrderTraverse()����*/
void PreTraverse(SqBiTree T, int e)
{
	visit(T[e]);
	if (T[2 * e + 1] != Nil) /*����������*/
	{
		PreTraverse(T, 2 * e + 1);
	}
	if (T[2 * e + 1] != Nil) /*����������*/
	{
		PreTraverse(T, 2 * e + 2);
	}
}

/*��ʼ����������������*/
/*����������������T*/
Status PreOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		PreTraverse(T, 0);
	}
	printf("\n");
	return OK;
}

/*InOrderTraverse()����*/
void InTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil) /*����������*/
	{
		InTraverse(T, 2 * e + 1);
	}
	visit(T[e]);
	if (T[2 * e + 2] != Nil) /*����������*/
	{
		InTraverse(T, 2 * e + 2);
	}
}

/*��ʼ����������������*/
/*����������������T*/
Status InOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T)) /*������*/
	{
		InTraverse(T, 0);
	}
	printf("\n");
	return OK;
}

/*PostOrderTraverse()����*/
void PostTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil) /*����������*/
	{
		PostTraverse(T, 2 * e + 1);
	}
	if (T[2 * e + 2] != Nil) /*����������*/
	{
		PostTraverse(T, 2 * e + 2);
	}
	visit(T[e]);
}

/*��ʼ����������������*/
/*����������������T*/
Status PostOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T)) /*������*/
	{
		PostTraverse(T, 0);
	}
	printf("\n");
	return OK;
}

/*�������������*/
void LevelOrderTraverse(SqBiTree T)
{
	int i = MAX_TREE_SIZE - 1, j;
	while (T[i] == Nil)
	{
		i--; /*�ҵ����һ���ǿս������*/
	}
	for (j = 0; j <= i; j++) /*�Ӹ��ڵ��𣬰��������������*/
	{
		if (T[j] != Nil)
		{
			visit(T[j]); /*ֻ�����ǿյĽ��*/
		}
	}
	printf("\n");
}

/*��㡢������������������*/
void Print(SqBiTree T)
{
	int j, k;
	Position p;
	TElemType e;
	for (j = 1; j <= BiTreeDepth(T); j++)
	{
		printf("��%d�㣺", j);
		for (k = 1; k <= powl(2, j - 1); k++)
		{
			p.level = j;
			p.order = k;
			e = Value(T, p);
			if (e != Nil)
			{
				printf("%d:%d ", k, e);
			}
		}
		printf("\n");
	}
}

/*������˳��ṹʵ��*/
int mainBiTreeArray(void)
{

	/*��ʼ������*/
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;

	/*��ʼ����*/
	InitBiTree(T);

	/*������*/
	CreateBiTree(T);

	/*��ӡ�пպ��������*/
	printf("������������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));

	/*�õ����ĸ����*/
	i = Root(T, &e);
	if (i)
	{
		printf("�������ĸ�Ϊ��%d\n", e);
	}
	else
	{
		printf("���գ��޸�\n");
	}

	/*����ǰ�����򡢺��������*/
	printf("�������������:\n");
	LevelOrderTraverse(T);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("�������������:\n");
	InOrderTraverse(T);
	printf("�������������:\n");
	PostOrderTraverse(T);

	/*�ҵ�ĳ����㲢�ı���ֵ,��ǰ�������*/
	printf("�޸Ľ��Ĳ��3�������2��");
	p.level = 3;
	p.order = 2;
	e = Value(T, p);
	printf("���޸Ľ���ԭֵΪ%d��������ֵ:50 ", e);
	e = 50;
	Assign(T, p, e);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);

	/*��ӡ��������ֵܣ�˫�ף������Һ���*/
	printf("���%d��˫��Ϊ%d,���Һ��ӷֱ�Ϊ", e, Parent(T, e));
	printf("%d,%d,�����ֱֵܷ�Ϊ", LeftChild(T, e), RightChild(T, e));
	printf("%d,%d\n", LeftSibling(T, e), RightSibling(T, e));

	/*��ն�����*/
	ClearBiTree(T);

	/*��ӡ��պ�������Ϣ*/
	printf("�����������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));

	/*�õ����ĸ��ڵ�*/
	i = Root(T, &e);
	if (i)
	{
		printf("�������ĸ�Ϊ��%d\n", e);
	}
	else
	{
		printf("���գ��޸�\n");
	}

	getchar();

}