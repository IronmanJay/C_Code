#include<stdio.h>

void remove_space01(char* ch)
{
	char str[100] = { 0 };
	char* temp = str;
	int i = 0;
	int j = 0;
	while (ch[i] != '\0')
	{
		if (ch[i] != ' ')
		{
			str[j] = ch[i];
			j++;
		}
		i++;
	}
	while (*ch++ = *temp++);
}

void remove_space02(char* ch)
{
	//±éÀú×Ö·û´®
	char* ftemp = ch;
	//¼ÇÂ¼·Ç¿Õ¸ñ×Ö·û´®
	char* rtemp = ch;
	while (*ftemp)
	{
		if (*ftemp != ' ')
		{
			*rtemp = *ftemp;
			rtemp++;
		}
		ftemp++;
	}
	*rtemp = 0;
}

int main8(void)
{
	char ch[] = "   h e   ll o  w o r  ld";
	remove_space02(ch);
	printf("%s\n", ch);
	getchar();
}