#include <stdio.h>
#include <string.h>
#include <stdlib.h>
short dp[5001][5001];
char s[6000];
int n;

short min(short a, short b) {
	return (a < b) ? a : b;
}

short cal(int l, int r) {
	if(r < l) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	dp[l][r] = (short)n;
	if(s[l] == s[r]) dp[l][r] = min(dp[l][r], cal(l + 1, r - 1));
	else {
		dp[l][r] = min(dp[l][r], (short)1 + cal(l + 1, r));
		dp[l][r] = min(dp[l][r], (short)1 + cal(l, r - 1));
	}
	return dp[l][r];
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	memset(dp, -1, sizeof dp);
	int len = strlen(s);
	printf("%d\n", (int)cal(0, len - 1));
}

int main() {
	run();
	return 0;
}
