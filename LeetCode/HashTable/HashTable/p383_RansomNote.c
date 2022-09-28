#include<stdio.h>
#include<stdbool.h>

bool canConstruct(char * ransomNote, char * magazine)
{
	int lenA = strlen(ransomNote);
	int lenB = strlen(magazine);
	int map[26] = { 0 };
	for (int i = 0; i < lenA; i++)
	{
		map[ransomNote[i] - 'a']++;
	}
	for (int i = 0; i < lenB; i++)
	{
		map[magazine[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (map[i] > 0)
		{
			return false;
		}
	}
	return true;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/