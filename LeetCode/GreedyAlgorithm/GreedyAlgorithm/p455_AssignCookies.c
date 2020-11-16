#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*自定义排序，从小到大排序*/
int compare_p455_AssignCookies(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	/*存储结果*/
	int res = 0;
	/*对数组进行排序*/
	qsort(g, gSize, sizeof(int), compare_p455_AssignCookies);
	qsort(s, sSize, sizeof(int), compare_p455_AssignCookies);
	/*孩子和饼干的数组指针*/
	int gindex = 0;
	int sindex = 0;
	/*只要饼干消耗完或者孩子已经喂完就结束*/
	while (sindex < sSize && gindex < gSize)
	{
		/*获取当前饼干的尺寸*/
		int cookiesSize = s[sindex++];
		/*给没喂的孩子喂饼干，只要饼干的尺寸大于等于孩子的胃口就能满足要求，这里体现贪心算法的思想，遇到满足胃口的孩子就可以*/
		for (int i = gindex; i < gSize; i++)
		{
			/*如果遇到了满足要求的孩子，当前的饼干被消耗，不再计算，当前的孩子也已经喂了，不再计算，直接break掉，等待下一次匹配*/
			if (cookiesSize >= g[i])
			{
				res++;
				gindex++;
				break;
			}
		}
	}
	/*返回结果*/
	return res;
}

/*主函数省略*/
