#include<stdio.h>
#include<limits.h>

int compare_p646_MaximumLengthOfPairChain(const void **a, const void **b)
{
	return (*(int**)a)[1] - (*(int**)b)[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize)
{
	qsort(pairs, pairsSize, sizeof(int*), compare_p646_MaximumLengthOfPairChain);
	int cur = INT_MIN;
	int res = 0;
	for (int i = 0; i < pairsSize; i++)
	{
		if (cur < pairs[i][0])
		{
			cur = pairs[i][1];
			res++;
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/