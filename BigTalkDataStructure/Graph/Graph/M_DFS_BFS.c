#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; /*Status是函数的类型,其值是函数结果状态代码，如OK等*/
typedef int Boolean; /*Boolean是布尔类型,其值是TRUE或FALSE*/
typedef char VertexType; /*顶点类型应由用户定义*/
typedef int EdgeType; /*边上的权值类型应由用户定义*/

#define MAXSIZE 9 /*存储空间初始分配量*/
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

/*邻接矩阵结构*/
typedef struct
{
	VertexType vexs[MAXVEX]; /*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX]; /*邻接矩阵，可看作边表*/
	int numVertexes, numEdges; /*图中当前的顶点数和边数*/
}MGraph;

/*循环队列的顺序存储结构*/
typedef struct
{
	int data[MAXSIZE];
	int front; /*头指针*/
	int rear; /*尾指针，若队列不为空，指向队列尾元素的下一个位置*/
}Queue;

/*初始化一个空队列Q*/
Status MInitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return  OK;
}

/*若队列Q为空队列，则返回TRUE，否则返回FALSE*/
Status MQueueEmpty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return TRUE; /*队列空的标志*/
	}
	else
	{
		return FALSE;
	}
}

/*若队列未满，则插入元素e为Q新的队尾元素*/
Status MEnQueue(Queue *Q, int e)
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
Status MDeQueue(Queue *Q, int *e)
{
	if (Q->front == Q->rear) /*队列空的判断*/
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; /*将队头元素赋值给e*/
	Q->front = (Q->front + 1) % MAXSIZE; /*front指针向后移一位置，若到最后则转到数组头部*/
	return OK;
}

/*建立图*/
void MCreateMGraph(MGraph *G)
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
	/*因为是无向图，需要建立双向的关系*/
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

Boolean Mvisited[MAXVEX];

/*邻接矩阵的深度优先递归算法*/
void MDFS(MGraph G, int i)
{
	int j;
	Mvisited[i] = FALSE;
	printf("%c ", G.vexs[i]); /*打印顶点，也可以其他操作*/
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && Mvisited[j])
		{
			MDFS(G, j); /*对未访问的邻接顶点递归调用*/
		}
	}
}

/*邻接矩阵的深度遍历操作*/
void MDFSTraverse(MGraph G)
{
	int i;
	/*初始所以顶点状态都是未访问过状态*/
	for (i = 0; i < G.numVertexes; i++)
	{
		Mvisited[i] = FALSE;
	}
	/*对未访问过的顶点调用DFS，若是连通图，只会执行一次*/
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!Mvisited[i])
		{
			MDFS(G, i);
		}
	}
}

/*邻接矩阵的广度遍历算法*/
void MBFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexes; i++)
	{
		Mvisited[i] = FALSE;
	}
	/*初始化一辅助用的队列*/
	MInitQueue(&Q);
	/*对每一个顶点做循环*/
	for (i = 0; i < G.numVertexes; i++)
	{
		/*若是未访问过的就处理*/
		if (!Mvisited[i])
		{
			Mvisited[i] = TRUE; /*设置当前顶点访问过*/
			printf("%c ", G.vexs[i]); /*打印顶点，也可以其他操作*/
			MEnQueue(&Q, i); /*将此顶点入队列*/
			while (!MQueueEmpty(Q)) /*若当前队列不为空*/
			{
				MDeQueue(&Q, &i); /*将队头元素出队列，赋值给i*/
				for (j = 0; j < G.numVertexes; j++)
				{
					/*判断其他顶点若与当前顶点存在边且未访问过*/
					if (G.arc[i][j] == 1 && !Mvisited[j])
					{
						Mvisited[j] = TRUE; /*将找到的此顶点标记为已访问*/
						printf("%c ", G.vexs[j]); /*打印顶点*/
						MEnQueue(&Q, j); /*将找到的此顶点入队列*/
					}
				}
			}
		}
	}
}

/*邻接矩阵深度和广度优先遍历*/
int mainM_BFS_DFS(void)
{
	MGraph G;
	MCreateMGraph(&G);
	printf("\n深度遍历：");
	MDFSTraverse(G);
	printf("\n广度遍历：");
	MBFSTraverse(G);
	getchar();
}
