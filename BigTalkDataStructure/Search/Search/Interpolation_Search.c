#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<io.h>
#include<math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

int Interpolation_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1; /*��������±�Ϊ��¼��λ*/
	high = n; /*��������±�Ϊ��¼ĩλ*/
	while (low <= high)
	{
		mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]); /*��ֵ*/
		if (key < a[mid]) /*������ֵ�Ȳ�ֵС*/
		{
			high = mid - 1; /*����±��������ֵ�±�Сһλ*/
		}
		else if (key > a[mid]) /*������ֵ�Ȳ�ֵ��*/
		{
			low = mid + 1; /*����±��������ֵ�±��һλ*/
		}
		else
		{
			return mid; /*�������˵��mid��Ϊ���ҵ���λ��*/
		}
	}
	return 0;
}

/*��ֵ����*/
int mainInterpolation_Search(void)
{

	int result, i;
	int arr[MAXSIZE] = { 0,1,16,24,35,47,59,62,73,88,99 };

	result = Interpolation_Search(arr, 10, 62);
	printf("Interpolation_Search:%d \n", result);

	getchar();

}
