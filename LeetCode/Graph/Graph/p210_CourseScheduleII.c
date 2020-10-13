#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define numCoursesParam 4 /*��Ӧ���Ǵ��������������Ϊvs2017Ҫ����ʽ���뺬�г���ֵ��������Ϊʾ����ֵΪ4*/

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
{
	/*�������*/
	int* res = (int *)malloc(sizeof(int)*numCourses);
	/*��ʾÿ���ڵ���ȸ���*/
	int inDegree[numCoursesParam];
	memset(inDegree, 0, sizeof(inDegree));
	/*�ڽӱ���ʾÿ���ڵ����һ�����ӽڵ�*/
	int** adj = (int **)malloc(sizeof(int *)*numCourses);
	int adjColSize[numCoursesParam];
	memset(adjColSize, 0, sizeof(adjColSize));
	/*���д�����Ϊ0�Ľڵ㣬��ʾ��ǰ�ڵ㲻��Ҫǰ�ÿγ̻���ǰ�ÿγ��Ѿ����*/
	int* queue = (int *)malloc(sizeof(int)*numCourses);
	int head = 0;
	int tail = 0;
	/*�������ָ��*/
	int index = 0;
	/*��ʼ���ڽӱ�*/
	for (int i = 0; i < numCourses; i++)
	{
		adj[i] = (int *)malloc(sizeof(int)*numCourses);
	}
	/*�����������ڽӱ�ֵ*/
	for (int i = 0; i < prerequisitesSize; i++)
	{
		int inNode = prerequisites[i][0];
		int outNode = prerequisites[i][1];
		inDegree[inNode]++;
		adjColSize[outNode]++;
		adj[outNode] = (int *)realloc(adj[outNode], sizeof(int)*adjColSize[outNode]);
		adj[outNode][adjColSize[outNode] - 1] = inNode;
	}
	/*�����Ϊ0�Ľڵ������*/
	for (int i = 0; i < numCourses; i++)
	{
		if (inDegree[i] == 0)
		{
			queue[tail++] = i;
		}
	}
	/*��ʼ����*/
	while (head != tail)
	{
		int cur = queue[head++];
		res[index++] = cur;
		/*������ǰ�ڵ�����к�̽ڵ㣬��Щ�ڵ�����-1�����Կ�����ǰ�ÿγ��Ѿ���ɣ����Ժ����γ�Ҳ��û�д��޶�������*/
		for (int i = 0; i < adjColSize[cur]; i++)
		{
			inDegree[adj[cur][i]]--;
			/*�����ĳһ����̽ڵ����Ϊ0��˵����ǰ�γ̵�ǰ�ÿγ��Ѿ���ɣ����Լ�������Ŀγ̣����������*/
			if (inDegree[adj[cur][i]] == 0)
			{
				queue[tail++] = adj[cur][i];
			}
		}
	}
	/*�ͷſռ�*/
	for (int i = 0; i < numCourses; i++)
	{
		free(adj[i]);
	}
	free(adj);
	/*������������õ��Ŀγ���������Ŀ�����Ŀγ���������ȣ�˵�������γ̰��Ų�����Ҫ�󣬷��ؿ�����*/
	if (index == numCourses)
	{
		*returnSize = numCourses;
	}
	else
	{
		*returnSize = 0;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
