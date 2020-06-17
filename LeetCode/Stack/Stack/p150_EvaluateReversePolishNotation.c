#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int evalRPN(char ** tokens, int tokensSize)
{
	/*ʹ������ģ��ջ*/
	int *stack = (int *)malloc(tokensSize * sizeof(int));
	int top = 0;
	/*right��left������ʾ����Ԫ�ص�˳����Ϊ�����ͳ���Ҫע��˳��*/
	int right = 0;
	int left = 0;
	/*������н��ֵ*/
	int val = 0;
	for (int i = 0; i < tokensSize; i++)
	{
		/*���������������ջ��ȡ������Ԫ�ؽ������㣬��Ϊ�������tokens���ǰ�˳���ŵģ��������赣�����������⣬��󽫽���������stack��ע�������ͳ���Ҫע�ⵯ����˳��*/
		if (tokens[i][0] == '+')
		{
			right = stack[--top];
			left = stack[--top];
			val = left + right;
			stack[top++] = val;
		}
		else if (tokens[i][0] == '-' && tokens[i][1] == '\0')
		{
			right = stack[--top];
			left = stack[--top];
			val = left - right;
			stack[top++] = val;
		}
		else if (tokens[i][0] == '*')
		{
			right = stack[--top];
			left = stack[--top];
			val = left * right;
			stack[top++] = val;
		}
		else if (tokens[i][0] == '/')
		{
			right = stack[--top];
			left = stack[--top];
			val = left / right;
			stack[top++] = val;
		}
		else
		{
			/*�����������ѹ��ջ*/
			stack[top++] = atoi(tokens[i]);
		}
	}
	/*���ؽ��*/
	return stack[--top];
}

/*������ʡ��*/
