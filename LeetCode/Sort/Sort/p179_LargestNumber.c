#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

/*�Զ���ȽϺ��������s2+s1>s1+s2���ͷ��ص�qsort��������Ԫ��*/
int cmp(const void *p1, const void *p2)
{
	char a1[MAX * 2 + 1];
	char a2[MAX * 2 + 1];
	sprintf(a1, "%d%d", *(int*)p1, *(int*)p2);
	sprintf(a2, "%d%d", *(int*)p2, *(int*)p1);
	return (strcmp(a2, a1));
}

/*�õ����յ������*/
char * largestNumber(int* nums, int numsSize)
{
	/*���ٽ���ռ�*/
	char *result = malloc(numsSize * MAX + 1);
	memset(result, '\0', numsSize * MAX + 1);
	/*ʹ���Զ���ȽϺ��������忴cmp*/
	qsort(nums, numsSize, sizeof(int), cmp);
	/*����Ƚ�������һ��������0��ֱ�ӷ���*/
	if (nums[0] == 0)
	{
		return "0";
	}
	/*���p��result��ָ�룬����ÿ�α任ָ���λ�ã�������д�뵽��������Ӧ��λ�ã�Ҳ����pָ��ָ��result��λ�ã���ǰ�����Ǽ�λ��+��λ�����ս�int���͵�������䵽�ַ�����*/
	char *p = result;
	for (int i = 0; i < numsSize; i++)
	{
		sprintf(p, "%d", nums[i]);
		p += strlen(p);
	}
	/*���ؽ��*/
	return result;
}

/*������ʡ��*/
