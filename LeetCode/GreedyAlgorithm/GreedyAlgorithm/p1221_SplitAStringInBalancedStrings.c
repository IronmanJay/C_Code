#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int balancedStringSplit(char * s)
{
	/*���*/
	int res = 0;
	/*����ƽ�����ӣ����Ϊ�㣬˵����ǰƽ�⣬res++������һ��ʼ��ƽ��ģ�����Ϊ0*/
	int balance = 0;
	/*��ʼ����*/
	for (int i = 0; i < strlen(s); i++)
	{
		/*����'L'��balance--*/
		if (s[i] == 'L')
		{
			balance--;
		}
		/*����'R'��balance++*/
		if (s[i] == 'R')
		{
			balance++;
		}
		/*���������balanceΪ0��˵������һ��ƽ����ƽ���ַ��������+1*/
		if (balance == 0)
		{
			res++;
		}
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
