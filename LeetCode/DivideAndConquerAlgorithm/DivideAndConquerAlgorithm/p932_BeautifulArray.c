#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
  arr:����������
  N:Ҫ���ɵ�����Ԫ�ظ���
  start:���鿪ʼλ��
  end:�������λ��
  Elem:��1��ʼ����Ư������
  step:����
*/
void dc(int *arr, int N, int start, int end, int Elem, int step)
{
	/*�������ԣ�ֱ�ӷ��أ�Ҳ���˳��ݹ������*/
	if (arr == NULL || N <= 0 || start >= N || end >= N || start > end) {
		return;
	}
	/*ֻ��һ��Ԫ��*/
	else if (start == end)
	{
		arr[start] = Elem;
	}
	/*��������������Ԫ��*/
	else
	{
		/*�м�λ��*/
		int pos = (start + end) / 2;
		/*����������˵��һ�£������ر������Ϊ������Ҫ������������������ż�����������ܹ���Ư������*/
		/*��ô���ȴ����Elem��1���������������ÿ�β�����*2������Ҫ���ף�����+ż��=������ż��*2=ż��*/
		/*������������ݹ飬�ݹ鵽���Elem��������1�������������鼴�ɣ�����ʱ���ҵݹ��������+ż��=�����������ͱ�֤���������涼������*/
		/*Ȼ���ٿ��ҵݹ飬�״εݹ��ʱ��Elem��+1����Ϊż���ˣ�����һֱ+(step*2)�����Ա�֤������һֱ����ż��*/
		dc(arr, N, start, pos, Elem, step * 2); /*����ݹ�*/
		dc(arr, N, pos + 1, end, Elem + step, step * 2); /*���ҵݹ�*/
	}
}

int* beautifulArray(int N, int* returnSize) {
	/*�пշ���*/
	if (N < 1 || returnSize == NULL)
	{
		return NULL;
	}
	else {
		/*�½�����*/
		int* arr = (int *)malloc(sizeof(int) * N);
		/*ʹ�÷��ο�ʼ�ݹ�*/
		dc(arr, N, 0, N - 1, 1, 1);
		*returnSize = N;
		/*���ؽ��*/
		return arr;
	}
}

/*������ʡ��*/