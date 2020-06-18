#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*使用数组模拟栈*/
#define MAX_COUNT 50
int p856stack[MAX_COUNT] = { 0 };
int p856stack_top = 0;

/*初始化栈*/
void p856stack_init()
{
	p856stack_top = 0;
	memset(p856stack, 0, sizeof(p856stack));
}

/*入栈*/
void p856stack_push(int num)
{
	p856stack[p856stack_top++] = num;
}

/*出栈*/
int p856stack_pop()
{
	int num = p856stack[p856stack_top - 1];
	p856stack[--p856stack_top] = 0;
	return num;
}

int scoreOfParentheses(char *S)
{
	/*新建一个栈，这个栈不是用来存放字符的，而是字符对应的得分*/
	p856stack_init();
	/*初始当前深度为0，得分为0*/
	p856stack_push(0);
	/*如果遇到（就将0入栈，说明还没有与之配对的，如果遇到）说明遇到了一个与之配对的，那么pop出两个元素，对应的分数就为1，再将新的分数push*/
	/*①、如果在上面的情况遇到了（，则继续将0入栈，还没有与之配对的*/
	/*②、如果在最上面的初始条件又遇到了），则说明现在肯定有（AB）型的，则pop出两个元素，这两个元素对应就是AB的分数，将其*2，但是还要加上最后一次pop的分数，因为要计算分数和，这里使用max是因为第一次）进入可能正好形成（），但是如果再次进入），说明肯定事（AB）型，所以要取最大值*/
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

/*主函数省略*/