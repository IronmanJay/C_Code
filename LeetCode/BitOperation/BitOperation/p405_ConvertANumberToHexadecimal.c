#include<stdio.h>

char * toHex(int num)
{
	if (num == 0)
	{
		return "0";
	}
	char map[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	char* res = (char*)calloc(9, sizeof(char));
	for (int i = 7; i >= 0; i--)
	{
		int temp = num & 0xf;
		res[i] = map[temp];
		num >>= 4;
	}
	res[8] = '\0';
	while (res[0] == '0')
	{
		res++;
	}
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/