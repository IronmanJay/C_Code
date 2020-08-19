#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*利用栈的思想，并没有实际创建栈，在原字符串上操作*/
char * removeDuplicates(char * S) 
{
	/*“栈”顶指针*/
	int top = -1;
	/*字符串指针*/
	int read = 0;
	/*用于存放每次遍历的字符*/
	char ch;
	/*开始遍历*/
	while (ch = S[read++])
	{
		/*如果是空栈，初始化栈，将新来的元素放在栈顶*/
		if (top < 0)
		{
			top = 0;
			S[top] = ch;
		}
		else
		{
			/*如果新来的元素和栈顶指针相同，说明出现重复元素，直接将重复的元素弹出*/
			if (S[top] == ch)
			{
				top--;
			}
			/*如果新来的元素和栈顶元素不相同，说明这个元素可以用，直接入栈*/
			else
			{
				S[++top] = ch;
			}
		}
	}
	/*将其余的截取，末尾置零*/
	S[++top] = 0;
	/*返回结果*/
	return S;
}

/*主函数省略*/
