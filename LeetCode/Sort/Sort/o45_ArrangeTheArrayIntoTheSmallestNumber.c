#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int o45_ArrangeTheArrayIntoTheSmallestNumber_compare(void *a, void *b)
{
	/*�½�temp1.temp2�ȴ�ƴ��*/
	char temp1[100] = "";
	char temp2[100] = "";
	/*���������ַ���ȡ�����ȴ�ƴ��*/
	char *s1 = *(char **)a;
	char *s2 = *(char **)b;
	/*��ʼƴ�ӣ����Ȱ�����+��ƴ��*/
	strcat(temp1, s1);
	strcat(temp1, s2);
	/*Ȼ������+��ƴ��*/
	strcat(temp2, s2);
	strcat(temp2, s1);
	/*�������Ϲ����������ǵõ�������ƴ�ӵ���Сֵ���õ������������Сֵ����ʵ�����Ϊ���Ǳ�֤��+��<��+�󼴿�*/
	return atof(temp1) - atof(temp2);
}

char* minNumber(int* nums, int numsSize)
{
	/*�½�һ���ַ�������ԭ����*/
	char** str = (char**)malloc(sizeof(char *)*numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		str[i] = (char *)malloc(sizeof(char) * 20);
		sprintf(str[i], "%d", nums[i]);
	}
	/*�����Զ����������*/
	qsort(str, numsSize, sizeof(char *), o45_ArrangeTheArrayIntoTheSmallestNumber_compare);
	/*����������*/
	char *res = (char *)malloc(sizeof(char) * 5000);
	memset(res, 0, sizeof(res));
	/*���Ѱ���������õ�����ͽ���������ƴ��*/
	for (int i = 0; i < numsSize; i++)
	{
		strcat(res, str[i]);
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
