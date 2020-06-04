#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1; /*��������±�Ϊ��¼��λ*/
	high = n; /*��������±�Ϊ��¼ĩβ*/
	while (low <= high)
	{
		mid = (low + high) / 2; /*�۰�*/
		if (key < a[mid]) /*������ֵ����ֵС*/
		{
			high = mid - 1; /*����±��������λ�±�Сһλ*/
		}
		else if (key > a[mid]) /*������ֵ����ֵ��*/
		{
			low = mid + 1; /*����±��������λ�±��һλ*/
		}
		else
		{
			return mid; /*�������˵��mid��ΪҪ���ҵ���λ��*/
		}
	}
	return 0;
}

/*�۰����*/
int mainBinary_Search(void)
{
	int i, result;
	int arr[MAXSIZE] = { 0,1,16,24,35,47,59,62,73,88,99 };

	result = Binary_Search(arr, 10, 62);
	printf("Binary_Search:%d \n",result);

	getchar();

}