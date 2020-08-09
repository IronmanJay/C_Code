#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * addBinary(char * a, char * b) {
	/*��ȡ�ַ�������*/
	int lenA = strlen(a);
	int lenB = strlen(b);
	int i, j;
	/*��ʾ��λ*/
	int carry = 0;
	/*��������*/
	int index = 0;
	/*�½��������*/
	char *res = (char*)malloc(sizeof(char) * 1000);
	/*�Ӻ���ǰ����*/
	for (i = lenA - 1, j = lenB - 1; i >= 0 || j >= 0 || carry; i--, j--)
	{
		/*�п������������鳤�Ȳ�һ�����ͻ���i��jС��0���������ʱ���ǲ�����뼴��*/
		int x = i < 0 ? 0 : a[i] - '0';
		int y = j < 0 ? 0 : b[j] - '0';
		/*��Ӧλ��ӣ��������carry�ж��Ƿ��λ�����������λ�������0�����û������λ�������1*/
		int num = (x + y + carry) % 2;
		/*carryֻ�ܵ�0����1�����������λ����1�����û������λ����0*/
		carry = (x + y + carry) / 2;
		/*�������������*/
		res[index++] = num + '0';
	}
	/*�����ַ�*/
	res[index] = '\0';
	/*��Ϊ�ǴӺ���ǰ������ӣ�������Ҫ��ת�ַ���������ǽ��*/
	for (i = 0, j = index - 1; i < j; i++, j--)
	{
		char temp = res[i];
		res[i] = res[j];
		res[j] = temp;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/