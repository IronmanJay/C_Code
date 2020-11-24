#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*��ϣ���Ÿ�Ԫ�س��ֵĴ���*/
int map[128];

/*�Զ�������������a��b���ֵĴ���һ����ASCIIֵС�ķŵ�ǰ�棬������ִ�����һ�����ѳ��ִ�������ַ��ŵ�ǰ��*/
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
	/*���ٹ�ϣ��ռ�*/
	memset(map, 0, sizeof(int) * 128);
	/*�������Ԫ�س��ֵĴ�����������Ԫ�ص�ASCII��ֵ������ֵ�Ƕ�ӦԪ�س��ֵĴ���*/
	for (int i = 0; i < strlen(s); i++)
	{
		map[s[i]]++;
	}
	/*���ַ������Զ��������������*/
	qsort(s, strlen(s), sizeof(char), compare_p451_SortCharactersByFrequency);
	/*���ؽ��*/
	return s;
}

/*������ʡ��*/
