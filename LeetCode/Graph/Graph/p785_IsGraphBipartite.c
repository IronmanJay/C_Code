#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*注：1为true，0为false*/
typedef int bool;
#define false 0
#define true 1

enum color
{
	unknown,
	white,
	black
};

bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
	int * pVisited = (int*)malloc(graphSize * sizeof(int));
	memset(pVisited, 0, graphSize * sizeof(int));
	int* pQueue = (int*)malloc(graphSize * sizeof(int));

	int front = -1;
	int rear = -1;
	int curr = 0;
	int row = 0;
	int col = 0;
	int neighborColor = 0;

	for (row = 0; row <= graphSize - 1; row++)
	{
		if (unknown != pVisited[row])
		{
			continue;
		}

		pQueue[++rear] = row;
		pVisited[row] = white;

		while (front != rear)
		{
			curr = pQueue[++front];
			neighborColor = pVisited[curr] == white ? black : white;
			for (col = 0; col <= graphColSize[curr] - 1; col++)
			{
				if (unknown == pVisited[graph[curr][col]])
				{
					pVisited[graph[curr][col]] = neighborColor;
				}
				else if (neighborColor != pVisited[graph[curr][col]])
				{
					return false;
				}
			}
		}
	}
	return true;
}

/*主函数省略*/