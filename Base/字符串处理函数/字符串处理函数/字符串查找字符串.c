#include<stdio.h>

char* my_strstr(char* src, char* dest)
{
	//����Դ�ַ�����ָ��
	char* fsrc = src;
	//��¼ÿ���ַ����׵�ַ
	char* rsrc = src;
	char* tdest = dest;
	while (*fsrc)
	{
		rsrc = fsrc;
		while (*fsrc == *tdest && *fsrc != '\0')
		{
			fsrc++;
			tdest++;
		}
		if (*tdest == '\0')
		{
			return rsrc;
		}
		//Ŀ���ַ������µ���ʼλ��
		tdest = dest;
		fsrc = rsrc;
		fsrc++;
	}
	return NULL;
}

int main3(void)
{
	char src[] = "hello world";
	char dest[] = "llo";
	char* p = my_strstr(src, dest);
	printf("%s\n", p);

	getchar();
}