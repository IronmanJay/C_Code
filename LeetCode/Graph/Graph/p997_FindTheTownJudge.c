#include<stdio.h>
#include<stdlib.h>

/*
	trustSize����ʾ����
	*trustColSize����ʾÿ��������
 */
int findJudge(int N, int** trust, int trustSize, int* trustColSize) {

	int cnt[999999 + 1]; /*999999����N����������ռλ����Ϊ��������ԭ�򣬲����������ʼ��ʱ��û�ж���ĳ������ǵ��õ�ʱ���滻��N*/
	memset(cnt, 0, sizeof(int) * (N + 1));

	// ��������Σ���cnt++����������˱��ˣ���cnt��Ϊ-1���϶����Ƿ��٣��Ժ�cnt��������
	for (int i = 0; i < trustSize; i++)
	{
		if (cnt[trust[i][1]] >= 0)
		{
			cnt[trust[i][1]]++;
		}
		cnt[trust[i][0]] = -1;
	}

	// ����������N - 1�����Ƿ���
	for (int i = 1; i <= N; i++)
	{
		if (cnt[i] == N - 1) 
		{
			return i;
		}
	}
	return -1;

}

int main(void) {
	/*������ʡ��*/
}