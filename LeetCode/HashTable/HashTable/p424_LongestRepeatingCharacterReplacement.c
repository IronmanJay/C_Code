#include<stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int characterReplacement(char * s, int k)
{
	int len = strlen(s);
	int map[26] = { 0 };
	int left = 0;
	int right = 0;
	int maxSame = 0;
	while (right < len)
	{
		int index = s[right] - 'A';
		map[index]++;
		maxSame = max(maxSame, map[index]);
		int windowsLen = right - left + 1;
		if (windowsLen - maxSame > k)
		{
			map[s[left] - 'A']--;
			left++;
		}
		right++;
	}
	return right - left;
}

/*Ö÷º¯ÊýÊ¡ÂÔ*/