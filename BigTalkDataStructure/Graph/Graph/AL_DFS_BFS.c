#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /*�洢�ռ��ʼ������*/
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��*/
typedef int Boolean; /*Boolean�ǲ�������,��ֵ��TRUE��FALSE*/
typedef char VertexType; /*��������Ӧ���û�����*/
typedef int EdgeType; /*���ϵ�Ȩֵ����Ӧ���û�����*/

/*�ڽӾ���ṹ*/
typedef struct
{
	VertexType vexs[MAXVEX]; /*�����*/
	EdgeType arc[MAXVEX][MAXVEX]; /*�ڽӾ��󣬿ɿ����߱�*/
	int numVertexes, numEdges; /*ͼ�е�ǰ�Ķ������ͱ���*/
}MGraph;

/*�߱���*/
typedef struct EdgeNode
{
	int adjvex; /*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
	int weight; /*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/
	struct EdgeNode *next; /*����ָ����һ���ڽӵ�*/
}EdgeNode;

/*�������*/
typedef struct VertexNode
{
	int in; /*�������*/
	char data; /*�����򣬴洢������Ϣ*/
	EdgeNode *firstedge; /*�߱�ͷָ��*/
}VertexNode,AdjList[MAXVEX];

/*�ڽӱ�ṹ*/
typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /*ͼ�е�ǰ�������ͱ���*/
}graphAdjList,*GraphAdjLlst;

/*ѭ�����е�˳��洢�ṹ*/
typedef struct
{
	int data[MAXSIZE];
	int front; /*ͷָ��*/
	int rear; /*βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/
}Queue;

/*��ʼ��һ���ն���Q*/
Status ALInitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/*������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE*/
Status ALQueueEmpty(Queue Q)
{
	if (Q.front == Q.rear) /*���пյı�־*/
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*������δ���������Ԫ��eΪQ�µĶ�βԪ��*/
Status ALEnQueue(Queue *Q, int e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) /*���������ж�*/
	{
		return ERROR;
	}
	Q->data[Q->rear] = e; /*��Ԫ��e��ֵ����β*/
	Q->rear = (Q->rear + 1) % MAXSIZE; /*rearָ�������һλ��*/
	return OK;
}

/*�����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ*/
Status ALDeQueue(Queue *Q, int *e)
{
	if (Q->front == Q->rear) /*���пյ��ж�*/
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; /*����ͷԪ�ظ�ֵ��e*/
	Q->front = (Q->front + 1) % MAXSIZE; /*frontָ�������һλ��*/
	return OK;
}

/*����ͼ*/
void ALCreateMGraph(MGraph *G)
{
	int i, j;
	/*����*/
	G->numEdges = 15;
	/*������*/
	G->numVertexes = 9;
	/*���붥����Ϣ�����������*/
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';
	/*��ʼ��ͼ*/
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	/*�����ߵĹ�ϵ*/
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
	/*��Ϊ������ͼ������˫��Ĺ�ϵ*/
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

/*�����ڽӾ��󹹽��ڽӱ�*/
void ALCreateALGraph(MGraph G, GraphAdjLlst *GL)
{
	int i, j;
	EdgeNode *e;
	*GL = (GraphAdjLlst)malloc(sizeof(graphAdjList));
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
				e->adjvex = j; /*�ٽ����Ϊj*/
				e->next = (*GL)->adjList[i].firstedge; /*����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e*/
				(*GL)->adjList[i].firstedge = e; /*����ǰ�����ָ��ָ��e*/
				(*GL)->adjList[j].in++; /*�ڽӽ������+1*/
			}
		}
	}
}

Boolean ALvisited[MAXSIZE]; /*���ʱ�־������*/

/*�ڽӱ��������ȵݹ��㷨*/
void ALDFS(GraphAdjLlst GL, int i)
{
	EdgeNode *p;
	ALvisited[i] = TRUE;
	printf("%c ", GL->adjList[i].data); /*��ӡ����,Ҳ������������*/
	p = GL->adjList[i].firstedge;
	while (p)
	{
		if (!ALvisited[p->adjvex])
		{
			ALDFS(GL, p->adjvex); /*��δ���ʹ����ڽӶ���ݹ����*/
		}
		p = p->next;
	}
}

/*�ڽӱ����ȱ�������*/
void ALDFSTraverse(GraphAdjLlst GL)
{
	int i;
	/*��ʼ���ж���״̬����δ���ʹ�״̬*/
	for (int i = 0; i < GL->numVertexes; i++)
	{
		ALvisited[i] = FALSE;
	}
	/*��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ��*/
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (!ALvisited[i])
		{
			ALDFS(GL, i);
		}
	}
}

/*�ڽӱ�Ĺ�ȱ����㷨*/
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
			printf("%c ", GL->adjList[i].data); /*��ӡ����,Ҳ������������*/
			ALEnQueue(&Q, i);
			while (!ALQueueEmpty(Q))
			{
				ALDeQueue(&Q, &i);
				p = GL->adjList[i].firstedge; /*�ҵ���ǰ����ı߱�����ͷָ��*/
				while (p)
				{
					if (!ALvisited[p->adjvex]) /*���˶���δ������*/
					{
						ALvisited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						ALEnQueue(&Q, p->adjvex); /*���˶��������*/
					}
					p = p->next; /*ָ��ָ����һ���ڽӵ�*/
				}
			}
		}
	}
}

/*�ڽӱ���Ⱥ͹�ȱ���DFS_BFS*/
int mainAL_DFS_BFS(void)
{
	MGraph G;
	GraphAdjLlst GL;
	ALCreateMGraph(&G);
	ALCreateALGraph(G, &GL);
	printf("\n��ȱ���:");
	ALDFSTraverse(GL);
	printf("\n��ȱ���:");
	ALBFSTraverse(GL);
	getchar();
}
