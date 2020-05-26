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
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/

typedef int Status; /*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
typedef int ElemType; /*ElemType���͸���ʵ������������������Ϊint*/
typedef char String[MAXSIZE + 1]; /*0�ŵ�Ԫ��Ŵ��ĳ���*/

/*����һ����ֵ����chars�Ĵ�T*/
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

/*��մ�*/
Status ClearStringKMP(String S)
{
	S[0] = 0; /*���Ϊ��*/
	return OK;
}

/*����ַ���T*/
void StrPrintKMP(String T)
{
	int i;
	for (i = 1; i <= T[0]; i++)
	{
		printf("%c", T[i]);
	}
	printf("\n");
}

/*���Next����ֵ*/
void NextPrintKMP(int next[], int length)
{
	int i;
	for (int i = 1; i <= length; i++)
	{
		printf("%d", next[i]);
	}
	printf("\n");
}

/*���ش���Ԫ�ظ���*/
int StrLengthKMP(String S)
{
	return S[0];
}

/*���ص�ģʽƥ�䷨*/
int IndexNormal(String S, String T, int pos)
{
	int i = pos; /*i��������S�е�ǰλ�õ��±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ��*/
	int j = 1; /*j�����ִ�T�е�ǰλ���±�ֵ*/
	while (i <= S[0] && j <= T[0]) /*��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������*/
	{
		if (S[i] == T[j]) /*���ַ���������*/
		{
			++i;
			++j;
		}
		else /*ָ��������¿�ʼƥ��*/
		{
			i = i - j + 2; /*i�˻ص��ϴ�ƥ����β����һλ*/
			j = 1; /*j�˻ص��ϴ��ִ�T����λ*/
		}
	}
	if (j > T[0]) /*˵��ƥ��ɹ�*/
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

/*ͨ�����㷵���ִ�T��next����*/
void get_next(String T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0]) /*�˴�T[0]��ʾ��T�ĳ���*/
	{
		if (j == 0 || T[i] == T[j]) /*T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�*/
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j]; /*���ַ�����ͬ����jֵ����*/
		}
	}
}

/*�����ִ�T������S�е�pos���ַ�֮���λ�ã��������ڣ���������ֵΪ0��T�ǿգ�1��pos��StrLength(S)*/
int Index_KMP(String S, String T, int pos)
{
	int i = pos; /*i��������S����Ǯλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ��*/
	int j = 1; /*j�����ִ�T�е�ǰλ���±�ֵ*/
	int next[255]; /*����һnext����*/
	get_next(T, next); /*�Դ�T���������õ�next����*/
	while (i <= S[0] && j <= T[0]) /*��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������*/
	{
		if (j == 0 || S[i] == T[j]) /*����ĸ�����������������㷨������j=0�ж�*/
		{
			++i;
			++j;
		}
		else /*ָ��������¿�ʼƥ��*/
		{
			j = next[j]; /*j�˻غ��ʵ�λ�ã�iֵ����*/
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

/*��ģʽ��T��next��������ֵ����������nextval*/
void get_nextval(String T, int *nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T[0]) /*�˴�T[0]��ʾ���ĳ���*/
	{
		if (j == 0 || T[i] == T[j]) /*T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�*/
		{
			++i;
			++j;
			if (T[i] != T[j]) /*����ǰ�ַ���ǰ׺�ַ���ͬ*/
			{
				nextval[i] = j; /*��ǰ��jΪnextval��iλ�õ�ֵ*/
			}
			else /*�����ǰ׺�ַ���ͬ����ǰ׺�ַ���nextvalֵ��ֵ��nextval��iλ�õ�ֵ*/
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j]; /*���ַ�����ͬ����jֵ����*/
		}
	}
}

/*�Ľ����KMP�㷨*/
int Index_KMP1(String S, String T, int pos)
{
	int i = pos; /*i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ��*/
	int j = 1; /*j�����ִ�T�е�ǰλ���±�ֵ*/
	int next[255]; /*����һnext����*/
	get_nextval(T, next); /*�Դ�T���������õ�next����*/
	while (i <= S[0] && j <= T[0]) /*��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������*/
	{
		if (j == 0 || S[i] == T[j]) /*����ĸ�����������������㷨������j=0�ж�*/
		{
			++i;
			++j;
		}
		else /*ָ��������¿�ʼƥ��*/
		{
			j = next[j]; /*j�˻غ��ʵ�λ�ã�iֵ����*/
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

/*ģʽƥ��*/
int mainKMP(void)
{

	/*��ʼ������*/
	int i, *p;
	String s1, s2;

	/*�����Ӵ�������ӡ�Ӵ������Ϣ*/
	StrAssignKMP(s1, "abcdex");
	printf("�ִ�Ϊ��");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*��ʼ��������ռ�*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*�����Ӵ���Ӧ��next���飬����ӡ�����Ϣ*/
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*�����Ӵ�������ӡ�Ӵ������Ϣ*/
	StrAssignKMP(s1, "abcabx");
	printf("�Ӵ�Ϊ: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*��ʼ��������ռ�*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*�����Ӵ���Ӧ��next���飬����ӡ�����Ϣ*/
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*�����Ӵ�������ӡ�Ӵ������Ϣ*/
	StrAssignKMP(s1, "ababaaaba");
	printf("�Ӵ�Ϊ: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*��ʼ��������ռ�*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*�����Ӵ���Ӧ��next���飬����ӡ�����Ϣ*/
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*�����Ӵ�������ӡ�Ӵ������Ϣ*/
	StrAssignKMP(s1, "aaaaaaaab");
	printf("�Ӵ�Ϊ: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*��ʼ��������ռ�*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*�����Ӵ���Ӧ��next���飬����ӡ�����Ϣ*/
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*�����Ӵ�������ӡ�Ӵ������Ϣ*/
	StrAssignKMP(s1, "ababaaaba");
	printf("�Ӵ�Ϊ: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*��ʼ��������ռ�*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*�����Ӵ���Ӧ��next�����nextval���飬����ӡ�����Ϣ*/
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	get_nextval(s1, p);
	printf("NextValΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*�����Ӵ�������ӡ�Ӵ������Ϣ*/
	StrAssignKMP(s1, "aaaaaaaab");
	printf("�Ӵ�Ϊ: ");
	StrPrintKMP(s1);
	i = StrLengthKMP(s1);
	/*��ʼ��������ռ�*/
	p = (int*)malloc((i + 1) * sizeof(int));
	/*�����Ӵ���Ӧ��next�����nextval���飬����ӡ�����Ϣ*/
	get_next(s1, p);
	printf("NextΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	get_nextval(s1, p);
	printf("NextValΪ: ");
	NextPrintKMP(p, StrLengthKMP(s1));
	printf("\n");

	/*��������������ӡ���������Ϣ*/
	StrAssignKMP(s1, "00000000000000000000000000000000000000000000000001");
	printf("����Ϊ: ");
	StrPrintKMP(s1);
	/*�����Ӵ�������ӡ�Ӵ������Ϣ*/
	StrAssignKMP(s2, "0000000001");
	printf("�Ӵ�Ϊ: ");
	StrPrintKMP(s2);
	printf("\n");
	/*ʹ������ģʽƥ���ַ���*/
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n", IndexNormal(s1, s2, 1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n", Index_KMP(s1, s2, 1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨�� \n", Index_KMP1(s1, s2, 1));

	getchar();

}