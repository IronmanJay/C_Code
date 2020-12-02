#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*���������������ֵ*/
int MAX_p395_LongestSubstringWithAtLeastKRepeatingCharacters(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int longestSubstring(char * s, int k)
{
	/*��ȡ�ַ�������*/
	int len = strlen(s);
	/*�߽�ֵ�ж�*/
	if (len == 0 || k > len)
	{
		return 0;
	}
	if (k < 2)
	{
		return len;
	}
	/*���ؽ��*/
	return getRes(s, k, 0, len - 1);
}

int getRes(char* s, int k, int left, int right)
{
	/*�����ǰ״̬���ַ�������С��k��˵����ǰ״̬���ַ�������ȫ��һ����ĸ��Ҳ�ﲻ��k���ظ�������0������Ҫʱ�̱�֤��ǰ״̬���Ӵ������Ƿ�>k���Ӷ����ٲ���Ҫ�ıȽ�*/
	if (right - left + 1 < k)
	{
		return 0;
	}
	/*��¼26��Ӣ����ĸ���ֵĴ���*/
	int* count = (int*)calloc(26, sizeof(int));
	for (int i = left; i <= right; i++)
	{
		count[s[i] - 'a']++;
	}
	/*���ĳ����ĸ���ֵĴ���С��k�������ܳ����ڽ���ַ����У������޸�����ָ���λ�ã���������Ҫ�����ĸ�ų�*/
	while (right - left + 1 >= k && count[s[left] - 'a'] < k)
	{
		left++;
	}
	while (right - left + 1 >= k && count[s[right] - 'a'] < k)
	{
		right--;
	}
	/*�ٴ��жϣ������ǰ״̬���ַ�������С��k��˵����ǰ״̬���ַ����϶�������Ҫ�󣬷���0*/
	if (right - left + 1 < k)
	{
		return 0;
	}
	/*��ʼ���Σ������ǰ���ַ������г��ִ���С��k����ĸ��˵����ǰ���ַ����϶�������Ҫ����ô�����ִ�ͬ�ϵݹ鴦���������ֵ*/
	for (int i = left; i <= right; i++)
	{
		if (count[s[i] - 'a'] < k)
		{
			return MAX_p395_LongestSubstringWithAtLeastKRepeatingCharacters(getRes(s, k, left, i - 1), getRes(s, k, i + 1, right));
		}
	}
	/*���տ϶�������Ҫ����Ӵ������ؼ���*/
	return right - left + 1;
}

/*������ʡ��*/
