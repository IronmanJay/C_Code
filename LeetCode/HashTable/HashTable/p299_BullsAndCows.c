#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define min(a,b) ((a) > (b) ? (b) : (a))

char * getHint(char * secret, char * guess)
{
	int s[10] = { 0 };
	int g[10] = { 0 };
	int A = 0;
	int B = 0;
	for (int i = 0; i < strlen(guess); i++)
	{
		if (secret[i] == guess[i])
		{
			A++;
		}
		else
		{
			s[secret[i] - '0']++;
			g[guess[i] - '0']++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		B += min(s[i], g[i]);
	}
	char* res = (char*)malloc(sizeof(char) * 10);
	sprintf(res, "%dA%dB", A, B);
	return res;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/