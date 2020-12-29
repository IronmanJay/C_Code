#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void p22_GenerateParentheses(char** res, int *returnSize, char* path, int pathIndex, int leftCount, int rightCount)
{
	/*递归跳出条件：必须当左括号和右括号都用过了之后才可以加入到结果数组并返回*/
	if (leftCount == 0 && rightCount == 0)
	{
		/*设置数组大小为pathIndex+1的原因是结尾要预留一个'\0'的位置*/
		res[(*returnSize)] = (char*)calloc(pathIndex + 1, sizeof(char));
		strcpy(res[(*returnSize)++], path);
		return;
	}
	/*剪枝操作：因为先加入的左括号，那么在递归过程中左括号的剩余数量一定严格小于右括号的剩余数量，否则进行剪枝操作返回*/
	if (leftCount > rightCount)
	{
		return;
	}
	/*回溯操作：如果左括号还有剩余，加入左括号。并且其中包括回溯的操作，当找到一组括号组合或者进行了剪枝操作都会回到还未加入的状态*/
	if (leftCount > 0)
	{
		path[pathIndex++] = '(';
		p22_GenerateParentheses(res, returnSize, path, pathIndex, leftCount - 1, rightCount);
		path[--pathIndex] = 0;
	}
	/*回溯操作：如果右括号还有剩余，加入右括号。并且其中包括回溯的操作，当找到一组括号组合或者进行了剪枝操作都会回到还未加入的状态*/
	if (rightCount > 0)
	{
		path[pathIndex++] = ')';
		p22_GenerateParentheses(res, returnSize, path, pathIndex, leftCount, rightCount - 1);
		path[--pathIndex] = 0;
	}
}

char** generateParenthesis(int n, int* returnSize)
{
	/*结果数组*/
	char** res = (char**)malloc(sizeof(char*) * 1500);
	/*结果数组指针*/
	*returnSize = 0;
	/*路经数组，设置数组大小为2*n+1的原因是结尾要预留一个'\0'的位置*/
	char* path = (char*)calloc((2 * n + 1), sizeof(char));
	/*开始递归*/
	p22_GenerateParentheses(res, returnSize, path, 0, n, n);
	/*返回结果*/
	return res;
}

/*主函数省略*/
