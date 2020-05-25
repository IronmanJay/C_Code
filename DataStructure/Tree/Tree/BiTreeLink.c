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
#define MAXSIZE 100 /*存储空间初始分配量*/

typedef int Status;		/*Status是函数的类型,其值是函数结果状态代码，如OK等*/

/*用于构造二叉树*/
int index = 1;
typedef char String[24]; /*0号单元存放串的长度*/
String str;

/*初始化二叉树*/
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
TElemType LinkNil = ' '; /*字符型以空格符为空*/

/*打印数据元素*/
Status Linkvisit(TElemType e)
{
	printf("%c ", e);
	return OK;
}

/*结点结构*/
typedef struct BiTNode
{
	TElemType data;		/* 结点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree;


/*构造空二叉树T*/
Status LinkInitBiTree(BiTree *T)
{
	*T = NULL;
	return OK;
}

/*初始条件: 二叉树T存在*/
/*操作结果: 销毁二叉树T*/
void LinkDestroyBiTree(BiTree *T)
{
	if (*T)
	{
		if ((*T)->lchild) /*有左孩子*/
		{
			LinkDestroyBiTree(&(*T)->lchild); /*销毁左孩子子树*/
		}
		if ((*T)->rchild) /* 有右孩子 */
		{
			LinkDestroyBiTree(&(*T)->rchild); /*销毁右孩子子树*/
		}
		free(*T); /*释放根结点*/
		*T = NULL; /*空指针赋0*/
	}
}

/*按前序输入二叉树中结点的值（一个字符）*/
/*#表示空树，构造二叉链表表示二叉树T*/
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
		(*T)->data = ch; /* 生成根结点 */
		LinkCreateBiTree(&(*T)->lchild); /* 构造左子树 */
		LinkCreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
}

/*初始条件: 二叉树T存在*/
/*操作结果: 若T为空二叉树,则返回TRUE,否则FALSE*/
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

/*初始条件: 二叉树T存在*/
/*操作结果: 返回T的深度*/
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

/*初始条件: 二叉树T存在*/
/*操作结果: 返回T的根*/
TElemType LinkRoot(BiTree T)
{
	if (LinkBiTreeEmpty(T))
	{
		return ERROR; /*之前是LinkNil，因为判断是Boolean类型，所以改成了ERROR*/
	}
	else
	{
		return T->data;
	}
}

/*初始条件: 二叉树T存在，p指向T中某个结点*/
/*操作结果: 返回p所指结点的值*/
TElemType LinkValue(BiTree p)
{
	return p->data;
}

/*给p所指结点赋值为value*/
void LinkAssign(BiTree p, TElemType value)
{
	p->data = value;
}

/*初始条件: 二叉树T存在*/
/*操作结果: 前序递归遍历T*/
void LinkPreOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c", T->data);/*显示结点数据，可以更改为其它对结点操作*/
	LinkPreOrderTraverse(T->lchild); /*再先序遍历左子树*/
	LinkPreOrderTraverse(T->rchild); /*最后先序遍历右子树*/
}

/*初始条件: 二叉树T存在 */
/*操作结果: 中序递归遍历T */
void LinkInOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	LinkInOrderTraverse(T->lchild); /*中序遍历左子树*/
	printf("%c", T->data);/*显示结点数据，可以更改为其它对结点操作*/
	LinkInOrderTraverse(T->rchild); /*最后中序遍历右子树*/
}

/*初始条件: 二叉树T存在*/
/*操作结果: 后序递归遍历T*/
void LinkPostOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	LinkPostOrderTraverse(T->lchild); /*先后序遍历左子树*/
	LinkPostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%c", T->data); /*显示结点数据，可以更改为其它对结点操作*/
}


int mainLink(void)
{
	/*初始化参数*/
	int i;
	BiTree T;
	TElemType e1;
	LinkInitBiTree(&T);

	/*初始化二叉树*/
	LinkStrAssign(str, "ABDH#K###E##CFI###G#J##");

	/*创建二叉树*/
	LinkCreateBiTree(&T);

	/*打印信息*/
	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", LinkBiTreeEmpty(T), LinkBiTreeDepth(T));

	/*获得根结点*/
	e1 = LinkRoot(T);
	printf("二叉树的根为: %c\n", e1);

	/*前序、中序、后序遍历二叉树*/
	printf("前序遍历二叉树:");
	LinkPreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	LinkInOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	LinkPostOrderTraverse(T);

	/*请空二叉树*/
	LinkClearBiTree(&T);

	/*打印信息*/
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", LinkBiTreeEmpty(T), LinkBiTreeDepth(T));

	/*打印根节点*/
	i = LinkRoot(T);
	if (!i)
	{
		printf("树空，无根\n");
	}

	getchar();

}

