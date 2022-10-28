#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
{
	int n = isConnectedSize;
	int* queue = (int*)calloc((n * n), sizeof(int));
	int front = 0;
	int rear = 0;
	bool visited[201] = { false };
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			queue[rear++] = i;
			while (front != rear)
			{
				int j = queue[front++];
				visited[j] = true;
				for (int k = 0; k < n; k++)
				{
					if (isConnected[j][k] == 1 && !visited[k])
					{
						queue[rear++] = k;
					}
				}
			}
			res++;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/