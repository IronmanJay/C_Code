#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*��С��������*/
int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize)
{
	/*�˸�����*/
	int directions[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };
	/*�������ָ��*/
	*returnSize = 0;
	/*����*/
	int row = landSize;
	/*����*/
	int col = landColSize[0];
	/*�������*/
	int* res = (int *)calloc(row * col, sizeof(int));
	/*��ź͵�ǰˮ�����ӵ�����ˮ��*/
	int** queue = (int **)calloc(row * col, sizeof(int *));
	/*������ÿһ��λ�ô�ŵ��ǵ�ǰˮ��ĺ������������*/
	for (int i = 0; i < row * col; i++)
	{
		queue[i] = (int *)calloc(2, sizeof(int));
	}
	/*ͷָ��*/
	int head;
	/*βָ��*/
	int tail;
	/*��ʼ����*/
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			/*�����ˮ��Ļ���ʼBFS*/
			if (land[i][j] == 0)
			{
				/*��ǰˮ����*/
				int num = 1;
				/*����ǰˮ����Ϊ½�أ���ֹ���α���*/
				land[i][j] = 1;
				/*����ǰˮ�������*/
				head = 0;
				tail = 0;
				queue[tail][0] = i;
				queue[tail][1] = j;
				tail++;
				/*��ʼ������ǰˮ�����������ˮ�򣬾���BFS*/
				while (head < tail)
				{
					/*������*/
					int x = queue[head][0];
					int y = queue[head][1];
					head++;
					/*��˸������ߣ���������ڵ�ͼ�У�������ˮ�򣬾ͽ���ˮ����Ϊ½�أ���ֹ���α�������������У�����һ�����ӵ�ˮ�򣬲��ҵ�ǰˮ����+1*/
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
				/*�����б�����ϣ�˵����ǰû�����ӵ�ˮ���ˣ����������飬׼����һ�α���*/
				res[(*returnSize)++] = num;
			}
		}
	}
	/*����������С��������*/
	qsort(res, *returnSize, sizeof(int), compare);
	/*�ͷſռ�*/
	for (int i = 0; i < row * col; i++)
	{
		free(queue[i]);
	}
	free(queue);
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
