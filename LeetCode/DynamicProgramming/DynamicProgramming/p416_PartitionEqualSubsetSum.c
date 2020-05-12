#include<stdio.h>
#include<stdlib.h>

/*注：1为true，0为false*/
typedef int bool;

bool canPartition(int* nums, int numsSize) {
	int i, j, target;
	// 统计所有数字之和，这个值就是目标值
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	// 如果为奇数返回false
	if (sum % 2 != 0) {
		return 0;
	}
	// 目标值
	target = sum / 2;
	// 为dp申请内存，都初始化为false，然后第一列为true
	bool **dp = (bool **)malloc(sizeof(bool *) * (numsSize + 1));
	for (int i = 0; i < numsSize + 1; i++) {
		dp[i] = (bool *)malloc(sizeof(bool) * (target + 1));
		memset(dp[i], 0, sizeof(bool) * (target + 1));
		dp[i][0] = 1;
	}
	// 从dp[1][1]开始遍历数组，如果dp[i-1][j]为true的话，那么dp[i][j]肯定为true，
	// 这说明已经有组合能够达到局部目标值了，再增加数组也不会改变结果，dp[i-1][j-nums[j-1]]
	for (int i = 1; i < numsSize + 1; i++) {
		for (int j = 1; j < target + 1; j++) {
			if (dp[i - 1][j] == 1 || (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]] == 1)) {
				dp[i][j] = 1;
			}
		}
	}
	// 最后最后一行最后一列的值
	return dp[numsSize][target];
}

int main(void) {
	int nums[4] = { 1,5,11,5 };
	int res = canPartition(nums, 4);
	printf("%d",res);
	getchar();
}
