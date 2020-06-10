#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

/*自定义比较函数，如果s2+s1>s1+s2，就返回到qsort交换两个元素*/
int cmp(const void *p1, const void *p2)
{
	char a1[MAX * 2 + 1];
	char a2[MAX * 2 + 1];
	sprintf(a1, "%d%d", *(int*)p1, *(int*)p2);
	sprintf(a2, "%d%d", *(int*)p2, *(int*)p1);
	return (strcmp(a2, a1));
}

/*得到最终的最大数*/
char * largestNumber(int* nums, int numsSize)
{
	/*开辟结果空间*/
	char *result = malloc(numsSize * MAX + 1);
	memset(result, '\0', numsSize * MAX + 1);
	/*使用自定义比较函数，具体看cmp*/
	qsort(nums, numsSize, sizeof(int), cmp);
	/*如果比较排序后第一个数组是0，直接返回*/
	if (nums[0] == 0)
	{
		return "0";
	}
	/*这个p是result的指针，用于每次变换指针的位置，将数组写入到结果数组对应的位置，也就是p指针指向result得位置，当前数字是几位就+几位，最终将int类型的数组填充到字符串中*/
	char *p = result;
	for (int i = 0; i < numsSize; i++)
	{
		sprintf(p, "%d", nums[i]);
		p += strlen(p);
	}
	/*返回结果*/
	return result;
}

/*主函数省略*/
