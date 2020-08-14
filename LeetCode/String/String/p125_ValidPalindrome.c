#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char * s) {
	/*�пշ���*/
	if (s == NULL || strlen(s) == 0)
	{
		return true;
	}
	/*��������ָ��*/
	int left = 0;
	int right = strlen(s) - 1;
	/*��ʼ����*/
	while (left <= right)
	{
		/*����ڷ�Χ���Ҳ������ֻ�����ĸ���������Ԫ�أ���ָ��+1*/
		while (left <= right && !isalnum(s[left]))
		{
			left++;
		}
		/*����ڷ�Χ���Ҳ������ֻ�����ĸ���������Ԫ�أ���ָ��-1*/
		while (left <= right && !isalnum(s[right]))
		{
			right--;
		}
		/*����ڷ�Χ��������ĸ����ȣ�����false*/
		if (left <= right && tolower(s[left]) != tolower(s[right]))
		{
			return false;
		}
		/*�����ȣ���ָ��+1����ָ��-1����������*/
		left++;
		right--;
	}
	/*˵���ǻ��Ĵ�������true*/
	return true;
}

/*������ʡ��*/
