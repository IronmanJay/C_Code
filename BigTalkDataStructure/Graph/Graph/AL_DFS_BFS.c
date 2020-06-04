#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /*存储空间初始分配量*/
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status; /*Status是函数的类型,其值是函数结果状态代码,如OK等*/
typedef int Boolean; /*Boolean是布尔类型,其值是TRUE或FALSE*/
typedef char VertexType; /*顶点类型应由用户定义*/
typedef int EdgeType; /*边上的权值类型应由用户定义*/

/*邻接矩阵结构*/
typedef struct
{
	VertexType vexs[MAXVEX]; /*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX]; /*邻接矩阵，可看作边表*/
	int numVertexes, numEdges; /*图中当前的顶点数和边数*/
}MGraph;

/*边表结点*/
typedef struct EdgeNode
{
	int adjvex; /*邻接点域，存储该顶点对应的下标*/
	int weight; /*用于存储权值，对于非网图可以不需要*/
	struct EdgeNode *next; /*链域指向下一个邻接点*/
}EdgeNode;

/*顶点表结点*/
typedef struct VertexNode
{
	int in; /*顶点入度*/
	char data; /*顶点域，存储顶点信息*/
	EdgeNode *firstedge; /*边表头指针*/
}VertexNode,AdjList[MAXVEX];

/*邻接表结构*/
typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /*图中当前顶点数和边数*/
}graphAdjList,*GraphAdjLlst;

/*循环队列的顺序存储结构*/
typedef struct
{
	int data[MAXSIZE];
	int front; /*头指针*/
	int rear; /*尾指针，若队列不空，指向队列尾元素的下一个位置*/
}Queue;

/*初始化一个空队列Q*/
Status ALInitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/*若队列Q为空队列，则返回TRUE，否则返回FALSE*/
Status ALQueueEmpty(Queue Q)
{
	if (Q.front == Q.rear) /*队列空的标志*/
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*若队列未满，则插入元素e为Q新的队尾元素*/
Status ALEnQueue(Queue *Q, int e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) /*队列满的判断*/
	{
		return ERROR;
	}
	Q->data[Q->rear] = e; /*将元素e赋值给队尾*/
	Q->rear = (Q->rear + 1) % MAXSIZE; /*rear指针向后移一位置*/
	return OK;
}

/*若队列不空，则删除Q中队头元素，用e返回其值*/
Status ALDeQueue(Queue *Q, int *e)
{
	if (Q->front == Q->rear) /*队列空的判断*/
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; /*将队头元素赋值给e*/
	Q->front = (Q->front + 1) % MAXSIZE; /*front指针向后移一位置*/
	return OK;
}

/*建立图*/
void ALCreateMGraph(MGraph *G)
{
	int i, j;
	/*边数*/
	G->numEdges = 15;
	/*顶点数*/
	G->numVertexes = 9;
	/*读入顶点信息，建立顶点表*/
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';
	/*初始化图*/
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	/*建立边的关系*/
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;
	G->arc[1][2] = 1;
	G->arc[1][8] = 1;
	G->arc[1][6] = 1;
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;
	G->arc[3][4] = 1;
	G->arc[3][7] = 1;
	G->arc[3][6] = 1;
	G->arc[3][8] = 1;
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;
	G->arc[5][6] = 1;
	G->arc[6][7] = 1;
	/*因为是无向图，建立双向的关系*/
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

/*利用邻接矩阵构建邻接表*/
void ALCreateALGraph(MGraph G, GraphAdjLlst *GL)
{
	int i, j;
	EdgeNode *e;
	*GL = (GraphAdjLlst)malloc(sizeof(graphAdjList));
	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	/*读入顶点信息，建立顶点表*/
	for (i = 0; i < G.numVertexes; i++)
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; /*将边表置为空表*/
	}
	/*建立边表*/
	for (i = 0; i < G.numVertexes; i++) 
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex = j; /*临界序号为j*/
				e->next = (*GL)->adjList[i].firstedge; /*将当前顶点上的指向的结点指针赋值给e*/
				(*GL)->adjList[i].firstedge = e; /*将当前顶点的指针指向e*/
				(*GL)->adjList[j].in++; /*邻接结点的入度+1*/
			}
		}
	}
}

Boolean ALvisited[MAXSIZE]; /*访问标志的数组*/

/*邻接表的深度优先递归算法*/
void ALDFS(GraphAdjLlst GL, int i)
{
	EdgeNode *p;
	ALvisited[i] = TRUE;
	printf("%c ", GL->adjList[i].data); /*打印顶点,也可以其它操作*/
	p = GL->adjList[i].firstedge;
	while (p)
	{
		if (!ALvisited[p->adjvex])
		{
			ALDFS(GL, p->adjvex); /*对未访问过的邻接顶点递归调用*/
		}
		p = p->next;
	}
}

/*邻接表的深度遍历操作*/
void ALDFSTraverse(GraphAdjLlst GL)
{
	int i;
	/*初始所有顶点状态都是未访问过状态*/
	for (int i = 0; i < GL->numVertexes; i++)
	{
		ALvisited[i] = FALSE;
	}
	/*对未访问过的顶点调用DFS，若是连通图，只会执行一次*/
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (!ALvisited[i])
		{
			ALDFS(GL, i);
		}
	}
}

/*邻接表的广度遍历算法*/
void ALBFSTraverse(GraphAdjLlst GL)
{
	int i;
	EdgeNode *p;
	Queue Q;
	for (i = 0; i < GL->numVertexes; i++)
	{
		ALvisited[i] = FALSE;
	}
	ALInitQueue(&Q);
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (!ALvisited[i])
		{
			ALvisited[i] = TRUE;
			printf("%c ", GL->adjList[i].data); /*打印顶点,也可以其它操作*/
			ALEnQueue(&Q, i);
			while (!ALQueueEmpty(Q))
			{
				ALDeQueue(&Q, &i);
				p = GL->adjList[i].firstedge; /*找到当前顶点的边表链表头指针*/
				while (p)
				{
					if (!ALvisited[p->adjvex]) /*若此顶点未被访问*/
					{
						ALvisited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						ALEnQueue(&Q, p->adjvex); /*将此顶点入队列*/
					}
					p = p->next; /*指针指向下一个邻接点*/
				}
			}
		}
	}
}

/*邻接表深度和广度遍历DFS_BFS*/
int mainAL_DFS_BFS(void)
{
	MGraph G;
	GraphAdjLlst GL;
	ALCreateMGraph(&G);
	ALCreateALGraph(G, &GL);
	printf("\n深度遍历:");
	ALDFSTraverse(GL);
	printf("\n广度遍历:");
	ALBFSTraverse(GL);
	getchar();
}
