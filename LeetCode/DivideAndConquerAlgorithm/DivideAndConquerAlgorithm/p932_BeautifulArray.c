#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
  arr:待生成数组
  N:要生成的数组元素个数
  start:数组开始位置
  end:数组结束位置
  Elem:从1开始生成漂亮数组
  step:步长
*/
void dc(int *arr, int N, int start, int end, int Elem, int step)
{
	/*参数不对，直接返回，也是退出递归的条件*/
	if (arr == NULL || N <= 0 || start >= N || end >= N || start > end) {
		return;
	}
	/*只有一个元素*/
	else if (start == end)
	{
		arr[start] = Elem;
	}
	/*三个或三个以上元素*/
	else
	{
		/*中间位置*/
		int pos = (start + end) / 2;
		/*首先在这里说明一下，这里特别巧妙，因为我们需要左面是奇数，右面是偶数，这样才能构成漂亮数组*/
		/*那么首先传入的Elem是1，奇数，根据这个每次步长都*2，我们要明白，奇数+偶数=奇数，偶数*2=偶数*/
		/*我们首先向左递归，递归到最后，Elem还是奇数1，正常放入数组即可，而此时的右递归就是奇数+偶数=奇数，这样就保证了所有左面都是奇数*/
		/*然后再看右递归，首次递归的时候Elem就+1，变为偶数了，后面一直+(step*2)，所以保证了右面一直都是偶数*/
		dc(arr, N, start, pos, Elem, step * 2); /*向左递归*/
		dc(arr, N, pos + 1, end, Elem + step, step * 2); /*向右递归*/
	}
}

int* beautifulArray(int N, int* returnSize) {
	/*判空返回*/
	if (N < 1 || returnSize == NULL)
	{
		return NULL;
	}
	else {
		/*新建数组*/
		int* arr = (int *)malloc(sizeof(int) * N);
		/*使用分治开始递归*/
		dc(arr, N, 0, N - 1, 1, 1);
		*returnSize = N;
		/*返回结果*/
		return arr;
	}
}

/*主函数省略*/