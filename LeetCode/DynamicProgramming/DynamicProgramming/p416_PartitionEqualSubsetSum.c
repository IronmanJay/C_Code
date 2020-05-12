#include<stdio.h>
#include<stdlib.h>

/*ע��1Ϊtrue��0Ϊfalse*/
typedef int bool;

bool canPartition(int* nums, int numsSize) {
	int i, j, target;
	// ͳ����������֮�ͣ����ֵ����Ŀ��ֵ
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	// ���Ϊ��������false
	if (sum % 2 != 0) {
		return 0;
	}
	// Ŀ��ֵ
	target = sum / 2;
	// Ϊdp�����ڴ棬����ʼ��Ϊfalse��Ȼ���һ��Ϊtrue
	bool **dp = (bool **)malloc(sizeof(bool *) * (numsSize + 1));
	for (int i = 0; i < numsSize + 1; i++) {
		dp[i] = (bool *)malloc(sizeof(bool) * (target + 1));
		memset(dp[i], 0, sizeof(bool) * (target + 1));
		dp[i][0] = 1;
	}
	// ��dp[1][1]��ʼ�������飬���dp[i-1][j]Ϊtrue�Ļ�����ôdp[i][j]�϶�Ϊtrue��
	// ��˵���Ѿ�������ܹ��ﵽ�ֲ�Ŀ��ֵ�ˣ�����������Ҳ����ı�����dp[i-1][j-nums[j-1]]
	for (int i = 1; i < numsSize + 1; i++) {
		for (int j = 1; j < target + 1; j++) {
			if (dp[i - 1][j] == 1 || (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]] == 1)) {
				dp[i][j] = 1;
			}
		}
	}
	// ������һ�����һ�е�ֵ
	return dp[numsSize][target];
}

int main(void) {
	int nums[4] = { 1,5,11,5 };
	int res = canPartition(nums, 4);
	printf("%d",res);
	getchar();
}
