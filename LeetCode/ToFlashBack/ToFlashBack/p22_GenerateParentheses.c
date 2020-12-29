#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void p22_GenerateParentheses(char** res, int *returnSize, char* path, int pathIndex, int leftCount, int rightCount)
{
	/*�ݹ��������������뵱�����ź������Ŷ��ù���֮��ſ��Լ��뵽������鲢����*/
	if (leftCount == 0 && rightCount == 0)
	{
		/*���������СΪpathIndex+1��ԭ���ǽ�βҪԤ��һ��'\0'��λ��*/
		res[(*returnSize)] = (char*)calloc(pathIndex + 1, sizeof(char));
		strcpy(res[(*returnSize)++], path);
		return;
	}
	/*��֦��������Ϊ�ȼ���������ţ���ô�ڵݹ�����������ŵ�ʣ������һ���ϸ�С�������ŵ�ʣ��������������м�֦��������*/
	if (leftCount > rightCount)
	{
		return;
	}
	/*���ݲ�������������Ż���ʣ�࣬���������š��������а������ݵĲ��������ҵ�һ��������ϻ��߽����˼�֦��������ص���δ�����״̬*/
	if (leftCount > 0)
	{
		path[pathIndex++] = '(';
		p22_GenerateParentheses(res, returnSize, path, pathIndex, leftCount - 1, rightCount);
		path[--pathIndex] = 0;
	}
	/*���ݲ�������������Ż���ʣ�࣬���������š��������а������ݵĲ��������ҵ�һ��������ϻ��߽����˼�֦��������ص���δ�����״̬*/
	if (rightCount > 0)
	{
		path[pathIndex++] = ')';
		p22_GenerateParentheses(res, returnSize, path, pathIndex, leftCount, rightCount - 1);
		path[--pathIndex] = 0;
	}
}

char** generateParenthesis(int n, int* returnSize)
{
	/*�������*/
	char** res = (char**)malloc(sizeof(char*) * 1500);
	/*�������ָ��*/
	*returnSize = 0;
	/*·�����飬���������СΪ2*n+1��ԭ���ǽ�βҪԤ��һ��'\0'��λ��*/
	char* path = (char*)calloc((2 * n + 1), sizeof(char));
	/*��ʼ�ݹ�*/
	p22_GenerateParentheses(res, returnSize, path, 0, n, n);
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
