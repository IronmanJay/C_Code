#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
	/*����������*/
	int *res = (int*)malloc(ASize * sizeof(int));
	/*����ż���±�������±�*/
	int oddIndex = 0;
	int evenIndex = 1;
	/*����A����ÿһ��Ԫ�أ������ż������ô�ͷŵ�res�����ż��λ�ã�oddIndex��Ӧ+2��������������ͷŵ�res��������λ�ã�eventIndex��Ӧ+2*/
	for (int i = 0; i < ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			res[oddIndex] = A[i];
			oddIndex += 2;
		}
		else
		{
			res[evenIndex] = A[i];
			evenIndex += 2;
		}
	}
	/*���ؽ��*/
	*returnSize = ASize;
	return res;
}

/*������ʡ��*/
int main(void)
{

}