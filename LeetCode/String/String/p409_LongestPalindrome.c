#include<stdio.h>
#include<stdbool.h>

int longestPalindrome(char * s)
{
	int map[128] = { 0 };
	for (int i = 0; i < strlen(s); i++)
	{
		map[s[i]]++;
	}
	int res = 0;
	bool flag = false;
	for (int i = 0; i < 128; i++)
	{
		if (map[i] % 2 == 0)
		{
			res += map[i];
		}
		else
		{
			res = res + map[i] - 1;
			flag = true;
		}
	}
	return flag == false ? res : res + 1;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/