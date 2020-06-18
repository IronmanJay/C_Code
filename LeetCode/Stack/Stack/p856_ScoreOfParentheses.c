#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*ʹ������ģ��ջ*/
#define MAX_COUNT 50
int p856stack[MAX_COUNT] = { 0 };
int p856stack_top = 0;

/*��ʼ��ջ*/
void p856stack_init()
{
	p856stack_top = 0;
	memset(p856stack, 0, sizeof(p856stack));
}

/*��ջ*/
void p856stack_push(int num)
{
	p856stack[p856stack_top++] = num;
}

/*��ջ*/
int p856stack_pop()
{
	int num = p856stack[p856stack_top - 1];
	p856stack[--p856stack_top] = 0;
	return num;
}

int scoreOfParentheses(char *S)
{
	/*�½�һ��ջ�����ջ������������ַ��ģ������ַ���Ӧ�ĵ÷�*/
	p856stack_init();
	/*��ʼ��ǰ���Ϊ0���÷�Ϊ0*/
	p856stack_push(0);
	/*����������ͽ�0��ջ��˵����û����֮��Եģ����������˵��������һ����֮��Եģ���ôpop������Ԫ�أ���Ӧ�ķ�����Ϊ1���ٽ��µķ���push*/
	/*�١�������������������ˣ����������0��ջ����û����֮��Ե�*/
	/*�ڡ������������ĳ�ʼ�����������ˣ�����˵�����ڿ϶��У�AB���͵ģ���pop������Ԫ�أ�������Ԫ�ض�Ӧ����AB�ķ���������*2�����ǻ�Ҫ�������һ��pop�ķ�������ΪҪ��������ͣ�����ʹ��max����Ϊ��һ�Σ�������������γɣ�������������ٴν��룩��˵���϶��£�AB���ͣ�����Ҫȡ���ֵ*/
	for (int i = 0; i < strlen(S); i++)
	{
		if (S[i] == '(')
		{
			p856stack_push(0);
		}
		else
		{
			int c1 = p856stack_pop();
			int c2 = p856stack_pop();
			p856stack_push(c2 + ((c1 * 2) > 1 ? (c1 * 2) : 1));
		}
	}
	return p856stack_pop();
}

/*������ʡ��*/