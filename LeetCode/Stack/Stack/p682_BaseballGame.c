#include<stdio.h>

int calPoints(char ** ops, int opsSize)
{
	int* stack = (int*)malloc(sizeof(int) * opsSize);
	int top = 0;
	int res = 0;
	for (int i = 0; i < opsSize; i++)
	{
		switch (ops[i][0])
		{
		case '+':
			stack[top++] = stack[top - 1] + stack[top - 2];
			break;
		case 'D':
			stack[top++] = stack[top - 1] * 2;
			break;
		case 'C':
			top--;
			break;
		default:
			stack[top++] = atoi(ops[i]);
			break;
		}
	}
	for (int i = 0; i < top; i++)
	{
		res += stack[i];
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/