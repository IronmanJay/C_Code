#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int p242_ValidAnagram_cmp(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}

bool isAnagram(char * s, char * t)
{
	if (strlen(s) != strlen(t) || !s || !t)
	{
		return false;
	}
	qsort(s, strlen(s), sizeof(char), p242_ValidAnagram_cmp);
	qsort(t, strlen(t), sizeof(char), p242_ValidAnagram_cmp);
	return strcmp(s, t) == 0;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/
