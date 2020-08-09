#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * intToRoman(int num)
{
	// 开辟结果数组空间
	char *res = (char *)malloc(20 * sizeof(char));
	// 罗马数字对应的数字值
	int value[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	// 数字对应罗马数字的值
	char str[13][3] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
	// 一共十三个对应关系，循环十三遍
	for (int i = 0; i < 13; i++)
	{
		// 当while循环继续的时候，说明当前位有值
		while (num >= value[i])
		{
			// 当前数字减去这一位
			num -= value[i];
			// 结果数组加上这一位对应的罗马数字
			strcat(res, str[i]);
		}
	}
	// 返回结果
	return res;
}