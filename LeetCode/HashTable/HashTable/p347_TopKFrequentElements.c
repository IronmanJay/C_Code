#include<stdio.h>
#include<stdlib.h>
#include<uthash.h>
#include<string.h>

/*定义Hash结构体*/
typedef struct
{
	int num;
	int count;
	UT_hash_handle hh;
}Hash;

/*自定义比较器*/
int Cmp(void *a, void *b)
{
	return ((Hash*)b)->count - ((Hash*)a)->count;
}

/*返回前K个高频元素*/
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
	/*初始化Hash*/
	Hash* map = NULL;
	/*依次遍历每个元素*/
	for (int i = 0; i < numsSize; i++)
	{
		/*在Hash表中查找当前元素*/
		Hash* temp = NULL;
		HASH_FIND_INT(map, &nums[i], temp);
		/*如果找到temp指向那个元素位置的数量+1*/
		if (temp != NULL)
		{
			temp->count++;
		}
		/*如果没找到说明是新的元素，那么就新建一个结构体存储当前元素，次数置为1，插入Hash表中*/
		else
		{
			temp = (Hash*)malloc(sizeof(Hash));
			temp->num = nums[i];
			temp->count = 1;
			HASH_ADD_INT(map, num, temp);
		}
	}
	/*使用自定义比较器进行降序排列*/
	HASH_SORT(map, Cmp);
	/*定义结果数组*/
	int *res = malloc(sizeof(int) * k);
	*returnSize = k;
	/*定义Hash表指针*/
	Hash* finalHash = NULL;
	/*从Hash表中取出前K个元素加入到结果数组中，注意：这里取出的是元素，而不是元素对应的次数*/
	int i;
	for (i = 0, finalHash = map; finalHash != NULL, i < k; finalHash = finalHash->hh.next, i++)
	{
		res[i] = finalHash->num;
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/