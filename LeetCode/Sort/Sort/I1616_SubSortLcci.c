#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�Զ�������*/
int I1616_SubSortLcci_compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int* subSort(int* array, int arraySize, int* returnSize)
{
	/*����һ�����飬���ں����Ƚ�*/
	int* temp = (int *)malloc(sizeof(int) * arraySize);
	memcpy(temp, array, sizeof(int) * arraySize);
	/*��ԭ�����������*/
	qsort(array, arraySize, sizeof(int), I1616_SubSortLcci_compare);
	/*����������*/
	int* res = (int *)malloc(sizeof(int) * 2);
	res[0] = -1;
	res[1] = -1;
	/*��ʼ�����Աȶ�Ӧλ�õ�Ԫ��*/
	for (int i = 0; i < arraySize; i++)
	{
		/*ֻ��ԭ����͸��Ƶ����鲻��Ӧ��λ�þ��Ƿ�������ı��λ��*/
		if (temp[i] != array[i])
		{
			/*��һ�������Ĳ���Ӧ��λ�þ��ǿ�ʼλ��*/
			if (res[0] == -1)
			{
				res[0] = i;
			}
			/*�ڶ��������Ĳ���Ӧ��λ�þ��ǽ���λ��*/
			res[1] = i;
		}
	}
	/*���ؽ��*/
	*returnSize = 2;
	return res;
}