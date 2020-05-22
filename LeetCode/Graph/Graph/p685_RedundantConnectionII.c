#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_GROUPS_COUNT 1001
int g_groups[MAX_GROUPS_COUNT];

/*初始化并查集数组*/
void InitGroups()
{
	for (size_t i = 0; i < MAX_GROUPS_COUNT; i++)
	{
		g_groups[i] = i;
	}
}

/*寻找父节点*/
int Find(int id)
{
	if (id == g_groups[id])
	{
		return id;
	}
	return g_groups[id] = Find(g_groups[id]);
}

/*算法主程序*/
int *findRedundantDirectedConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
	/*不合法参数*/
	if (edges == NULL || edgesColSize == NULL || returnSize == NULL)
	{
		return NULL;
	}
	/*定义结果数组*/
	int *result = (int *)malloc(sizeof(int) * 2);
	if (result == NULL)
	{
		return NULL;
	}
	/*初始化并查集*/
	InitGroups();
	int twoDegreeUv[2][2];
	int removeFirst = 0;
	int twoDegreeV = MAX_GROUPS_COUNT;
	int degrees[MAX_GROUPS_COUNT] = { 0 };
	int u, v, uGroupId, vGroupId;
	/*寻找2度结点*/
	for (int i = 0; i < edgesSize; i++)
	{
		u = edges[i][0];
		v = edges[i][1];
		degrees[v] += 1;
		if (degrees[v] == 2) {
			twoDegreeV = v;
			break;
		}
	}
	int saveDegreeCount = 0;
	for (int i = 0; i < edgesSize; i++)
	{
		u = edges[i][0];
		v = edges[i][1];
		if (v == twoDegreeV)
		{
			twoDegreeUv[saveDegreeCount][0] = u;
			twoDegreeUv[saveDegreeCount][1] = v;
			saveDegreeCount += 1;
		}
		if (v == twoDegreeV && saveDegreeCount == 2)
		{
			/*跳过第二组，检查是否有异常*/
			continue;
		}
		uGroupId = Find(u);
		vGroupId = Find(v);
		if (uGroupId == vGroupId)
		{
			removeFirst = 1;
			if (twoDegreeV != MAX_GROUPS_COUNT)
			{
				/*未删除第一组有问题，说明应该删除第一组*/
			}
			else
			{
				twoDegreeUv[0][0] = u;
				twoDegreeUv[0][1] = v;
				break;
			}
		}
		g_groups[vGroupId] = uGroupId;
	}
	if (removeFirst)
	{
		result[0] = twoDegreeUv[0][0];
		result[1] = twoDegreeUv[0][1];
	}
	else
	{
		result[0] = twoDegreeUv[1][0];
		result[1] = twoDegreeUv[1][1];
	}
	*returnSize = 2;
	return result;
}

/*主函数省略*/