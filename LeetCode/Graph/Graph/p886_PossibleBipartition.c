#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*表示染的两种颜色*/
#define RED 1
#define BLUE 2

bool p886_PossibleBipartition_DFS(int** graph, int* graphColSize, int* color, int inedx, int colorCur)
{
	/*递归终止条件，如果当前这个人已经染色，并且要给他染成别的颜色，如果颜色相同，说明两个人不在一组，返回true，如果颜色不同，就是要将互相不喜欢的人分到一个组，返回false*/
	if (color[inedx] != 0)
	{
		return color[inedx] == colorCur;
	}
	/*每次递归都将互不喜欢的人置为相反的颜色*/
	color[inedx] = colorCur;
	/*准备将当前这个人不喜欢的邻居置为相反的颜色*/
	int neiColor = (colorCur == RED) ? BLUE : RED;
	/*将所有当前这个人不喜欢的邻居取出来*/
	for (int i = 0; i < graphColSize[inedx]; i++)
	{
		/*每次递归都将互不喜欢的人置为相反的颜色，判断条件如递归终止条件*/
		if (!p886_PossibleBipartition_DFS(graph, graphColSize, color, graph[inedx][i], neiColor))
		{
			return false;
		}
	}
	/*如果成功，返回true*/
	return true;
}

bool possibleBipartition(int N, int** dislikes, int dislikesSize, int* dislikesColSize)
{
	/*染色Map，表示当前这个人是否被染色，也就是是否被分到了某一组*/
	int* color = (int *)malloc(sizeof(int)*(N + 1));
	memset(color, 0, sizeof(int)*(N + 1));
	/*图的邻接矩阵列长度*/
	int* graphColSize = (int *)malloc(sizeof(int)*(N + 1));
	memset(graphColSize, 0, sizeof(int)*(N + 1));
	/*图的邻接矩阵，都是不喜欢的人构成的邻接矩阵*/
	int** graph = (int **)malloc(sizeof(int*)*(N + 1));
	for (int i = 0; i <= N; i++)
	{
		graph[i] = (int *)malloc(sizeof(int)*(N + 1));
		memset(graph[i], 0, sizeof(int)*(N + 1));
	}
	/*初始化图的邻接矩阵，从1~N*/
	for (int i = 0; i < dislikesSize; i++)
	{
		graph[dislikes[i][0]][graphColSize[dislikes[i][0]]] = dislikes[i][1];
		graphColSize[dislikes[i][0]]++;
		graph[dislikes[i][1]][graphColSize[dislikes[i][1]]] = dislikes[i][0];
		graphColSize[dislikes[i][1]]++;
	}
	/*遍历每一个人，将其分组，从1~N*/
	for (int i = 1; i <= N; i++)
	{
		/*因为要分成两组，所以第二组开始遍历的时候要保证这一组没有被染色*/
		if (color[i] == 0)
		{
			/*默认没有染色，开始深度优先搜索，如果不成功直接返回false*/
			if (!p886_PossibleBipartition_DFS(graph, graphColSize, color, i, RED))
			{
				return false;
			}
		}
	}
	/*释放空间*/
	for (int i = 0; i <= N; i++)
	{
		free(graph[i]);
	}
	free(graph);
	free(graphColSize);
	free(color);
	/*如果成功，返回true*/
	return true;
}

/*主函数省略*/
