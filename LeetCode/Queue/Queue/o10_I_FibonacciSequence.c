#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fib(int n)
{
	/*С�ڵ���1�����ֵ�쳲��������к;�������*/
	if (n <= 1)
	{
		return n;
	}
	/*���д��ǰn��ĺ�*/
	int* queue = (int*)malloc(sizeof(int) * 100);
	int head = 0;
	int tail = 0;
	/*�Ƚ�ǰ���������*/
	queue[tail++] = 1;
	queue[tail++] = 1;
	/*���ÿ����ĺ�*/
	int addNum = 0;
	/*���ÿ����ȡģ��ĺ�*/
	int newAddNum = 0;
	/*�ӵ����ʼ����쳲��������еļ���*/
	int count = 3;
	while (count <= n)
	{
		/*һ��poll()һ��peek()����������ȡ���������*/
		int addNum = queue[head++] + queue[head];
		/*������Ҫ��͵Ľ������1000000008����1*/
		if (addNum == 1000000008)
		{
			return 1;
		}
		/*����Ժ͵Ľ��ȡģ*/
		else
		{
			newAddNum = addNum % 1000000007;
		}
		/*��ȡģ��͵Ľ������У������������Ǵ��ǰn-1��ĺͺ�ǰn��ĺ�*/
		queue[tail++] = newAddNum;
		/*����+1*/
		count++;
	}
	/*���������һ��Ԫ�ؾ���ǰn��ĺ�*/
	return queue[--tail];
}

/*������ʡ��*/
