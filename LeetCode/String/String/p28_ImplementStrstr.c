#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strStr(char * haystack, char * needle) {
	/*�߽�����*/
	if (haystack != NULL && strcmp(haystack, needle) == 0)
	{
		return 0;
	}
	if (haystack == NULL || strlen(haystack) == 0)
	{
		return -1;
	}
	if (needle == NULL || strlen(needle) == 0)
	{
		return 0;
	}
	/*��ȡ�ַ�������*/
	int H = strlen(haystack);
	int N = strlen(needle);
	/*������H-N���ɣ����泬������û��Ҫ�Ƚϣ����ٱȽϴ���*/
	for (int i = 0; i <= H - N; i++)
	{
		/*�������ȱ���ƥ��һ��*/
		int j = 0;
		while (j < N && needle[j] == haystack[i + j])
		{
			j++;
		}
		/*�������ƥ�䵽������λ�ü���*/
		if (j == N)
		{
			return i;
		}
		/*�������ƥ��ʧ�ܣ�ʹ��Sunday�㷨ƥ��*/
		else
		{
			/*��ȡneedle����������*/
			int k = N - 1;
			/*�Ӻ���ǰ�ң�Ŀ���������ƶ������������ƶ�����*/
			while (k >= 0 && i + N < H && needle[k] != haystack[i + N])
			{
				k--;
			}
			/*���k<0˵����ǰ���Ԫ��δ�����ڴ�ƥ���ַ����У���������֮ǰ��Ԫ��+�����ƥ���Ԫ��*/
			if (k < 0)
			{
				i = i + N + 1;
			}
			/*���k>0˵����ǰ���Ԫ�س����ڴ�ƥ���ַ����У�k���ǵ�ǰ���Ԫ���ڴ�ƥ���ַ���һ�γ��ֵ�������ֱ�Ӷ��뼴��*/
			else
			{
				i = i + N - 1 - k;
			}
		}
	}
	/*δƥ�䵽������-1*/
	return -1;
}

/*������ʡ��*/