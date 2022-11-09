#include<stdio.h>
#include<math.h>

int minCostToMoveChips(int* position, int positionSize)
{
	int even = 0;
	int odd = 0;
	for (int i = 0; i < positionSize; i++)
	{
		if (position[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	return fmin(even, odd);
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/