#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* sortedSquares(int* A, int ASize, int* returnSize)
{
	/*�������*/
	int* res = (int *)malloc(sizeof(int)*ASize);
	/*ͷָ��*/
	int start = 0;
	/*βָ��*/
	int end = ASize - 1;
	/*�������ָ��*/
	int index = ASize - 1;
	/*��ʼ����*/
	while (start <= end)
	{
		/*˭���˭�ŵ��������ĺ��棬ָ����Ӧ�仯��ע�����ﲻ�ܰ�С�ķŵ���������ǰ�棬��Ϊ�и����Ŀ��ܣ�ƽ��֮�󷴶�����ˣ����������Ѿ�������ص㣬������ı�֤���ԴӺ���ǰ���*/
		if (A[start] * A[start] > A[end] * A[end])
		{
			res[index] = A[start] * A[start];
			index--;
			start++;
		}
		else
		{
			res[index] = A[end] * A[end];
			index--;
			end--;
		}
	}
	/*���ش�С*/
	*returnSize = ASize;
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
