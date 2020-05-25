#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool detectCapitalUse(char * word)
{
	/*大写字母数量*/
	int upWord = 0;
	/*小写字母数量*/
	int lowWord = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] - 'a' < 0)
		{
			upWord++;
		}
		else
		{
			lowWord++;
		}
	}
	/*如果全是大写字母或者全是小写字母或者首字母大写其余全为小写字母，符合要求，返回true*/
	if (upWord == strlen(word) || lowWord == strlen(word) || (upWord == 1 && word[0] < 'a'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	/*主函数省略*/
}