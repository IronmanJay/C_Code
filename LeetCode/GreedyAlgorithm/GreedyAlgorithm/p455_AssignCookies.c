#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*�Զ������򣬴�С��������*/
int compare_p455_AssignCookies(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	/*�洢���*/
	int res = 0;
	/*�������������*/
	qsort(g, gSize, sizeof(int), compare_p455_AssignCookies);
	qsort(s, sSize, sizeof(int), compare_p455_AssignCookies);
	/*���Ӻͱ��ɵ�����ָ��*/
	int gindex = 0;
	int sindex = 0;
	/*ֻҪ������������ߺ����Ѿ�ι��ͽ���*/
	while (sindex < sSize && gindex < gSize)
	{
		/*��ȡ��ǰ���ɵĳߴ�*/
		int cookiesSize = s[sindex++];
		/*��ûι�ĺ���ι���ɣ�ֻҪ���ɵĳߴ���ڵ��ں��ӵ�θ�ھ�������Ҫ����������̰���㷨��˼�룬��������θ�ڵĺ��ӾͿ���*/
		for (int i = gindex; i < gSize; i++)
		{
			/*�������������Ҫ��ĺ��ӣ���ǰ�ı��ɱ����ģ����ټ��㣬��ǰ�ĺ���Ҳ�Ѿ�ι�ˣ����ټ��㣬ֱ��break�����ȴ���һ��ƥ��*/
			if (cookiesSize >= g[i])
			{
				res++;
				gindex++;
				break;
			}
		}
	}
	/*���ؽ��*/
	return res;
}

/*������ʡ��*/
