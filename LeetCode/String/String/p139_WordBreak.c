#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

unsigned long long Hash(char* s, int l, int r)
{
	unsigned long long value = 0;
	for (int i = l; i < r; i++)
	{
		value = value * 2333ull;
		value += s[i] - 'a' + 1;
	}
	return value;
}

bool query(unsigned long long *rec, int recLen, unsigned long long x)
{
	for (int i = 0; i < recLen; i++)
	{
		if (rec[i] == x)
		{
			return true;
		}
	}
	return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize)
{
	unsigned long long* rec = (unsigned long long*)malloc(sizeof(unsigned long long) * wordDictSize);
	for (int i = 0; i < wordDictSize; i++)
	{
		rec[i] = Hash(wordDict[i], 0, strlen(wordDict[i]));
	}
	int lenS = strlen(s);
	bool *dp = (bool *)calloc(lenS + 1, sizeof(bool));
	dp[0] = true;
	for (int i = 1; i <= lenS; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp[j] && query(rec, wordDictSize, Hash(s, j, i)))
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[lenS];
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/