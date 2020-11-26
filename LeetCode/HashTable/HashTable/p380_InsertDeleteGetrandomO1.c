#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<uthash.h>

/*哈希表结构，key存放元素值，value存放元素在list中的索引*/
typedef struct
{
	int key;
	int value;
	UT_hash_handle hh;
}HashMap;

/*辅助哈希表和list结构，list是数组存放元素，listLen是数组的长度*/
typedef struct
{
	HashMap* map;
	int* list;
	int listLen;
} RandomizedSet;

/*初始化*/
RandomizedSet* randomizedSetCreate()
{
	RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
	obj->map = NULL;
	obj->list = (int *)malloc(sizeof(int) * 65535);
	obj->listLen = 0;
	return obj;
}

/*插入元素*/
bool randomizedSetInsert(RandomizedSet* obj, int val)
{
	/*准备插入到哈希表中的元素*/
	HashMap* mapCur = NULL;
	/*找当前元素值是否存在于哈希表中*/
	HASH_FIND_INT(obj->map, &val, mapCur);
	if (mapCur == NULL)
	{
		/*开辟新空间*/
		mapCur = (HashMap*)malloc(sizeof(HashMap));
		/*key存放元素值*/
		mapCur->key = val;
		/*value存放元素在list中的索引*/
		mapCur->value = obj->listLen;
		/*将新的键值对插入到哈希表中*/
		HASH_ADD_INT(obj->map, key, mapCur);
		/*将元素插入到list中*/
		obj->list[obj->listLen++] = val;
		/*插入成功返回true*/
		return true;
	}
	/*如果存在返回false*/
	return false;
}

/*删除元素*/
bool randomizedSetRemove(RandomizedSet* obj, int val)
{
	/*存放在哈希表中找到的对应元素*/
	HashMap* mapCur = NULL;
	/*作用是修改list尾元素在哈希表中的对应list中的索引*/
	HashMap* temp = NULL;
	/*判断当前元素是否在哈希表中*/
	HASH_FIND_INT(obj->map, &val, mapCur);
	if (mapCur != NULL)
	{
		/*找到尾元素在哈希表中对应的list索引*/
		HASH_FIND_INT(obj->map, &obj->list[obj->listLen - 1], temp);
		/*修改尾元素在list中的索引为待删除结点在list中的索引*/
		temp->value = mapCur->value;
		/*删除在哈希表中的待删除结点*/
		HASH_DEL(obj->map, mapCur);
		/*将list中的尾元素与带删除元素位置交换，此时list中的尾元素就是待删除结点，直接删除即可，数组长度-1，时间复杂度O(1)*/
		obj->list[mapCur->value] = obj->list[--obj->listLen];
		/*删除成功返回true*/
		return true;
	}
	/*如果不在返回false*/
	return false;
}

/*返回随机元素*/
int randomizedSetGetRandom(RandomizedSet* obj)
{
	return obj->list[rand() % obj->listLen];
}

/*释放空间*/
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

/*主函数省略*/
