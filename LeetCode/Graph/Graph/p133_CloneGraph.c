#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int val;
	int numNeighbors;
	struct Node** neighbors;
};

struct Node* p133_CloneGraph_DFS(struct Node *s, struct Node** visited)
{
	/*��Ϊͼ�Ǽ�����ͼ�����ԭ�����ڶ�Ӧ��㣬˵���˽���Ѿ����ʹ�������������ݹ��������������ѭ����˵������εݹ��н�ͼ������һ��*/
	if (visited[s->val])
	{
		return visited[s->val];
	}
	/*��Ϊ������������ھ���Ҫ������ӣ�������ֱ�Ӹ���*/
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = s->val;
	newNode->numNeighbors = s->numNeighbors;
	/*�˽ڵ��¡֮����Ϊ�Ѿ����ʹ�*/
	visited[s->val] = newNode;
	newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * newNode->numNeighbors);
	/*���뵱ǰ����ȫ���ھӽ��*/
	for (int i = 0; i < newNode->numNeighbors; i++)
	{
		newNode->neighbors[i] = p133_CloneGraph_DFS(s->neighbors[i], visited);
	}
	/*���ش˴εݹ�Ľ��*/
	return newNode;
}

struct Node *cloneGraph(struct Node *s)
{
	/*�пշ���*/
	if (s == NULL)
	{
		return NULL;
	}
	/*��ϣ��洢ԭ���Ķ�Ӧ��㣬�ж��Ƿ���ʹ�*/
	struct Node** visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
	memset(visited, 0, sizeof(struct Node*) * 101);
	// ��ʼ���������������󷵻ؽ��
	return p133_CloneGraph_DFS(s, visited);
}

/*������ʡ��*/
