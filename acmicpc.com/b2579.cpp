#include <stdio.h>
#include <math.h>
#define MAX 300
//백준 2579
int calc(int level, int stair[], int dp[], int maxi) {
	if (level == maxi) {
		return dp[level];
	}
	if (level == 0) {
		dp[0] = stair[0];
	}
	else if (level == 1) {
		dp[1] = stair[0] + stair[1];
	}
	else if (level == 2) {
		if (stair[2] + stair[1] > dp[0] + stair[2]) {
			dp[2] = stair[2] + stair[1];
		}
		else {
			dp[2] = dp[0] + stair[2];
		}
	}
	else {
		if (dp[level - 3] + stair[level] + stair[level - 1] > dp[level - 2] + stair[level]) {
			dp[level] = dp[level - 3] + stair[level] + stair[level - 1];
		}
		else {
			dp[level] = dp[level - 2] + stair[level];
		}
	}
	level++;
	return calc(level, stair, dp, maxi);
}
int main() {
	int i;
	int N;
	int stair[MAX];
	int dp[MAX];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &stair[i]);
	}
	calc(0, stair,dp,N);
	printf("%d", dp[N-1]);
	return 0;
}
