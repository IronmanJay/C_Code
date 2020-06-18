#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*ʹ������ģ��ջ*/
#define MAX_COUNT 10000
char p20stack[MAX_COUNT] = { 0 };
int p20stack_top = 0;

/*��ʼ��ջ*/
void p20stack_init()
{
	p20stack_top = 0;
	memset(p20stack, 0, sizeof(p20stack));
}

/*��ջ*/
void p20stack_push(char c)
{
	p20stack[p20stack_top++] = c;
}

/*��ջ*/
char p20stack_pop()
{
	char c = p20stack[p20stack_top - 1];
	p20stack[--p20stack_top] = 0;
	return c;
}

/*�ж�ջ�Ƿ�Ϊ��*/
bool p20stack_empty()
{
	if (p20stack_top <= 0)
	{
		return true;
	}
	return false;
}

/*�ж������Ƿ���Ч*/
bool isValid(char * s)
{
	/*��ʼ��ջ*/
	p20stack_init();
	/*����ջ�Ƚ��ȳ������ԣ�����һ���ַ����������Ӧ���ַ�ѹ��ջ�������е�����ַ���������֮��ÿ���ַ������Ӧ���ַ�������ջ*/
	/*���ʱ���ڼ��������ַ�����Ҳ��ʼ��ջ�е���Ԫ�أ�������ʱ�򵯳���Ԫ�����úͱ��������ַ�����ȣ���˵�����������Ч*/
	/*��Ϊ��ǰ����ַ��������ģ����������Ӧ���ַ���ջ�������α�����ȥ������������Ԫ�ض�������ջ�գ�˵���������Ŷ���Ч*/
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(')
		{
			p20stack_push(')');
		}
		else if (s[i] == '{')
		{
			p20stack_push('}');
		}
		else if (s[i] == '[')
		{
			p20stack_push(']');
		}
		else if (p20stack_empty() || s[i] != p20stack_pop())
		{
			return false;
		}
	}
	return p20stack_empty();
}

int main(void)
{
	/*������ʡ��*/
}
