#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/*�Ա߼�����Edge�ṹ�Ķ���*/
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

/*����ͼ*/
void KruskalCreateMGraph(MGraph *G)
{
	int i, j;
	G->numEdges = 15;
	G->numVertexes = 9;
	/*��ʼ��ͼ*/
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = G->arc[j][i] = INFINITY;
			}
		}
	}
	/*�����ߵĹ�ϵ*/
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;
	/*��Ϊ������ͼ����Ӧλ�����*/
	for(i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

/*����Ȩֵ���Լ�ͷ��β*/
void Swapn(Edge *edges, int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

/*��Ȩֵ��������*/
void sort(Edge edges[], MGraph *G)
{
	int i, j;
	for (i = 0; i < G->numEdges; i++)
	{
		for (j = i + 1; j < G->numEdges; j++)
		{
			Swapn(edges, i, j);
		}
	}
	printf("Ȩ����֮���Ϊ:\n");
	for (i = 0; i < G->numEdges; i++)
	{
		printf("(%d, %d)\n", edges[i].begin, edges[i].end, edges[i].weight);
	}
}

/*�������߶����β���±�*/
int Find(int *parent, int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*������С������*/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int parent[MAXVEX]; /*����һά���������жϱ�����Ƿ��γɻ�·*/
	Edge edges[MAXEDGE]; /*����߼����飬edge�ĽṹΪbegin��end��wright����Ϊ����*/
	/*���������߼����鲢����*/
	for (i = 0; i < G.numVertexes - 1; i++)
	{
		for (j = i + 1; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] < INFINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;
			}
		}
	}
	sort(edges, &G);
	/*��ʼ������ֵΪ0*/
	for (i = 0; i < G.numVertexes; i++)
	{
		parent[i] = 0;
	}
	printf("��ӡ��С��������\n");
	/*ѭ��ÿһ����*/
	for (i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		/*����n��m���ȣ�˵���˱�û�������е��������γɻ�·*/
		if (n != m)
		{
			parent[n] = m; /*���˱ߵĽ�β��������±�Ϊ����parent�У���ʾ�˶����Ѿ���������������*/
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

/*��С������-Kruskal*/
int mainMiniSpanTreeKruskal(void)
{

	MGraph G;
	KruskalCreateMGraph(&G);
	MiniSpanTree_Kruskal(G);

	getchar();

}