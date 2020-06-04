#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/
typedef int Boolean; /*Boolean�ǲ�������,��ֵ��TRUE��FALSE*/
typedef char VertexType; /*��������Ӧ���û�����*/
typedef int EdgeType; /*���ϵ�Ȩֵ����Ӧ���û�����*/

#define MAXSIZE 9 /*�洢�ռ��ʼ������*/
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

/*�ڽӾ���ṹ*/
typedef struct
{
	VertexType vexs[MAXVEX]; /*�����*/
	EdgeType arc[MAXVEX][MAXVEX]; /*�ڽӾ��󣬿ɿ����߱�*/
	int numVertexes, numEdges; /*ͼ�е�ǰ�Ķ������ͱ���*/
}MGraph;

/*ѭ�����е�˳��洢�ṹ*/
typedef struct
{
	int data[MAXSIZE];
	int front; /*ͷָ��*/
	int rear; /*βָ�룬�����в�Ϊ�գ�ָ�����βԪ�ص���һ��λ��*/
}Queue;

/*��ʼ��һ���ն���Q*/
Status MInitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return  OK;
}

/*������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE*/
Status MQueueEmpty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return TRUE; /*���пյı�־*/
	}
	else
	{
		return FALSE;
	}
}

/*������δ���������Ԫ��eΪQ�µĶ�βԪ��*/
Status MEnQueue(Queue *Q, int e)
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
Status MDeQueue(Queue *Q, int *e)
{
	if (Q->front == Q->rear) /*���пյ��ж�*/
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; /*����ͷԪ�ظ�ֵ��e*/
	Q->front = (Q->front + 1) % MAXSIZE; /*frontָ�������һλ�ã����������ת������ͷ��*/
	return OK;
}

/*����ͼ*/
void MCreateMGraph(MGraph *G)
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
	/*��Ϊ������ͼ����Ҫ����˫��Ĺ�ϵ*/
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

Boolean Mvisited[MAXVEX];

/*�ڽӾ����������ȵݹ��㷨*/
void MDFS(MGraph G, int i)
{
	int j;
	Mvisited[i] = FALSE;
	printf("%c ", G.vexs[i]); /*��ӡ���㣬Ҳ������������*/
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && Mvisited[j])
		{
			MDFS(G, j); /*��δ���ʵ��ڽӶ���ݹ����*/
		}
	}
}

/*�ڽӾ������ȱ�������*/
void MDFSTraverse(MGraph G)
{
	int i;
	/*��ʼ���Զ���״̬����δ���ʹ�״̬*/
	for (i = 0; i < G.numVertexes; i++)
	{
		Mvisited[i] = FALSE;
	}
	/*��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ��*/
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!Mvisited[i])
		{
			MDFS(G, i);
		}
	}
}

/*�ڽӾ���Ĺ�ȱ����㷨*/
void MBFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexes; i++)
	{
		Mvisited[i] = FALSE;
	}
	/*��ʼ��һ�����õĶ���*/
	MInitQueue(&Q);
	/*��ÿһ��������ѭ��*/
	for (i = 0; i < G.numVertexes; i++)
	{
		/*����δ���ʹ��ľʹ���*/
		if (!Mvisited[i])
		{
			Mvisited[i] = TRUE; /*���õ�ǰ������ʹ�*/
			printf("%c ", G.vexs[i]); /*��ӡ���㣬Ҳ������������*/
			MEnQueue(&Q, i); /*���˶��������*/
			while (!MQueueEmpty(Q)) /*����ǰ���в�Ϊ��*/
			{
				MDeQueue(&Q, &i); /*����ͷԪ�س����У���ֵ��i*/
				for (j = 0; j < G.numVertexes; j++)
				{
					/*�ж������������뵱ǰ������ڱ���δ���ʹ�*/
					if (G.arc[i][j] == 1 && !Mvisited[j])
					{
						Mvisited[j] = TRUE; /*���ҵ��Ĵ˶�����Ϊ�ѷ���*/
						printf("%c ", G.vexs[j]); /*��ӡ����*/
						MEnQueue(&Q, j); /*���ҵ��Ĵ˶��������*/
					}
				}
			}
		}
	}
}

/*�ڽӾ�����Ⱥ͹�����ȱ���*/
int mainM_BFS_DFS(void)
{
	MGraph G;
	MCreateMGraph(&G);
	printf("\n��ȱ�����");
	MDFSTraverse(G);
	printf("\n��ȱ�����");
	MBFSTraverse(G);
	getchar();
}
