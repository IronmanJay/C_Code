#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*哈希表存放各元素出现的次数*/
int map[128];

/*自定义排序规则，如果a和b出现的次数一样把ASCII值小的放到前面，如果出现次数不一样，把出现次数多的字符放到前面*/
int compare_p451_SortCharactersByFrequency(const void *a, const void *b)
{
	char charA = *(char *)a;
	char charB = *(char *)b;
	if (map[charA] == map[charB])
	{
		return charA - charB;
	}
	return map[charB] - map[charA];
}

char * frequencySort(char * s)
{
	/*开辟哈希表空间*/
	memset(map, 0, sizeof(int) * 128);
	/*计算各个元素出现的次数，索引是元素的ASCII码值，索引值是对应元素出现的次数*/
	for (int i = 0; i < strlen(s); i++)
	{
		map[s[i]]++;
	}
	/*对字符串按自定义排序规则排序*/
	qsort(s, strlen(s), sizeof(char), compare_p451_SortCharactersByFrequency);
	/*返回结果*/
	return s;
}

/*主函数省略*/
