#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /*��󶥵�����Ӧ���û�����*/

typedef int Status; /*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
typedef char VertexType; /*�����������û�����*/
typedef int EdgeType; /*���ϵ�Ȩֵ����Ӧ���û�����*/

/*�߱����*/
typedef struct EdgeNode
{
	int adjvex; /*�ڽӵ��򣬴洢�ö����Ӧ���±�*/
	EdgeType info; /*���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ*/
	struct EdgeNode *next; /*��������ָ����һ�����*/
}EdgeNode;

/*��������*/
typedef struct VertexNode
{
	VertexType data; /*�����򣬴洢������Ϣ*/
	EdgeNode *firstedge; /*�߱�ͷָ��*/
}VertextNode, AdjList[MAXVEX];


typedef struct
{
	AdjList adjList;
	int numNodes, numEdges; /*ͼ�е�ǰ�������ͱ���*/
}GraphAdjList;

/*����ͼ���ڽӱ��ṹ������ͼ��*/
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("���붥�����ͱ���:\n");
	scanf_s("%d,%d", &G->numNodes, &G->numEdges); /*���붥�����ͱ���*/
	for (i = 0; i < G->numNodes; i++) /*���붥����Ϣ�����������*/
	{
		scanf_s(&G->adjList[i].data); /*���붥����Ϣ*/
		G->adjList[i].firstedge = NULL; /*���߱���Ϊ�ձ�*/
	}
	for (k = 0; k < G->numEdges; k++) /*�����߱�*/
	{
		printf("�����(vi,vj)�ϵĶ������:\n");
		scanf_s("%d,%d", &i, &j); /*����ߣ�vi��vj���ϵĶ������*/
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ䣬���ɱ߱����*/
		e->adjvex = j; /*�ڽ����Ϊj*/
		e->next = G->adjList[i].firstedge; /*��e��ָ��ָ��ǰ������ָ��Ľ��*/
		G->adjList[i].firstedge = e; /*����ǰ�����ָ��ָ��e*/

		e = (EdgeNode *)malloc(sizeof(EdgeNode)); /*���ڴ�����ռ䣬���ɱ߱����*/
		e->adjvex = i; /*�ڽ����Ϊi*/
		e->next = G->adjList[j].firstedge; /*��e��ָ��ָ��ǰ������ָ��Ľ��*/
		G->adjList[j].firstedge = e; /*����ǰ�����ָ��ָ��e*/
	}

}

/*�ڽӱ�����*/
int mainCreateALGraph(void)
{
	GraphAdjList G;
	CreateALGraph(&G);
	getchar();

}