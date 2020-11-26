#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<uthash.h>

/*��ϣ��ṹ��key���Ԫ��ֵ��value���Ԫ����list�е�����*/
typedef struct
{
	int key;
	int value;
	UT_hash_handle hh;
}HashMap;

/*������ϣ���list�ṹ��list��������Ԫ�أ�listLen������ĳ���*/
typedef struct
{
	HashMap* map;
	int* list;
	int listLen;
} RandomizedSet;

/*��ʼ��*/
RandomizedSet* randomizedSetCreate()
{
	RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
	obj->map = NULL;
	obj->list = (int *)malloc(sizeof(int) * 65535);
	obj->listLen = 0;
	return obj;
}

/*����Ԫ��*/
bool randomizedSetInsert(RandomizedSet* obj, int val)
{
	/*׼�����뵽��ϣ���е�Ԫ��*/
	HashMap* mapCur = NULL;
	/*�ҵ�ǰԪ��ֵ�Ƿ�����ڹ�ϣ����*/
	HASH_FIND_INT(obj->map, &val, mapCur);
	if (mapCur == NULL)
	{
		/*�����¿ռ�*/
		mapCur = (HashMap*)malloc(sizeof(HashMap));
		/*key���Ԫ��ֵ*/
		mapCur->key = val;
		/*value���Ԫ����list�е�����*/
		mapCur->value = obj->listLen;
		/*���µļ�ֵ�Բ��뵽��ϣ����*/
		HASH_ADD_INT(obj->map, key, mapCur);
		/*��Ԫ�ز��뵽list��*/
		obj->list[obj->listLen++] = val;
		/*����ɹ�����true*/
		return true;
	}
	/*������ڷ���false*/
	return false;
}

/*ɾ��Ԫ��*/
bool randomizedSetRemove(RandomizedSet* obj, int val)
{
	/*����ڹ�ϣ�����ҵ��Ķ�ӦԪ��*/
	HashMap* mapCur = NULL;
	/*�������޸�listβԪ���ڹ�ϣ���еĶ�Ӧlist�е�����*/
	HashMap* temp = NULL;
	/*�жϵ�ǰԪ���Ƿ��ڹ�ϣ����*/
	HASH_FIND_INT(obj->map, &val, mapCur);
	if (mapCur != NULL)
	{
		/*�ҵ�βԪ���ڹ�ϣ���ж�Ӧ��list����*/
		HASH_FIND_INT(obj->map, &obj->list[obj->listLen - 1], temp);
		/*�޸�βԪ����list�е�����Ϊ��ɾ�������list�е�����*/
		temp->value = mapCur->value;
		/*ɾ���ڹ�ϣ���еĴ�ɾ�����*/
		HASH_DEL(obj->map, mapCur);
		/*��list�е�βԪ�����ɾ��Ԫ��λ�ý�������ʱlist�е�βԪ�ؾ��Ǵ�ɾ����㣬ֱ��ɾ�����ɣ����鳤��-1��ʱ�临�Ӷ�O(1)*/
		obj->list[mapCur->value] = obj->list[--obj->listLen];
		/*ɾ���ɹ�����true*/
		return true;
	}
	/*������ڷ���false*/
	return false;
}

/*�������Ԫ��*/
int randomizedSetGetRandom(RandomizedSet* obj)
{
	return obj->list[rand() % obj->listLen];
}

/*�ͷſռ�*/
void randomizedSetFree(RandomizedSet* obj)
{
	HashMap* mapCur = NULL;
	HashMap* temp = NULL;
	free(obj->list);
	HASH_ITER(hh, obj->map, mapCur, temp)
	{
		HASH_DEL(obj->map, mapCur);
		free(mapCur);
	}
	free(obj);
}

/*������ʡ��*/
