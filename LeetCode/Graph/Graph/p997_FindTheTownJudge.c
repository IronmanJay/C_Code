#include<stdio.h>
#include<stdlib.h>

/*
	trustSize：表示对数
	*trustColSize：表示每队是两个
 */
int findJudge(int N, int** trust, int trustSize, int* trustColSize) {

	int cnt[999999 + 1]; /*999999就是N，这里用来占位，因为编译器的原因，不能在数组初始化时用没有定义的常量，记得用的时候替换成N*/
	memset(cnt, 0, sizeof(int) * (N + 1));

	// 如果被信任，则cnt++，如果信任了别人，则cnt置为-1，肯定不是法官，以后cnt不再增加
	for (int i = 0; i < trustSize; i++)
	{
		if (cnt[trust[i][1]] >= 0)
		{
			cnt[trust[i][1]]++;
		}
		cnt[trust[i][0]] = -1;
	}

	// 被信任数是N - 1的则是法官
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
	/*主函数省略*/
}