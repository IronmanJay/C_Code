#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*�õ�ÿ�ε���*/
int getHappyNum(int n)
{
	/*���ÿһ�ε�ֵ*/
	int res = 0;
	/*���ÿһλ��ƽ����*/
	int t;
	while (n != 0)
	{
		/*�Ӹ�λ��ʼ����λȡÿһλ��ƽ����*/
		t = n % 10;
		res = res + t * t;
		/*�Ӹ�λ���󣬱�����һ��λ����ֵ*/
		n = n / 10;
	}
	/*������εĽ��*/
	return res;
}

/*�ж��Ƿ����*/
bool exist(int* set, int n, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (set[i] == n)
		{
			return true;
		}
	}
	return false;
}

bool isHappy(int n)
{
	int len = 1;
	int set[100];
	/*���Ƚ�������ּ���*/
	set[0] = n;
	n = getHappyNum(n);
	/*��ʼ����ѭ�������н��ʱ����*/
	while (n != 1)
	{
		/*�������ѭ��������False*/
		if (exist(set, n, len))
		{
			return false;
		}
		// �������n��ֵ����ѭ��
		else
		{
			set[len++] = n;
			/*����n��ֵ*/
			n = getHappyNum(n);
		}
	}
	/*���n=1����True*/
	return true;
}

int main(void)
{
	/*������ʡ��*/
}
