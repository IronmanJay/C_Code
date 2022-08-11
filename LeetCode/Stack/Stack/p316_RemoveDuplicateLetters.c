#include<stdio.h>

char * removeDuplicateLetters(char * s)
{
	int len = strlen(s);
	char* res = (char *)malloc(sizeof(char) * 27);
	int index = 0;
	int hash[26] = { 0 };
	int visied[26] = { 0 };
	for (int i = 0; i < len; i++)
	{
		hash[s[i] - 'a']++;
	}
	for (int i = 0; i < len; i++)
	{
		if (!visied[s[i] - 'a'])
		{
			while ((index > 0) && (res[index - 1] > s[i]) && (hash[res[index - 1] - 'a'] >= 1))
			{
				visied[res[--index] - 'a'] = 0;
			}
			visied[s[i] - 'a'] = 1;
			res[index++] = s[i];
		}
		hash[s[i] - 'a']--;
	}
	res[index] = '\0';
	return res;
}

/*Ö÷º¯ÊıÊ¡ÂÔ*/