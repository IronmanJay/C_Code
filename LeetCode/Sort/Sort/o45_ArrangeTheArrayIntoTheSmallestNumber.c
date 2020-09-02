#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int o45_ArrangeTheArrayIntoTheSmallestNumber_compare(void *a, void *b)
{
	/*新建temp1.temp2等待拼接*/
	char temp1[100] = "";
	char temp2[100] = "";
	/*将这两个字符串取出，等待拼接*/
	char *s1 = *(char **)a;
	char *s2 = *(char **)b;
	/*开始拼接，首先按照左+右拼接*/
	strcat(temp1, s1);
	strcat(temp1, s2);
	/*然后按照右+左拼接*/
	strcat(temp2, s2);
	strcat(temp2, s1);
	/*按照以上规则排序总是得到两个数拼接的最小值即得到整个数组的最小值，其实我理解为就是保证左+右<右+左即可*/
	return atof(temp1) - atof(temp2);
}

char* minNumber(int* nums, int numsSize)
{
	/*新建一个字符数组存放原数组*/
	char** str = (char**)malloc(sizeof(char *)*numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		str[i] = (char *)malloc(sizeof(char) * 20);
		sprintf(str[i], "%d", nums[i]);
	}
	/*进行自定义快速排序*/
	qsort(str, numsSize, sizeof(char *), o45_ArrangeTheArrayIntoTheSmallestNumber_compare);
	/*定义结果数组*/
	char *res = (char *)malloc(sizeof(char) * 5000);
	memset(res, 0, sizeof(res));
	/*对已按规则排序好的数组和结果数组进行拼接*/
	for (int i = 0; i < numsSize; i++)
	{
		strcat(res, str[i]);
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
