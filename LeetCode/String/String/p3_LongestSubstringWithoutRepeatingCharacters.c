#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�������ֵ*/
int Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int lengthOfLongestSubstring(char * s)
{
	/*˫ָ�룬�ֱ�ָ��ʼ�ͽ�β*/
	int start = 0;
	int end = 0;
	/*��ʱ�����ظ��ַ����Ӵ�����*/
	int len = 0;
	/*���*/
	int res = 0;
	/*�ڲ�Խ�������±����ַ���*/
	while (end < strlen(s))
	{
		/*���ȿ���ǰ�ַ��Ƿ���֮ǰ���Ӵ��г��ֹ���������ֹ���startλ��������������ظ����ֵ��޳���*/
		for (int index = start; index < end; index++)
		{
			if (s[index] == s[end])
			{
				start = index + 1;
				len = end - start;
				break;
			}
		}
		/*�����ǰ�ַ�û����֮ǰ���Ӵ��г��ֹ�����βָ��������ƣ���ʼָ�벻�ö���������Ӧ���ӣ�res���ؽϴ��*/
		len++;
		end++;
		res = Max(len, res);
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/