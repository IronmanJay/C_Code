#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*��������ȫ�ֱ���*/
int res;

void count(char * s, int left, int right)
{
	/*��left��right��Խ���ʱ�򣬴����ĵ���������չ��������ȵ�˵���л����Ӵ�*/
	while (left >= 0 && right < strlen(s) && s[left] == s[right])
	{
		res++;
		left--;
		right++;
	}
}

int countSubstrings(char * s)
{
	/*�����˰ѽ����ȫ�ֱ�����ʼ��һ��*/
	res = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		/*��ѡȡ�����ĵ�Ϊ��������Ҳ����һ���ַ�*/
		count(s, i, i);
		/*��ѡȡ�����ĵ�Ϊż������Ҳ���������ַ�*/
		count(s, i, i + 1);
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
