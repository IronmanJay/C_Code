#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*使用数组模拟栈*/
#define MAX_COUNT 10000
char p20stack[MAX_COUNT] = { 0 };
int p20stack_top = 0;

/*初始化栈*/
void p20stack_init()
{
	p20stack_top = 0;
	memset(p20stack, 0, sizeof(p20stack));
}

/*入栈*/
void p20stack_push(char c)
{
	p20stack[p20stack_top++] = c;
}

/*出栈*/
char p20stack_pop()
{
	char c = p20stack[p20stack_top - 1];
	p20stack[--p20stack_top] = 0;
	return c;
}

/*判断栈是否为空*/
bool p20stack_empty()
{
	if (p20stack_top <= 0)
	{
		return true;
	}
	return false;
}

/*判断括号是否有效*/
bool isValid(char * s)
{
	/*初始化栈*/
	p20stack_init();
	/*利用栈先进先出的特性，传入一个字符，他反向对应的字符压入栈，当所有的左边字符都遍历完之后，每个字符反向对应的字符都已入栈*/
	/*这个时候还在继续遍历字符串，也开始从栈中弹出元素，如果这个时候弹出的元素正好和遍历到的字符串相等，则说明这个括号有效*/
	/*因为当前这个字符最后进来的，和它反向对应的字符在栈顶，依次遍历下去，如果最后所有元素都弹出，栈空，说明所有括号都有效*/
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
	/*主函数省略*/
}
