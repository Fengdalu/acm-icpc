#include <bits/stdc++.h>

#define cmax(x, y) x = std::max(x, y)
const int N = 200;
int dp[2][3];

int main() {
	int n; scanf("%d", &n);
	int cur = 0, next = 1;
	for(int j = 0; j < 3; j++) dp[cur][j] = -1;
	dp[cur][0] = 0;
	for(int i = 0; i < n; i++) {
		int mk; scanf("%d", &mk);
		for(int j = 0; j < 3; j++) dp[next][j] = -1;
		for(int j = 0; j < 3; j++) if(~dp[cur][j]) {
			cmax(dp[next][0], dp[cur][j]);
			for(int k = 1; k <= 2; k++) if(k != j) if(mk >> (k - 1) & 1) {
				cmax(dp[next][k], dp[cur][j] + 1);
			}
		}
		std::swap(cur, next);
	}
	printf("%d\n", std::max(0, n - *std::max_element(dp[cur], dp[cur] + 3)));
	return 0;
}

