#include<stdio.h>
#include<stdlib.h>
#include<uthash.h>
#include<string.h>

/*����Hash�ṹ��*/
typedef struct
{
	int num;
	int count;
	UT_hash_handle hh;
}Hash;

/*�Զ���Ƚ���*/
int Cmp(void *a, void *b)
{
	return ((Hash*)b)->count - ((Hash*)a)->count;
}

/*����ǰK����ƵԪ��*/
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
	/*��ʼ��Hash*/
	Hash* map = NULL;
	/*���α���ÿ��Ԫ��*/
	for (int i = 0; i < numsSize; i++)
	{
		/*��Hash���в��ҵ�ǰԪ��*/
		Hash* temp = NULL;
		HASH_FIND_INT(map, &nums[i], temp);
		/*����ҵ�tempָ���Ǹ�Ԫ��λ�õ�����+1*/
		if (temp != NULL)
		{
			temp->count++;
		}
		/*���û�ҵ�˵�����µ�Ԫ�أ���ô���½�һ���ṹ��洢��ǰԪ�أ�������Ϊ1������Hash����*/
		else
		{
			temp = (Hash*)malloc(sizeof(Hash));
			temp->num = nums[i];
			temp->count = 1;
			HASH_ADD_INT(map, num, temp);
		}
	}
	/*ʹ���Զ���Ƚ������н�������*/
	HASH_SORT(map, Cmp);
	/*����������*/
	int *res = malloc(sizeof(int) * k);
	*returnSize = k;
	/*����Hash��ָ��*/
	Hash* finalHash = NULL;
	/*��Hash����ȡ��ǰK��Ԫ�ؼ��뵽��������У�ע�⣺����ȡ������Ԫ�أ�������Ԫ�ض�Ӧ�Ĵ���*/
	int i;
	for (i = 0, finalHash = map; finalHash != NULL, i < k; finalHash = finalHash->hh.next, i++)
	{
		res[i] = finalHash->num;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/