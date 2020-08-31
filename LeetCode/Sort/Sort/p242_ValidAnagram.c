#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*自定义排序规则，从小到大排序*/
int p242_ValidAnagram_cmp(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}

bool isAnagram(char * s, char * t)
{
	/*如果长度不相等，或者有一个字符串为空，说明不是有效的字母异位词，返回false即可*/
	if (strlen(s) != strlen(t) || !s || !t)
	{
		return false;
	}
	/*使用C语言qsort自定义排序进行排序*/
	qsort(s, strlen(s), sizeof(char), p242_ValidAnagram_cmp);
	qsort(t, strlen(t), sizeof(char), p242_ValidAnagram_cmp);
	/*如果排序之后两个字符数组相等，说明是有效的字母异位词，如果排序之后不相等，也就意味着两个字符串包含的字母不相同，说明并不是有效的字母异位词*/
	return strcmp(s, t) == 0;
}

/*主函数省略*/
