#include<stdio.h>

#define MAX_ 10 /*�������*/
#define RADIX 10 /*��������*/
#define KEYNUM 10 /*�ؼ��ָ���������Ϊ����λ��*/

/*��ӡ���*/
void Show(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*�ҵ�num�Ĵӵ͵��ߵĵ�posλ������*/
int GetNumInPos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
	{
		temp *= 10;
	}
	return (num / temp) % 10;
}

/*pDataArray:��������*/
/*iDataNum:�����������*/
void RadixSort(int* pDataArray, int iDataNum)
{
	int *radixArrays[RADIX]; /*�ֱ�Ϊ0~9�����пռ�*/
	for (int i = 0; i < 10; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
		radixArrays[i][0] = 0; /*indexΪ0����¼�������ݵĸ���*/
	}
	for (int pos = 1; pos <= KEYNUM; pos++) /*�Ӹ�λ��ʼ��ʮλ*/
	{
		for (int i = 0; i < iDataNum; i++) /*�������*/
		{
			int num = GetNumInPos(pDataArray[i], pos); /*��õ�ǰλ��ֵ*/
			int index = ++radixArrays[num][0]; /*��ǰλ�õ�Ԫ�ظ���+1*/
			radixArrays[num][index] = pDataArray[i]; /*����ǰԪ�ظ�ֵ�����Ͱ��indexΪ0����¼��ǰԪ�ظ���*/
		}
		for (int i = 0, j = 0; i < RADIX; i++) /*�ռ�����*/
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
			{
				pDataArray[j++] = radixArrays[i][k]; /*�����ִ�Ͱ��ȡ����*/
			}
			radixArrays[i][0] = 0; /*����ǰͰ�����ָ�����λ�����´α���ʱʹ��*/
		}
	}
}

/*��������*/
int mainRadixSort(void)
{

	/*��������*/
	int arr_test[MAX_] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
	/*����ǰ��������*/
	printf("����ǰ��");
	Show(arr_test, MAX_);
	RadixSort(arr_test, MAX_);
	/*�������������*/
	printf("�����");
	Show(arr_test, MAX_);

	getchar();

}
