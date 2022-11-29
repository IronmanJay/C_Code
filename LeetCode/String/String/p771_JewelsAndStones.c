#include<stdio.h>
#include<stdlib.h>

int numJewelsInStones(char * jewels, char * stones)
{
	int* countSmall = (int*)calloc(27, sizeof(int));
	int* countBig = (int*)calloc(27, sizeof(int));
	for (int i = 0; i < strlen(stones); i++)
	{
		char c = stones[i];
		if (c >= 'a' && c <= 'z')
		{
			countSmall[c - 'a']++;
		}
		else
		{
			countBig[c - 'A']++;
		}
	}
	int res = 0;
	for (int i = 0; i < strlen(jewels); i++)
	{
		char c = jewels[i];
		if (c >= 'a' && c <= 'z')
		{
			res += countSmall[c - 'a'];
		}
		else
		{
			res += countBig[c - 'A'];
		}
	}
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/