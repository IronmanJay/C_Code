#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

/*从Hash表中找元素*/
int find_hash(int n, int* hash, int size)
{
	/*定义Hash寻址规则*/
	int location = (n + size / 2) % size;
	/*如果寻址地址小于0，取相反数*/
	if (location < 0)
	{
		location = -location;
	}
	/*如果这个地址不是n，并且这个地址有元素，说明当前元素不是n*/
	while(hash[location] != n && hash[location] != -234567)
	{
		/*地址+1*/
		location++;
		/*如果地址超过Hash表长度，置0*/
		if (location >= size)
		{
			location = 0;
		}
	}
	/*如果寻址找到n，返回1*/
	if (hash[location] == n)
	{
		return 1;
	}
	/*没找到返回0*/
	return 0;
}

/*向Hash表中插入元素*/
void insert_hash(int n, int* hash, int size)
{
	/*定义Hash寻址规则*/
	int location = (n + size / 2) % size;
	/*如果寻址地址小于0，取相反数*/
	if (location < 0)
	{
		location = -location;
	}
	/*当前位置不为空，说明有元素占有位置，则向下继续找，直到找到一个没有被占有的位置*/
	while (hash[location] != -234567)
	{
		/*地址+1*/
		location++;
		/*如果地址超过Hash表长度，置0*/
		if (location >= size)
		{
			location = 0;
		}
	}
	/*走到这里说明有一个位置可以插入，插入即可*/
	hash[location] = n;
	/*返回*/
	return;
}

/*初始化Hash表*/
void init_hash(int* hash, int size)
{
	/*遍历数组，赋初值为-234567，表示当前位置没有元素占用*/
	for (int i = 0; i < size; i++)
	{
		hash[i] = -234567;
	}
	/*返回*/
	return;
}

/*查找重复元素*/
bool containsDuplicate(int* nums, int numsSize)
{
	/*如果数组为空，直接返回false*/
	if (numsSize == 0)
	{
		return false;
	}
	/*定义Hash表长度*/
	int hash_size = 5 * numsSize;
	/*初始化Hash表，正常这里应该填hash_size，当时C语言数组定义不能使用变量，所以临时填10000*/
	int hash[10000];
	init_hash(hash, hash_size);
	/*依次遍历*/
	for (int i = 0; i < numsSize; i++)
	{
		/*如果在Hash表中找到相同元素，返回true，正常这里应该填hash_size，当时C语言数组定义不能使用变量，所以临时填10000*/
		if (find_hash(nums[i], hash, 10000)) {
			return true;
		}
		/*如果没找到，将当前元素插入到Hash表中，正常这里应该填hash_size，当时C语言数组定义不能使用变量，所以临时填10000*/
		insert_hash(nums[i], hash, 10000);
	}
	/*如果遍历完都没找到重复数，返回false*/
	return false;
}

/*主函数省略*/
