#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define nParam 3 /*��Ӧ���Ǵ��������������Ϊvs2017Ҫ����ʽ���뺬�г���ֵ��������Ϊʾ����ֵΪ2*/

bool I0401_RouteBetweenNodesLcci_DFS(int** adj, int* adjColSize, int start, int target, bool* visited)
{
	/*����ҵ�����true*/
	if (start == target)
	{
		return true;
	}
	/*����ǰ�����Ϊ�ѷ���*/
	visited[start] = true;
	for (int i = 0; i < adjColSize[start]; i++)
	{
		/*����ҵ�����true*/
		if (adj[start][i] == target)
		{
			return true;
		}
		/*��ûʹ�ù�������£��������������ǰ���ĺ�̽��*/
		if (visited[adj[start][i]] == false)
		{
			if (I0401_RouteBetweenNodesLcci_DFS(adj, adjColSize, adj[start][i], target, visited))
			{
				return true;
			}
		}
	}
	/*û�ҵ�����false*/
	return false;
}

bool findWhetherExistsPath(int n, int** graph, int graphSize, int* graphColSize, int start, int target)
{
	/*Ŀ��ֵ���ڵ��ڽ����������false*/
	if (target >= n)
	{
		return false;
	}
	/*�ڽӾ���*/
	int** adj = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
	{
		adj[i] = (int *)malloc(sizeof(int) * 50);
	}
	/*ÿ�����ĺ�̽����*/
	int adjColSize[nParam];
	memset(adjColSize, 0, sizeof(adjColSize));
	/*��ʼ���ڽӾ���*/
	for (int i = 0; i < graphSize; i++)
	{
		int from = graph[i][0];
		int to = graph[i][1];
		adj[from][adjColSize[from]] = graph[i][1];
		adjColSize[from]++;
	}
	/*�жϵ�ǰ�ڵ��Ƿ�ʹ�ù�*/
	bool visited[nParam];
	memset(visited, 0, sizeof(visited));
	/*��ʼ�����������*/
	bool res = I0401_RouteBetweenNodesLcci_DFS(adj, adjColSize, start, target, visited);
	/*�ͷſռ�*/
	for (int i = 0; i < n; i++)
	{
		free(adj[i]);
	}
	free(adj);
	/*���ؽ��*/
	return res;
}



