#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define numCoursesParam 4 /*这应该是传入参数，但是因为vs2017要求表达式必须含有常量值，所以作为示例赋值为4*/

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
{
	/*结果数组*/
	int* res = (int *)malloc(sizeof(int)*numCourses);
	/*表示每个节点入度个数*/
	int inDegree[numCoursesParam];
	memset(inDegree, 0, sizeof(inDegree));
	/*邻接表，表示每个节点的下一个连接节点*/
	int** adj = (int **)malloc(sizeof(int *)*numCourses);
	int adjColSize[numCoursesParam];
	memset(adjColSize, 0, sizeof(adjColSize));
	/*队列存放入度为0的节点，表示当前节点不需要前置课程或者前置课程已经完成*/
	int* queue = (int *)malloc(sizeof(int)*numCourses);
	int head = 0;
	int tail = 0;
	/*结果数组指针*/
	int index = 0;
	/*初始化邻接表*/
	for (int i = 0; i < numCourses; i++)
	{
		adj[i] = (int *)malloc(sizeof(int)*numCourses);
	}
	/*给入度数组和邻接表赋值*/
	for (int i = 0; i < prerequisitesSize; i++)
	{
		int inNode = prerequisites[i][0];
		int outNode = prerequisites[i][1];
		inDegree[inNode]++;
		adjColSize[outNode]++;
		adj[outNode] = (int *)realloc(adj[outNode], sizeof(int)*adjColSize[outNode]);
		adj[outNode][adjColSize[outNode] - 1] = inNode;
	}
	/*将入度为0的节点入队列*/
	for (int i = 0; i < numCourses; i++)
	{
		if (inDegree[i] == 0)
		{
			queue[tail++] = i;
		}
	}
	/*开始遍历*/
	while (head != tail)
	{
		int cur = queue[head++];
		res[index++] = cur;
		/*遍历当前节点的所有后继节点，这些节点的入度-1，可以看作此前置课程已经完成，所以后续课程也就没有此限定条件了*/
		for (int i = 0; i < adjColSize[cur]; i++)
		{
			inDegree[adj[cur][i]]--;
			/*如果有某一个后继节点入度为0，说明当前课程的前置课程已经完成，可以继续后面的课程，所以入队列*/
			if (inDegree[adj[cur][i]] == 0)
			{
				queue[tail++] = adj[cur][i];
			}
		}
	}
	/*释放空间*/
	for (int i = 0; i < numCourses; i++)
	{
		free(adj[i]);
	}
	free(adj);
	/*最终如果遍历得到的课程数量和题目所给的课程数量不相等，说明所给课程安排不符合要求，返回空数组*/
	if (index == numCourses)
	{
		*returnSize = numCourses;
	}
	else
	{
		*returnSize = 0;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
