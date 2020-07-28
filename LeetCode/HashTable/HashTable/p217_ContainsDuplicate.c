#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

/*��Hash������Ԫ��*/
int find_hash(int n, int* hash, int size)
{
	/*����HashѰַ����*/
	int location = (n + size / 2) % size;
	/*���Ѱַ��ַС��0��ȡ�෴��*/
	if (location < 0)
	{
		location = -location;
	}
	/*��������ַ����n�����������ַ��Ԫ�أ�˵����ǰԪ�ز���n*/
	while(hash[location] != n && hash[location] != -234567)
	{
		/*��ַ+1*/
		location++;
		/*�����ַ����Hash���ȣ���0*/
		if (location >= size)
		{
			location = 0;
		}
	}
	/*���Ѱַ�ҵ�n������1*/
	if (hash[location] == n)
	{
		return 1;
	}
	/*û�ҵ�����0*/
	return 0;
}

/*��Hash���в���Ԫ��*/
void insert_hash(int n, int* hash, int size)
{
	/*����HashѰַ����*/
	int location = (n + size / 2) % size;
	/*���Ѱַ��ַС��0��ȡ�෴��*/
	if (location < 0)
	{
		location = -location;
	}
	/*��ǰλ�ò�Ϊ�գ�˵����Ԫ��ռ��λ�ã������¼����ң�ֱ���ҵ�һ��û�б�ռ�е�λ��*/
	while (hash[location] != -234567)
	{
		/*��ַ+1*/
		location++;
		/*�����ַ����Hash���ȣ���0*/
		if (location >= size)
		{
			location = 0;
		}
	}
	/*�ߵ�����˵����һ��λ�ÿ��Բ��룬���뼴��*/
	hash[location] = n;
	/*����*/
	return;
}

/*��ʼ��Hash��*/
void init_hash(int* hash, int size)
{
	/*�������飬����ֵΪ-234567����ʾ��ǰλ��û��Ԫ��ռ��*/
	for (int i = 0; i < size; i++)
	{
		hash[i] = -234567;
	}
	/*����*/
	return;
}

/*�����ظ�Ԫ��*/
bool containsDuplicate(int* nums, int numsSize)
{
	/*�������Ϊ�գ�ֱ�ӷ���false*/
	if (numsSize == 0)
	{
		return false;
	}
	/*����Hash����*/
	int hash_size = 5 * numsSize;
	/*��ʼ��Hash����������Ӧ����hash_size����ʱC�������鶨�岻��ʹ�ñ�����������ʱ��10000*/
	int hash[10000];
	init_hash(hash, hash_size);
	/*���α���*/
	for (int i = 0; i < numsSize; i++)
	{
		/*�����Hash�����ҵ���ͬԪ�أ�����true����������Ӧ����hash_size����ʱC�������鶨�岻��ʹ�ñ�����������ʱ��10000*/
		if (find_hash(nums[i], hash, 10000)) {
			return true;
		}
		/*���û�ҵ�������ǰԪ�ز��뵽Hash���У���������Ӧ����hash_size����ʱC�������鶨�岻��ʹ�ñ�����������ʱ��10000*/
		insert_hash(nums[i], hash, 10000);
	}
	/*��������궼û�ҵ��ظ���������false*/
	return false;
}

/*������ʡ��*/
