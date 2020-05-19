#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*花园结构体*/
struct node
{
	int paths[4];
	int path_num;
	int color;
};

int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathColSize, int* returnSize)
{
	if (N == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int *res = (int *)malloc(sizeof(int) * N);
	memset(res, 0, sizeof(int) * N);
	struct node *Nodes = (struct node *)malloc(sizeof(struct node) * N);
	/*构造邻接矩阵*/
	for (int i = 0; i < pathsSize; i++)
	{
		int start = paths[i][0] - 1;
		int end = paths[i][1] - 1;
		Nodes[start].paths[Nodes[start].path_num] = end;
		Nodes[start].path_num++;
		Nodes[end].paths[Nodes[end].path_num] = start;
		Nodes[end].path_num++;
	}
	/*填充颜色*/
	for (int i = 0; i < N; i++)
	{
		int set[4] = { 1,-1,-1,-1 };
		for (int path_i = 0; path_i < Nodes[i].path_num; path_i++)
		{
			int n_path = Nodes[i].paths[path_i];
			/*这个颜色不能有*/
			if (res[n_path] != 0)
			{
				set[res[n_path] - 1] = 0;
			}
		}
		/*上色*/
		for (int j = 0; j < 4; j++)
		{
			if (set[j] == -1)
			{
				res[i] = j + 1;
				break;
			}
		}
	}
	*returnSize = N;
	return res;
}

/*主函数省略*/