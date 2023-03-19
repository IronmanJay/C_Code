#include<stdio.h>
#include<string.h>

int compareVersion(char * version1, char * version2)
{
	int len1 = strlen(version1);
	int len2 = strlen(version2);
	int index1 = 0;
	int index2 = 0;
	while (index1 < len1 || index2 < len2)
	{
		long x = 0;
		while (index1 < len1 && version1[index1] != '.')
		{
			x = x * 10 + version1[index1] - '0';
			index1++;
		}
		index1++;
		long y = 0;
		while (index2 < len2 && version2[index2] != '.')
		{
			y = y * 10 + version2[index2] - '0';
			index2++;
		}
		index2++;
		if (x != y)
		{
			return x > y ? 1 : -1;
		}
	}
	return 0;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/