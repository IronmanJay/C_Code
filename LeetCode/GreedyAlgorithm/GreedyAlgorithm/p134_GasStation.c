#include<stdio.h>
#include<stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
	/*ȫ��������ֵ*/
	int totalGas = 0;
	/*��ǰ������ֵ*/
	int curGas = 0;
	/*��ʼ��ַ*/
	int startPos = 0;
	/*��ʼ����*/
	for (int i = 0; i < gasSize; i++)
	{

		/*�洢ÿһ��������վ���Ĵ������ͺ�������ֵ*/
		totalGas += gas[i] - cost[i];
		/*�洢��ǰ������վ�ġ��������ͺ�������ֵ*/
		curGas += gas[i] - cost[i];
		/*�����ǰ������ֵ����0��˵�����λ�þ��п�������㣬�����ǰ������ֵС��0��˵���������վ�϶�������㣬��Ϊ��������������*/
		if (curGas < 0)
		{
			/*��Ϊ���������㣬�������ӵ�ǰλ��+1������һ��λ���ǲ������*/
			startPos = i + 1;
			/*curGasҪ��Ϊ0����Ϊ����㱻�����ˣ����Դ���һ�����¿�ʼ*/
			curGas = 0;
		}
	}
	/*������totalGas���ڵ���0��˵�������㹻������ȫ�̣���ôֱ�ӷ���startPos�����С��0��˵�����е��ͼ�����������������ȫ�̣�����-1*/
	return totalGas >= 0 ? startPos : -1;
}

/*������ʡ��*/
