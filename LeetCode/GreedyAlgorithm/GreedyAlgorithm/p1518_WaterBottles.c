#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int numWaterBottles(int numBottles, int numExchange)
{
	/*���ս��*/
	int res = 0;
	/*ÿ�ֵ�ʣ��վ�ƿ�������ܻ����پ�*/
	int emptyWine = 0;
	/*�оƾ��ܺ�*/
	while (numBottles > 0)
	{
		/*ÿ��ֻҪ�оƾ��ܺȣ����Խ������ÿ���ܺȵľ�*/
		res += numBottles;
		/*ÿ���ܺȶ��پƾ�ʣ���ٿվ�ƿ*/
		emptyWine += numBottles;
		/*ÿ�ְ����еľƶ���û�ˣ����Ե�ǰʣ��ľ��ÿգ�ͬʱΪ��һ�ֻ�����׼��*/
		numBottles = 0;
		/*��վ�ƿ�ܻ����پ�*/
		numBottles += emptyWine / numExchange;
		/*�㻻��ƻ�ʣ���ٿվ�ƿ*/
		emptyWine = emptyWine % numExchange;
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
