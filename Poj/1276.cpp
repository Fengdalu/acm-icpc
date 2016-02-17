#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cash, n;
int dp[100010];

int run() {
	if(scanf("%d%d", &cash, &n) != 2) return 1;
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		int d, c;
		scanf("%d%d", &c, &d);
		for(int j = 1; c != 0; j *= 2) {
			if(c < j) j = c;
			c -= j;
			for(int k = cash; k >= j * d; k--) 
				dp[k] |= dp[k - j * d];
		}
	}
	while(!dp[cash]) cash--;
	printf("%d\n", cash);
	return 0;
}

int main() {
	while(!run());
	return 0;
}
