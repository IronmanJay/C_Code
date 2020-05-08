#include<stdio.h>

int getstrcount01(char* ch)
{
	int i = 0;
	int count = 0;
	while (ch[i])
	{
		if (ch[i] != ' ')
		{
			count++;
		}
		i++;
	}
	return count;
}

int getstrcount02(char* ch)
{
	int count = 0;
	while (*ch)
	{
		if (*ch != ' ')
		{
			count++;
		}
		ch++;
	}
	return count;
}

int main1(void)
{
	char ch[] = "    hello world";
	int len = getstrcount02(ch);
	printf("%d\n", len);
	getchar();
}

int main2(void)
{
	char ch[] = "helloworldnichoushachounizadizaichouyixiashishi";

	int arr[26] = { 0 };
	for (int i = 0; i < strlen(ch); i++)
	{
		arr[ch[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != 0)
		{
			printf("字母:%c出现次数:%d\n", i + 'a', arr[i]);
		}
	}
	getchar();
}