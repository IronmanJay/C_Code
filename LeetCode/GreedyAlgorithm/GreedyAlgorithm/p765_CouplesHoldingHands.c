#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int minSwapsCouples(int* row, int rowSize)
{
	/*������*/
	int res = 0;
	/*��ʼ������ÿ�εõ�һ�����£�����i+=2*/
	for (int i = 0; i < rowSize; i+=2)
	{
		/*���������ʵ�ʾ��������ǰ��ż������ô��Ӧ�����¿϶��Ƕ�Ӧ��(+1)��������֮�����ǰ������������ô��Ӧ�����¿϶��Ƕ�Ӧ��(-1)ż��*/
		if (row[i + 1] == (row[i] ^ 1))
		{
			/*�������Ҫ��ֱ��������ǰ���ѭ���Ϳ���*/
			continue;
		}
		/*����ʼ�������ҵ���Ӧ�����£������Ӧ+1*/
		res++;
		for (int j = i + 1; j < rowSize; j++)
		{
			if (row[j] == (row[i] ^ 1))
			{
				row[j] = row[i + 1];
				row[i + 1] = row[i] ^ 1;
				break;
			}
		}
	}
	return res;
}

/*������ʡ��*/
