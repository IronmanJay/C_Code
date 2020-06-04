#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*存储空间初始分配量*/

typedef int Status; /*Status是函数的类型，其值是函数结果状态代码，如OK等*/
typedef int ElemType; /*ElemType类型根据实际情况而定，这里假设为int*/
typedef char String[MAXSIZE + 1]; /*0号单元存放串的长度*/

/*生成一个其值等于chars的串T*/
Status StrAssignKMP(String T, char *chars)
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

/*清空串*/
Status ClearStringKMP(String S)
{
	S[0] = 0; /*令串长为零*/
	return OK;
}

/*输出字符串T*/
void StrPrintKMP(String T)
{
	int i;
	for (i = 1; i <= T[0]; i++)
	{
		printf("%c", T[i]);
	}
	printf("\n");
}

/*输出Next数组值*/
void NextPrintKMP(int next[], int length)
{
	int i;
	for (int i = 1; i <= length; i++)
	{
		printf("%d", next[i]);
	}
	printf("\n");
}

/*返回串的元素个数*/
int StrLengthKMP(String S)
{
	return S[0];
}

/*朴素的模式匹配法*/
int IndexNormal(String S, String T, int pos)
{
	int i = pos; /*i用于主串S中当前位置的下标值，若pos不为1，则从pos位置开始匹配*/
	int j = 1; /*j用于字串T中当前位置下标值*/
	while (i <= S[0] && j <= T[0]) /*若i小于S的长度并且j小于T的长度时，循环继续*/
	{
		if (S[i] == T[j]) /*两字符相等则继续*/
		{
			++i;
			++j;
		}
		else /*指针后退重新开始匹配*/
		{
			i = i - j + 2; /*i退回到上次匹配首尾的下一位*/
			j = 1; /*j退回到上次字串T的首位*/
		}
	}
	if (j > T[0]) /*说明匹配成功*/
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

/*通过计算返回字串T的next数组*/
void get_next(String T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0]) /*此处T[0]表示串T的长度*/
	{
		if (j == 0 || T[i] == T[j]) /*T[i]表示后缀的单个字符，T[j]表示前缀的单个字符*/
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j]; /*若字符不相同，则j值回溯*/
		}
	}
}

/*返回字串T在主串S中第pos个字符之后的位置，所不存在，则函数返回值为0，T非空，1≤pos≤StrLength(S)*/
int Index_KMP(String S, String T, int pos)
{
	int i = pos; /*i用于主串S但付钱位置下标值，若pos不为1，则从pos位置开始匹配*/
	int j = 1; /*j用于字串T中当前位置下标值*/
	int next[255]; /*定义一next数组*/
	get_next(T, next); /*对串T做分析，得到next数组*/
	while (i <= S[0] && j <= T[0]) /*若i小于S的长度并且j小于T的长度时，循环继续*/
	{
		if (j == 0 || S[i] == T[j]) /*两字母相等则继续，与朴素算法增加了j=0判断*/
		{
			++i;
			++j;
		}
		else /*指针后退重新开始匹配*/
		{
			j = next[j]; /*j退回合适的位置，i值不变*/
		}
	}
	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

/*求模式串T的next函数修正值并存入数组nextval*/
void get_nextval(String T, int *nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T[0]) /*此处T[0]表示串的长度*/
	{
		if (j == 0 || T[i] == T[j]) /*T[i]表示后缀的单个字符，T[j]表示前缀的单个字符*/
		{
			++i;
			++j;
			if (T[i] != T[j]) /*若当前字符与前缀字符不同*/
			{
				nextval[i] = j; /*则当前的j为nextval在i位置的值*/
			}
			else /*如果与前缀字符相同，则将前缀字符的nextval值赋值给nextval在i位置的值*/
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j]; /*若字符不相同，则j值回溯*/
		}
	}
}

/*改进后的KMP算法*/
int Index_KMP1(String S, String T, int pos)
{
	int i = pos; /*i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配*/
	int j = 1; /*j用于字串T中当前位置下标值*/
	int next[255]; /*定义一next数组*/
	get_nextval(T, next); /*对串T做分析，得到next数组*/
	while (i <= S[0] && j <= T[0]) /*若i小于S的长度并且j小于T的长度时，循环继续*/
	{
		if (j == 0 || S[i] == T[j]) /*两字母相等则继续，与朴素算法增加了j=0判断*/
		{
			++i;
			++j;
		}
		else /*指针后退重新开始匹配*/
		{
			j = next[j]; /*j退回合适的位置，i值不表*/
		}
	}
	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

/*模式匹配*/
int mainKMP(void)
{

	/*初始化参数*/
	int i, *p;
	String s1, s2;

	/*生成子串，并打印子串相关信息*/
	StrAssignKMP(s1, "abcdex");
	printf("字串为：");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*开始辅助数组空间*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*生成子串对应的next数组，并打印相关信息*/
	get_next(s1, p);
	printf("Next为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*生成子串，并打印子串相关信息*/
	StrAssignKMP(s1, "abcabx");
	printf("子串为: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*开始辅助数组空间*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*生成子串对应的next数组，并打印相关信息*/
	get_next(s1, p);
	printf("Next为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*生成子串，并打印子串相关信息*/
	StrAssignKMP(s1, "ababaaaba");
	printf("子串为: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*开始辅助数组空间*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*生成子串对应的next数组，并打印相关信息*/
	get_next(s1, p);
	printf("Next为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*生成子串，并打印子串相关信息*/
	StrAssignKMP(s1, "aaaaaaaab");
	printf("子串为: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*开始辅助数组空间*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*生成子串对应的next数组，并打印相关信息*/
	get_next(s1, p);
	printf("Next为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*生成子串，并打印子串相关信息*/
	StrAssignKMP(s1, "ababaaaba");
	printf("子串为: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*开始辅助数组空间*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*生成子串对应的next数组和nextval数组，并打印相关信息*/
	get_next(s1, p);
	printf("Next为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	get_nextval(s1, p);
	printf("NextVal为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*生成子串，并打印子串相关信息*/
	StrAssignKMP(s1, "aaaaaaaab");
	printf("子串为: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*开始辅助数组空间*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*生成子串对应的next数组和nextval数组，并打印相关信息*/
	get_next(s1, p);
	printf("Next为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	get_nextval(s1, p);
	printf("NextVal为: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*生成主串，并打印主串相关信息*/
	StrAssignKMP(s1, "00000000000000000000000000000000000000000000000001");
	printf("主串为: ");
	StrPrintKMP(s1);
	/*生成子串，并打印子串相关信息*/
	StrAssignKMP(s2, "0000000001");
	printf("子串为: ");
	StrPrintKMP(s2);
	printf("\n");
	/*使用三种模式匹配字符串*/
	printf("主串和子串在第%d个字符处首次匹配（朴素模式匹配算法）\n", IndexNormal(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP算法） \n", Index_KMP(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP改良算法） \n", Index_KMP1(s1, s2, 1));

	getchar();

}