#include<stdio.h>

enum TYPE
{
	run,attack,skill,dance,showUI,frozen,dizz,dath,moti
}type;

int main02(void)
{
	int value;
	while (1)
	{
		scanf_s("%d", &value);
		switch (value)
		{
		case run:
			printf("�����ƶ���\n");
			break;
		case attack:
			printf("���ڹ�����\n");
			break;
		case skill:
			printf("�����ͷż�����\n");
			break;
		case dance:
			printf("����������\n");
			break;
		case showUI:
			printf("������ʾ������\n");
			break;
		case frozen:
			printf("���ڱ�����\n");
			break;
		case dizz:
			printf("����ѣ����\n");
			break;
		case dath:
			printf("����������\n");
			return 0;
			break;
		case moti:
			printf("���ھ�ֹ��\n");
			break;
		default:
			break;
		}
	}
	getchar();
}