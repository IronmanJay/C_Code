#include<stdio.h>
#include<math.h>

int compare(const void *a, const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return *pa - *pb;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize)
{
	qsort(houses, housesSize, sizeof(int), compare);
	qsort(heaters, heatersSize, sizeof(int), compare);
	int res = 0;
	for (int i = 0, j = 0; i < housesSize; i++)
	{
		int curDis = fabs(houses[i] - heaters[j]);
		while (j < heatersSize - 1 && fabs(houses[i] - heaters[j]) >= fabs(houses[i] - heaters[j + 1]))
		{
			j++;
			curDis = fabs(houses[i] - heaters[j]);
		}
		res = fmax(res, curDis);
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/