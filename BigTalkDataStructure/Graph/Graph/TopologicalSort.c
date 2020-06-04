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
#define MAXVEX 14
#define INFINITY 65535

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

/*�ڽӾ���ṹ*/
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/*�ڽӱ�ṹ*/
/*�߱�ṹ*/
typedef struct EdgeNode
{
	int adjvex; /*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
	int weight; /*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/
	struct EdgeNode *next; /*����ָ����һ���ڽӵ�*/
}EdgeNode;

/*�����ṹ*/
typedef struct VertexNode
{
	int in; /*�������*/
	int data; /*�����򣬴洢������Ϣ*/
	EdgeNode *firstedge; /*�߱�ͷָ��*/
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /*ͼ�е�ǰ�������ͱ���*/
}graphAdjList,*GraphAdjList;

/*����ͼ*/
void TopologicalSortCreateMGraph(MGraph *G)
{
	int i, j;
	G->numEdges = MAXEDGE;
	G->numVertexes = MAXVEX;
	/*��ʼ��ͼ*/
	for (i = 0; i < G->numVertexes; i++)
	{
		G->vexs[i] = i;
	}
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	G->arc[0][4] = 1;
	G->arc[0][5] = 1;
	G->arc[0][11] = 1;
	G->arc[1][2] = 1;
	G->arc[1][4] = 1;
	G->arc[1][8] = 1;
	G->arc[2][5] = 1;
	G->arc[2][6] = 1;
	G->arc[2][9] = 1;
	G->arc[3][2] = 1;
	G->arc[3][13] = 1;
	G->arc[4][7] = 1;
	G->arc[5][8] = 1;
	G->arc[5][12] = 1;
	G->arc[6][5] = 1;
	G->arc[8][7] = 1;
	G->arc[9][10] = 1;
	G->arc[9][11] = 1;
	G->arc[10][13] = 1;
	G->arc[12][9] = 1;
}

/*�����ڽӾ��󹹽��ڽӱ�*/
void TopologicalSortCreateALGraph(MGraph G, GraphAdjList *GL)
{
	int i, j;
	EdgeNode *e;
	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));
	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	/*���붥����Ϣ�����������*/
	for (i = 0; i < G.numVertexes; i++)
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; /*���߱���Ϊ�ձ�*/
	}
	/*�����߱�*/
	for (i = 0; i < G.numVertexes; i++)
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex = j; /*�ڽ����Ϊj*/
				e->next = (*GL)->adjList[i].firstedge; /*����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e*/
				(*GL)->adjList[i].firstedge = e; /*����ǰ�����ָ��ָ��e*/
				(*GL)->adjList[j].in++;
			}
		}
	}
}

/*����������GL�޻�·������������������в�����1�����л�·����0*/
Status Topological(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0; /*����ջָ���±�*/
	int count = 0; /*����ͳ���������ĸ���*/
	int *stack; /*��ջ�����Ϊ0�Ķ�����ջ*/
	stack = (int *)malloc(GL->numVertexes * sizeof(int));
	/*�����Ϊ0�Ķ�����ջ*/
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in)
		{
			stack[++top] = i;
		}
	}
	while (top != 0)
	{
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count++; /*���i�Ŷ��㣬������*/
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in)) /*��i�Ŷ�����ڽӵ�����-1�����-1��Ϊ0������ջ*/
			{
				stack[++top] = k;
			}
		}
	}
	printf("\n");
	if (count < GL->numVertexes)
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}

/*��������*/
int mainTopologicalSort(void)
{

	MGraph G;
	GraphAdjList GL;
	int result;
	TopologicalSortCreateMGraph(&G);
	TopologicalSortCreateALGraph(G, &GL);
	result = Topological(GL);
	printf("result:%d", result);

	getchar();

}
