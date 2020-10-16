#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*��ʾȾ��������ɫ*/
#define RED 1
#define BLUE 2

bool p886_PossibleBipartition_DFS(int** graph, int* graphColSize, int* color, int inedx, int colorCur)
{
	/*�ݹ���ֹ�����������ǰ������Ѿ�Ⱦɫ������Ҫ����Ⱦ�ɱ����ɫ�������ɫ��ͬ��˵�������˲���һ�飬����true�������ɫ��ͬ������Ҫ�����಻ϲ�����˷ֵ�һ���飬����false*/
	if (color[inedx] != 0)
	{
		return color[inedx] == colorCur;
	}
	/*ÿ�εݹ鶼������ϲ��������Ϊ�෴����ɫ*/
	color[inedx] = colorCur;
	/*׼������ǰ����˲�ϲ�����ھ���Ϊ�෴����ɫ*/
	int neiColor = (colorCur == RED) ? BLUE : RED;
	/*�����е�ǰ����˲�ϲ�����ھ�ȡ����*/
	for (int i = 0; i < graphColSize[inedx]; i++)
	{
		/*ÿ�εݹ鶼������ϲ��������Ϊ�෴����ɫ���ж�������ݹ���ֹ����*/
		if (!p886_PossibleBipartition_DFS(graph, graphColSize, color, graph[inedx][i], neiColor))
		{
			return false;
		}
	}
	/*����ɹ�������true*/
	return true;
}

bool possibleBipartition(int N, int** dislikes, int dislikesSize, int* dislikesColSize)
{
	/*ȾɫMap����ʾ��ǰ������Ƿ�Ⱦɫ��Ҳ�����Ƿ񱻷ֵ���ĳһ��*/
	int* color = (int *)malloc(sizeof(int)*(N + 1));
	memset(color, 0, sizeof(int)*(N + 1));
	/*ͼ���ڽӾ����г���*/
	int* graphColSize = (int *)malloc(sizeof(int)*(N + 1));
	memset(graphColSize, 0, sizeof(int)*(N + 1));
	/*ͼ���ڽӾ��󣬶��ǲ�ϲ�����˹��ɵ��ڽӾ���*/
	int** graph = (int **)malloc(sizeof(int*)*(N + 1));
	for (int i = 0; i <= N; i++)
	{
		graph[i] = (int *)malloc(sizeof(int)*(N + 1));
		memset(graph[i], 0, sizeof(int)*(N + 1));
	}
	/*��ʼ��ͼ���ڽӾ��󣬴�1~N*/
	for (int i = 0; i < dislikesSize; i++)
	{
		graph[dislikes[i][0]][graphColSize[dislikes[i][0]]] = dislikes[i][1];
		graphColSize[dislikes[i][0]]++;
		graph[dislikes[i][1]][graphColSize[dislikes[i][1]]] = dislikes[i][0];
		graphColSize[dislikes[i][1]]++;
	}
	/*����ÿһ���ˣ�������飬��1~N*/
	for (int i = 1; i <= N; i++)
	{
		/*��ΪҪ�ֳ����飬���Եڶ��鿪ʼ������ʱ��Ҫ��֤��һ��û�б�Ⱦɫ*/
		if (color[i] == 0)
		{
			/*Ĭ��û��Ⱦɫ����ʼ�������������������ɹ�ֱ�ӷ���false*/
			if (!p886_PossibleBipartition_DFS(graph, graphColSize, color, i, RED))
			{
				return false;
			}
		}
	}
	/*�ͷſռ�*/
	for (int i = 0; i <= N; i++)
	{
		free(graph[i]);
	}
	free(graph);
	free(graphColSize);
	free(color);
	/*����ɹ�������true*/
	return true;
}

/*������ʡ��*/
