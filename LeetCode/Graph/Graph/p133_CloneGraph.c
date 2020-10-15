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
	/*因为图是简单无向图，如果原结点存在对应结点，说明此结点已经访问过，这就是跳出递归的条件，避免死循环，说明在这次递归中将图遍历了一遍*/
	if (visited[s->val])
	{
		return visited[s->val];
	}
	/*因为是深拷贝，所以邻居需要挨个添加，而不是直接复制*/
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = s->val;
	newNode->numNeighbors = s->numNeighbors;
	/*此节点克隆之后置为已经访问过*/
	visited[s->val] = newNode;
	newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * newNode->numNeighbors);
	/*加入当前结点的全部邻居结点*/
	for (int i = 0; i < newNode->numNeighbors; i++)
	{
		newNode->neighbors[i] = p133_CloneGraph_DFS(s->neighbors[i], visited);
	}
	/*返回此次递归的结果*/
	return newNode;
}

struct Node *cloneGraph(struct Node *s)
{
	/*判空返回*/
	if (s == NULL)
	{
		return NULL;
	}
	/*哈希表存储原结点的对应结点，判断是否访问过*/
	struct Node** visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
	memset(visited, 0, sizeof(struct Node*) * 101);
	// 开始深度优先搜索，最后返回结果
	return p133_CloneGraph_DFS(s, visited);
}

/*主函数省略*/
