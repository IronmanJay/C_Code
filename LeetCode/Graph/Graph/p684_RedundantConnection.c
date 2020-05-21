#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

bool is_same;

int findRoot(int *nums, int n)
{
	if (n == nums[n])
	{
		return n;
	}
	nums[n] = findRoot(nums, nums[n]);
	return nums[n];
}

void merge(int *nums, int r1, int r2)
{
	int f1 = findRoot(nums, r1);
	int f2 = findRoot(nums, r2);
	if (f1 == f2)
	{
		is_same = true;
		return f1;
	}
	if (f1 < f2)
	{
		nums[f2] = f1;
	}
	else {
		nums[f1] = f2;
	}
}

int res[2];

/*利用并查集的特点，当出现冗余连接时，连接的两个结点，其根结点相同*/
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
	int max = 0;
	for (int i = 0; i < edgesSize; i++)
	{
		max = MAX(max, edges[i][0]);
		max = MAX(max, edges[i][1]);
	}

	int *nums = (int *)malloc(max + 1, sizeof(int));

	for (int i = 0; i <= max; i++)
	{
		nums[i] = i;
	}

	is_same = false;

	for (int i = 0; i < edgesSize; i++)
	{
		int r1 = edges[i][0];
		int r2 = edges[i][1];
		merge(nums, r1, r2);
		if (is_same == true)
		{
			res[0] = r1;
			res[1] = r2;
			break;
		}
	}
	*returnSize = 2;
	return res;
}

/*主函数省略*/