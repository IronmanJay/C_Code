#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*����С����*/
int I1709_MIN(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

int getKthMagicNumber(int k)
{
	/*����������*/
	int* res = (int *)malloc(k * sizeof(int));
	/*��ʼ����һ��λ��Ϊ1*/
	res[0] = 1;
	/*����������ָ��*/
	int p3 = 0;
	int p5 = 0;
	int p7 = 0;
	for (int i = 1; i < k; i++)
	{
		/*ĳһ��������������һ����֮ǰ��ĳ��res[p3]*3��������res[p5]*5��������res[p7]*7�Ľ�������ҽ��һ�����������˻�����Сֵ*/
		int temp = I1709_MIN(I1709_MIN(res[p3] * 3, res[p5] * 5), res[p7] * 7);
		/*p3��p5��p7�ǲ��ϱ仯�ģ����Ҷ�Ӧ������С����˭��ѡ�У���Ӧ��ȡ��һ��ֵ*/
		if (temp % 3 == 0)
		{
			p3++;
		}
		if (temp % 5 == 0)
		{
			p5++;
		}
		if (temp % 7 == 0)
		{
			p7++;
		}
		/*������Ҫ��ļ���������*/
		res[i] = temp;
	}
	/*���һ��Ԫ�ؾ���Ŀ��ֵ�����ؼ���*/
	return res[k - 1];
}

/*������ʡ��*/
