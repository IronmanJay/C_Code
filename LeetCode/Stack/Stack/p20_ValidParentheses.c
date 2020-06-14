#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*ʹ������ģ��ջ*/
#define MAX_COUNT 10000
char stack[MAX_COUNT] = { 0 };
int stack_top = 0;

/*��ʼ��ջ*/
void stack_init()
{
	stack_top = 0;
	memset(stack, 0, sizeof(stack));
}

/*��ջ*/
void stack_push(char c)
{
	stack[stack_top++] = c;
}

/*��ջ*/
char stack_pop()
{
	char c = stack[stack_top - 1];
	stack[--stack_top] = 0;
	return c;
}

/*�ж�ջ�Ƿ�Ϊ��*/
bool stack_empty()
{
	if (stack_top <= 0)
	{
		return true;
	}
	return false;
}

/*�ж������Ƿ���Ч*/
bool isValid(char * s)
{
	/*��ʼ��ջ*/
	stack_init();
	/*����ջ�Ƚ��ȳ������ԣ�����һ���ַ����������Ӧ���ַ�ѹ��ջ�������е�����ַ���������֮��ÿ���ַ������Ӧ���ַ�������ջ*/
	/*���ʱ���ڼ��������ַ�����Ҳ��ʼ��ջ�е���Ԫ�أ�������ʱ�򵯳���Ԫ�����úͱ��������ַ�����ȣ���˵�����������Ч*/
	/*��Ϊ��ǰ����ַ��������ģ����������Ӧ���ַ���ջ�������α�����ȥ������������Ԫ�ض�������ջ�գ�˵���������Ŷ���Ч*/
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(')
		{
			stack_push(')');
		}
		else if (s[i] == '{')
		{
			stack_push('}');
		}
		else if (s[i] == '[')
		{
			stack_push(']');
		}
		else if (stack_empty() || s[i] != stack_pop())
		{
			return false;
		}
	}
	return stack_empty();
}

int main(void)
{
	/*������ʡ��*/
}
