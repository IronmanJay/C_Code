#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * intToRoman(int num)
{
	// ���ٽ������ռ�
	char *res = (char *)malloc(20 * sizeof(char));
	// �������ֶ�Ӧ������ֵ
	int value[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	// ���ֶ�Ӧ�������ֵ�ֵ
	char str[13][3] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
	// һ��ʮ������Ӧ��ϵ��ѭ��ʮ����
	for (int i = 0; i < 13; i++)
	{
		// ��whileѭ��������ʱ��˵����ǰλ��ֵ
		while (num >= value[i])
		{
			// ��ǰ���ּ�ȥ��һλ
			num -= value[i];
			// ������������һλ��Ӧ����������
			strcat(res, str[i]);
		}
	}
	// ���ؽ��
	return res;
}