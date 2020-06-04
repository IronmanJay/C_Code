#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /*�洢�ռ��ʼ������*/

typedef int Status; /*Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��*/

/*���ڱ�ģʽ��aΪ���飬nΪҪ���ҵ����������keyΪҪ���ҵĹؼ���*/
int Sequential_Search1(int *a, int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return 0;
}

/*���ڱ�ģʽ*/
int Sequential_Search2(int *a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while (a[i] != key)
	{
		i--;
	}
	return i;
}

/*˳�����*/
int mainSuquential_Search(void)
{

	int a[MAXSIZE + 1], i, result;

	for (i = 0; i <= MAXSIZE; i++)
	{
		a[i] = i;
	}

	result = Sequential_Search1(a, MAXSIZE, MAXSIZE);
	printf("Sequential_Search1:%d \n", result);

	result = Sequential_Search2(a, MAXSIZE, 1);
	printf("Sequential_Search2:%d \n", result);

	getchar();

}