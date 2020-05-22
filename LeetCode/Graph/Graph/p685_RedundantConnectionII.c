#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_GROUPS_COUNT 1001
int g_groups[MAX_GROUPS_COUNT];

/*��ʼ�����鼯����*/
void InitGroups()
{
	for (size_t i = 0; i < MAX_GROUPS_COUNT; i++)
	{
		g_groups[i] = i;
	}
}

/*Ѱ�Ҹ��ڵ�*/
int Find(int id)
{
	if (id == g_groups[id])
	{
		return id;
	}
	return g_groups[id] = Find(g_groups[id]);
}

/*�㷨������*/
int *findRedundantDirectedConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
	/*���Ϸ�����*/
	if (edges == NULL || edgesColSize == NULL || returnSize == NULL)
	{
		return NULL;
	}
	/*����������*/
	int *result = (int *)malloc(sizeof(int) * 2);
	if (result == NULL)
	{
		return NULL;
	}
	/*��ʼ�����鼯*/
	InitGroups();
	int twoDegreeUv[2][2];
	int removeFirst = 0;
	int twoDegreeV = MAX_GROUPS_COUNT;
	int degrees[MAX_GROUPS_COUNT] = { 0 };
	int u, v, uGroupId, vGroupId;
	/*Ѱ��2�Ƚ��*/
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
			/*�����ڶ��飬����Ƿ����쳣*/
			continue;
		}
		uGroupId = Find(u);
		vGroupId = Find(v);
		if (uGroupId == vGroupId)
		{
			removeFirst = 1;
			if (twoDegreeV != MAX_GROUPS_COUNT)
			{
				/*δɾ����һ�������⣬˵��Ӧ��ɾ����һ��*/
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

/*������ʡ��*/