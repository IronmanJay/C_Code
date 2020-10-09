#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*从小到大排序*/
int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize)
{
	/*八个方向*/
	int directions[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };
	/*结果数组指针*/
	*returnSize = 0;
	/*行数*/
	int row = landSize;
	/*列数*/
	int col = landColSize[0];
	/*结果数组*/
	int* res = (int *)calloc(row * col, sizeof(int));
	/*存放和当前水域连接的其他水域*/
	int** queue = (int **)calloc(row * col, sizeof(int *));
	/*队列中每一个位置存放的是当前水域的横坐标和纵坐标*/
	for (int i = 0; i < row * col; i++)
	{
		queue[i] = (int *)calloc(2, sizeof(int));
	}
	/*头指针*/
	int head;
	/*尾指针*/
	int tail;
	/*开始遍历*/
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			/*如果是水域的话开始BFS*/
			if (land[i][j] == 0)
			{
				/*当前水域数*/
				int num = 1;
				/*将当前水域置为陆地，防止二次遍历*/
				land[i][j] = 1;
				/*将当前水域入队列*/
				head = 0;
				tail = 0;
				queue[tail][0] = i;
				queue[tail][1] = j;
				tail++;
				/*开始遍历当前水域的其他连接水域，就是BFS*/
				while (head < tail)
				{
					/*出队列*/
					int x = queue[head][0];
					int y = queue[head][1];
					head++;
					/*向八个方向走，如果坐标在地图中，并且是水域，就将此水域置为陆地，防止二次遍历，并且入队列，找下一个连接的水域，并且当前水域数+1*/
					for (int k = 0; k < 8; k++)
					{
						int newX = x + directions[k][0];
						int newY = y + directions[k][1];
						if (newX < 0 || newY < 0 || newX >= row || newY >= col || land[newX][newY] != 0)
						{
							continue;
						}
						land[newX][newY] = 1;
						queue[tail][0] = newX;
						queue[tail][1] = newY;
						tail++;
						num++;
					}
				}
				/*当队列遍历完毕，说明当前没有连接的水域了，加入结果数组，准备下一次遍历*/
				res[(*returnSize)++] = num;
			}
		}
	}
	/*将结果数组从小到大排序*/
	qsort(res, *returnSize, sizeof(int), compare);
	/*释放空间*/
	for (int i = 0; i < row * col; i++)
	{
		free(queue[i]);
	}
	free(queue);
	/*返回结果*/
	return res;
}

/*主函数省略*/
