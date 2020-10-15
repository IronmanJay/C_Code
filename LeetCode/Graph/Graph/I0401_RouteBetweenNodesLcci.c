#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define nParam 3 /*这应该是传入参数，但是因为vs2017要求表达式必须含有常量值，所以作为示例赋值为2*/

bool I0401_RouteBetweenNodesLcci_DFS(int** adj, int* adjColSize, int start, int target, bool* visited)
{
	/*如果找到返回true*/
	if (start == target)
	{
		return true;
	}
	/*将当前结点置为已访问*/
	visited[start] = true;
	for (int i = 0; i < adjColSize[start]; i++)
	{
		/*如果找到返回true*/
		if (adj[start][i] == target)
		{
			return true;
		}
		/*在没使用过的情况下，深度优先搜索当前结点的后继结点*/
		if (visited[adj[start][i]] == false)
		{
			if (I0401_RouteBetweenNodesLcci_DFS(adj, adjColSize, adj[start][i], target, visited))
			{
				return true;
			}
		}
	}
	/*没找到返回false*/
	return false;
}

bool findWhetherExistsPath(int n, int** graph, int graphSize, int* graphColSize, int start, int target)
{
	/*目标值大于等于结点数，返回false*/
	if (target >= n)
	{
		return false;
	}
	/*邻接矩阵*/
	int** adj = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
	{
		adj[i] = (int *)malloc(sizeof(int) * 50);
	}
	/*每个结点的后继结点数*/
	int adjColSize[nParam];
	memset(adjColSize, 0, sizeof(adjColSize));
	/*初始化邻接矩阵*/
	for (int i = 0; i < graphSize; i++)
	{
		int from = graph[i][0];
		int to = graph[i][1];
		adj[from][adjColSize[from]] = graph[i][1];
		adjColSize[from]++;
	}
	/*判断当前节点是否使用过*/
	bool visited[nParam];
	memset(visited, 0, sizeof(visited));
	/*开始深度优先搜索*/
	bool res = I0401_RouteBetweenNodesLcci_DFS(adj, adjColSize, start, target, visited);
	/*释放空间*/
	for (int i = 0; i < n; i++)
	{
		free(adj[i]);
	}
	free(adj);
	/*返回结果*/
	return res;
}



