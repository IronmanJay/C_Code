#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<uthash.h>

typedef struct myStruct
{
	char val[21];
	UT_hash_handle hh;
}Node;

Node *map;
char que[20000][21];
int cnt, head, tail;

void Swap(char *a, char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void Enque(char *a)
{
	strcpy(que[head], a);
	head++;
	head %= 20000;
	cnt++;
}

void Deque(char *a)
{
	strcpy(a, que[tail]);
	tail++;
	tail %= 20000;
	cnt--;
}

void ClearHash()
{
	Node *s, *tmp;
	HASH_ITER(hh, map, s, tmp);
	{
		HASH_DEL(map, s);
		free(s);
	}
}

int kSimilarity(char * A, char * B)
{
	if (strcmp(A, B) == 0)
	{
		return 0;
	}
	cnt = 0;
	head = 0;
	tail = 0;
	map = NULL;
	int wordLen = strlen(A);
	char *c = calloc(wordLen + 1, sizeof(char));
	char *c1 = calloc(wordLen + 1, sizeof(char));
	int res = 0;
	Node *s = calloc(1, sizeof(Node));
	strcpy(s->val, A);
	HASH_ADD_STR(map, val, s);
	Enque(A);
	while (cnt > 0)
	{
		int queLen = cnt;
		for (int i = 0; i < queLen; i++)
		{
			Deque(c);
			int k = 0;
			while (c[k] == B[k])
			{
				k++;
			}
			for (int j = k + 1; j < wordLen; j++)
			{
				if (c[j] == B[k])
				{
					strcpy(c1, c);
					Swap(&c1[j], &c1[k]);
				}
				if (strcmp(c1, B) == 0)
				{
					free(c);
					free(c1);
					ClearHash();
					return res + 1;
				}
				HASH_FIND_STR(map, c1, s);
				if (s == NULL)
				{
					s = calloc(1, sizeof(Node));
					strcpy(s->val, c1);
					HASH_ADD_STR(map, val, s);
					Enque(c1);
				}
			}
		}
		res++;
	}
	free(c);
	free(c1);
	ClearHash();
	return 0;
}

/*主函数内容省略，上面的算法是核心*/
