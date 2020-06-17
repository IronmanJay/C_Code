#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int evalRPN(char ** tokens, int tokensSize)
{
	/*使用数组模拟栈*/
	int *stack = (int *)malloc(tokensSize * sizeof(int));
	int top = 0;
	/*right和left用来表示弹出元素的顺序，因为减法和除法要注意顺序*/
	int right = 0;
	int left = 0;
	/*存放运行结果值*/
	int val = 0;
	for (int i = 0; i < tokensSize; i++)
	{
		/*如果是运算符，则从栈中取出两个元素进行运算，因为运算符在tokens里是按顺序存放的，所以无需担心运算律问题，最后将结果保存进入stack。注：减法和除法要注意弹出的顺序*/
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
			/*如果是数字则压入栈*/
			stack[top++] = atoi(tokens[i]);
		}
	}
	/*返回结果*/
	return stack[--top];
}

/*主函数省略*/
